// Renderer.h
#ifndef RENDERER_H
#define RENDERER_H

#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <C:\Users\Ziel\AppData\Local\Android\Sdk\ndk\26.1.10909125\sources\android\native_app_glue\android_native_app_glue.h>
#include <memory>
#include <vector>
#include "Model.h"
#include "Shader.h"
#include "input_handler.h"

class Renderer {
public:
    explicit Renderer(android_app* app, InputHandler& inputHandler);
    ~Renderer();

    void render();
    void handleInput();
    void initRenderer();

private:
    void updateRenderArea();
    void createModels();

    android_app* app_;
    InputHandler& inputHandler_;
    EGLDisplay display_;
    EGLSurface surface_;
    EGLContext context_;
    EGLint width_, height_;
    bool shaderNeedsNewProjectionMatrix_;
    std::unique_ptr<Shader> shader_;
    std::vector<Model> models_;
};

#endif // RENDERER_H