#include "Shader.h"
#include <iostream>

// Compile a shader from the source code
GLuint Shader::loadShader(GLenum shaderType, const std::string& shaderSource) {
    // Create a new shader object of the specified type
    GLuint shader = glCreateShader(shaderType);

    // Get the C-style string of the shader source code
    const char* shaderSourceCStr = shaderSource.c_str();

    // Attach the source code to the shader and compile it
    glShaderSource(shader, 1, &shaderSourceCStr, nullptr);
    glCompileShader(shader);

    // Check if the shader compiled successfully
    GLint compileStatus;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compileStatus);
    if (compileStatus != GL_TRUE) {
        GLint logLength;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
        char* log = new char[logLength];
        glGetShaderInfoLog(shader, logLength, nullptr, log);
        std::cerr << "Shader compilation failed: " << log << std::endl;
        delete[] log;
        glDeleteShader(shader);
        return 0;
    }

    // Return the shader ID
    return shader;
}

// Load and link a shader program from vertex and fragment shader sources
Shader* Shader::loadShader(
        const std::string& vertexSource,
        const std::string& fragmentSource,
        const std::string& positionAttributeName,
        const std::string& uvAttributeName,
        const std::string& projectionMatrixUniformName
) {
    // Load the vertex shader
    GLuint vertexShader = loadShader(GL_VERTEX_SHADER, vertexSource);
    if (!vertexShader) {
        return nullptr;
    }

    // Load the fragment shader
    GLuint fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentSource);
    if (!fragmentShader) {
        glDeleteShader(vertexShader);
        return nullptr;
    }

    // Create a program and attach the shaders
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    // Link the shader program
    glLinkProgram(program);

    // Check if the program linked successfully
    GLint linkStatus;
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
    if (linkStatus != GL_TRUE) {
        GLint logLength;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
        char* log = new char[logLength];
        glGetProgramInfoLog(program, logLength, nullptr, log);
        std::cerr << "Program linking failed: " << log << std::endl;
        delete[] log;
        glDeleteProgram(program);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return nullptr;
    }

    // Get attribute and uniform locations
    GLint position = glGetAttribLocation(program, positionAttributeName.c_str());
    GLint uv = glGetAttribLocation(program, uvAttributeName.c_str());
    GLint projectionMatrix = glGetUniformLocation(program, projectionMatrixUniformName.c_str());

    // Clean up shaders as they are now linked into the program
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Return a new Shader object
    return new Shader(program, position, uv, projectionMatrix);
}

// Destructor to clean up the shader program
Shader::~Shader() {
    if (program_ != 0) {
        glDeleteProgram(program_);
    }
}

// Activate the shader program for rendering
void Shader::activate() const {
    glUseProgram(program_);
}

// Deactivate the shader program
void Shader::deactivate() const {
    glUseProgram(0);
}

// Draw the given model using this shader
void Shader::drawModel(const Model& model) const {
    glBindVertexArray(model.getVao());
    glDrawElements(GL_TRIANGLES, model.getIndexCount(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

// Set the projection matrix uniform
void Shader::setProjectionMatrix(const float* projectionMatrix) const {
    glUniformMatrix4fv(projectionMatrix_, 1, GL_FALSE, projectionMatrix);
}