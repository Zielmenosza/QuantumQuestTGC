#include "Renderer.h"
#include <GLES3/gl3.h>
#include <memory>
#include <vector>
#include <android/imagedecoder.h>
#include "AndroidOut.h"
#include "Shader.h"
#include "Utility.h"
#include "TextureAsset.h"
#include "iostream"
#include <fstream> // For file operations
#include <sstream> // For string streams

//! executes glGetString and outputs the result to logcat
#define PRINT_GL_STRING(s) {aout << #s": "<< glGetString(s) << std::endl;}

/*!
 * @brief if glGetString returns a space-separated list of elements, prints each one on a new line
 *
 * This works by creating an istringstream of the input C-style string. Then that is used to create
 * a vector -- each element of the vector is a new element in the input string. Finally, a foreach
 * loop consumes this and outputs it to logcat using @a aout
 */
#define PRINT_GL_STRING_AS_LIST(s) { \
std::istringstream extensionStream((const char *) glGetString(s));\
std::vector<std::string> extensionList(\
        std::istream_iterator<std::string>{extensionStream},\
        std::istream_iterator<std::string>());\
aout << #s":\n";\
for (auto& extension: extensionList) {\
    aout << extension << "\n";\
}\
aout << std::endl;\
}

//! Color for cornflower blue. Can be sent directly to glClearColor
#define CORNFLOWER_BLUE 100 / 255.f, 149 / 255.f, 237 / 255.f, 1

// Vertex shader, you'd typically load this from assets
static const char *vertex = R"vertex(#version 300 es
in vec3 inPosition;
in vec2 inUV;

out vec2 fragUV;

uniform mat4 uProjection;

void main() {
    fragUV = inUV;
    gl_Position = uProjection * vec4(inPosition, 1.0);
}
)vertex";

// Fragment shader, you'd typically load this from assets
static const char *fragment = R"fragment(#version 300 es
precision mediump float;

in vec2 fragUV;

uniform sampler2D uTexture;

out vec4 outColor;

void main() {
    outColor = texture(uTexture, fragUV);
}
)fragment";

/*!
 * Half the height of the projection matrix. This gives you a renderable area of height 4 ranging
 * from -2 to 2
 */
static constexpr float kProjectionHalfHeight = 2.f;

/*!
 * The near plane distance for the projection matrix. Since this is an orthographic projection
 * matrix, it's convenient to have negative values for sorting (and avoiding z-fighting at 0).
 */
static constexpr float kProjectionNearPlane = -1.f;

/*!
 * The far plane distance for the projection matrix. Since this is an orthographic projection
 * matrix, it's convenient to have the far plane equidistant from 0 as the near plane.
 */
static constexpr float kProjectionFarPlane = 1.f;

Renderer::Renderer(android_app* app, InputHandler& inputHandler)
        : app_(app), inputHandler_(inputHandler), display_(EGL_NO_DISPLAY), surface_(EGL_NO_SURFACE),
          context_(EGL_NO_CONTEXT), width_(0), height_(0), shaderNeedsNewProjectionMatrix_(true) {}

Renderer::~Renderer() {
    if (display_ != EGL_NO_DISPLAY) {
        eglMakeCurrent(display_, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        if (context_ != EGL_NO_CONTEXT) {
            eglDestroyContext(display_, context_);
            context_ = EGL_NO_CONTEXT;
        }
        if (surface_ != EGL_NO_SURFACE) {
            eglDestroySurface(display_, surface_);
            surface_ = EGL_NO_SURFACE;
        }
        eglTerminate(display_);
        display_ = EGL_NO_DISPLAY;
    }
}

void Renderer::initRenderer() {
    // Initialize EGL and OpenGL ES settings here
    const EGLint configAttribs[] = {
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_BLUE_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_RED_SIZE, 8,
            EGL_DEPTH_SIZE, 24,
            EGL_NONE
    };

    EGLint numConfigs;
    EGLConfig config;
    display_ = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    eglInitialize(display_, nullptr, nullptr);
    eglChooseConfig(display_, configAttribs, &config, 1, &numConfigs);

    EGLint contextAttribs[] = {EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE};
    context_ = eglCreateContext(display_, config, EGL_NO_CONTEXT, contextAttribs);

    surface_ = eglCreateWindowSurface(display_, config, app_->window, nullptr);
    eglMakeCurrent(display_, surface_, surface_, context_);

    // Check and log OpenGL version and extensions
    PRINT_GL_STRING(GL_VENDOR);
    PRINT_GL_STRING(GL_RENDERER);
    PRINT_GL_STRING(GL_VERSION);
    PRINT_GL_STRING_AS_LIST(GL_EXTENSIONS);

    // Initialize the shader
    shader_ = std::unique_ptr<Shader>(Shader::loadShader(vertex, fragment, "inPosition", "inUV", "uProjection"));

    // Create models here
    createModels();
}

void Renderer::updateRenderArea() {
    EGLint newWidth, newHeight;
    eglQuerySurface(display_, surface_, EGL_WIDTH, &newWidth);
    eglQuerySurface(display_, surface_, EGL_HEIGHT, &newHeight);

    if (width_ != newWidth || height_ != newHeight) {
        width_ = newWidth;
        height_ = newHeight;
        glViewport(0, 0, width_, height_);
        shaderNeedsNewProjectionMatrix_ = true;
    }
}

void Renderer::render() {
    // Check to see if the surface has changed size. This is _necessary_ to do every frame when
    // using immersive mode as you'll get no other notification that your renderable area has
    // changed.
    updateRenderArea();

    // When the renderable area changes, the projection matrix has to also be updated. This is true
    // even if you change from the sample orthographic projection matrix as your aspect ratio has
    // likely changed.
    if (shaderNeedsNewProjectionMatrix_) {
        // a placeholder projection matrix allocated on the stack. Column-major memory layout
        float projectionMatrix[16] = {0};

        // build an orthographic projection matrix for 2d rendering
        Utility::buildOrthographicMatrix(
                projectionMatrix,
                kProjectionHalfHeight,
                float(width_) / height_,
                kProjectionNearPlane,
                kProjectionFarPlane);

        // Corrected method call
        shader_->setProjectionMatrix(projectionMatrix);

        shaderNeedsNewProjectionMatrix_ = false;

        // Logging projection matrix values
        std::ofstream aout("log.txt", std::ios_base::app);
        if (aout.is_open()) {
            aout << "Projection matrix updated\n";
            aout << "Projection matrix: " << projectionMatrix[0] << " " << projectionMatrix[1]
                 << " "
                 << projectionMatrix[2] << " " << projectionMatrix[3] << "\n";
            aout << "Projection matrix: " << projectionMatrix[4] << " " << projectionMatrix[5]
                 << " "
                 << projectionMatrix[6] << " " << projectionMatrix[7] << "\n";
            aout << "Projection matrix: " << projectionMatrix[8] << " " << projectionMatrix[9]
                 << " "
                 << projectionMatrix[10] << " " << projectionMatrix[11] << "\n";
            aout << "Projection matrix: " << projectionMatrix[12] << " " << projectionMatrix[13]
                 << " "
                 << projectionMatrix[14] << " " << projectionMatrix[15] << "\n";
            aout.close();
        } else
            std::cerr << "Failed to open log file for writing." << std::endl;

    }

    // Rendering code
    glClearColor(CORNFLOWER_BLUE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Example rendering call (ensure `model_` is properly defined and initialized)
    shader_->activate();
    for (auto& model : models_) {
        shader_->drawModel(model);
    }
    shader_->deactivate();

    eglSwapBuffers(display_, surface_);
}

void Renderer::handleInput(const AInputEvent* event) { // Add event argument
    // Handle user input and update game state
    inputHandler_.processInput(event); // Pass event to processInput
}

void Renderer::createModels() {
    // Example: Load a model and initialize it here
    Model model;
    // Initialize model with vertex data, textures, etc.
    models_.push_back(model);
}