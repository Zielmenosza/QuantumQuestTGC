#ifndef SHADER_H
#define SHADER_H

#include <GLES3/gl3.h>
#include <string>
#include "Model.h"
#include "AndroidOut.h"
#include "Utility.h"

class Shader {
public:
    static Shader* loadShader(
            const std::string& vertexSource,
            const std::string& fragmentSource,
            const std::string& positionAttributeName,
            const std::string& uvAttributeName,
            const std::string& projectionMatrixUniformName);

    void activate() const;
    void deactivate() const;
    void drawModel(const Model& model) const;
    void setProjectionMatrix(float* projectionMatrix) const;

private:
    Shader(GLuint program, GLint position, GLint uv, GLint projectionMatrix)
            : program_(program), position_(position), uv_(uv), projectionMatrix_(projectionMatrix) {}

    static GLuint loadShader(GLenum shaderType, const std::string& shaderSource);

    GLuint program_;
    GLint position_;
    GLint uv_;
    GLint projectionMatrix_;
};

#endif // SHADER_H