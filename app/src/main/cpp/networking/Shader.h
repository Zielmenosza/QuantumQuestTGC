#ifndef SHADER_H
#define SHADER_H

#include <GLES3/gl3.h>
#include <string>
#include "Model.h"

class Shader {
public:
    // Loads a shader program from vertex and fragment shader sources
    static Shader* loadShader(
            const std::string& vertexSource,
            const std::string& fragmentSource,
            const std::string& positionAttributeName,
            const std::string& uvAttributeName,
            const std::string& projectionMatrixUniformName
    );

    // Destructor to clean up resources
    ~Shader();

    // Activate the shader program for use
    void activate() const;

    // Deactivate the shader program
    void deactivate() const;

    // Draw the given model using this shader program
    void drawModel(const Model& model) const;

    // Set the projection matrix uniform in the shader
    void setProjectionMatrix(const float* projectionMatrix) const;

private:
    // Constructor is private to force the use of loadShader method
    Shader(GLuint program, GLint position, GLint uv, GLint projectionMatrix)
            : program_(program), position_(position), uv_(uv), projectionMatrix_(projectionMatrix) {}

    // Compiles a shader of the given type from the given source
    static GLuint loadShader(GLenum shaderType, const std::string& shaderSource);

    GLuint program_;          // OpenGL shader program ID
    GLint position_;          // Attribute location for vertex positions
    GLint uv_;                // Attribute location for vertex UVs
    GLint projectionMatrix_;  // Uniform location for the projection matrix
};

#endif // SHADER_H