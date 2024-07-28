#ifndef RENDERER_H
#define RENDERER_H

#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <android/native_app_glue.h>
#include <memory>
#include <vector>
#include "Model.h"
#include "Shader.h"
#include "inputHandler.h" // Assuming an InputHandler class

struct android_app;

class Renderer {
public:
    explicit Renderer(android_app* pApp, InputHandler& inputHandler);
    ~Renderer();

    void render();
    void handleInput();

private:
    void initRenderer();
    void updateRenderArea();
    void createModels();

    android_app* app_;
    EGLDisplay display_;
    EGLSurface surface_;
    EGLContext context_;
    EGLint width_, height_;

    bool shaderNeedsNewProjectionMatrix_;

    std::unique_ptr<Shader> shader_;
    std::vector<Model> models_;
    InputHandler& inputHandler_;
};

#endif // RENDERER_H