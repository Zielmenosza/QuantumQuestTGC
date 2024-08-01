#include "Shader.h"

Shader* Shader::loadShader(
        const std::string& vertexSource,
        const std::string& fragmentSource,
        const std::string& positionAttributeName,
        const std::string& uvAttributeName,
        const std::string& projectionMatrixUniformName) {
    // Implementation from your original Shader.h
}

GLuint Shader::loadShader(GLenum shaderType, const std::string& shaderSource) {
    // Implementation from your original Shader.h
}

void Shader::activate() const {
    // Implementation from your original Shader.h
}

void Shader::deactivate() const {
    // Implementation from your original Shader.h
}

void Shader::drawModel(const Model& model) const {
    // Implementation from your original Shader.h
}

void Shader::setProjectionMatrix(float* projectionMatrix) const {
    // Implementation from your original Shader.h
}