#include "Model.h"

Model::Model()
        : vao_(0), vbo_(0), ebo_(0), indexCount_(0) {
    // Generate and bind VAO, VBO, and EBO
    glGenVertexArrays(1, &vao_);
    glGenBuffers(1, &vbo_);
    glGenBuffers(1, &ebo_);
}

Model::~Model() {
    // Delete buffers and array
    glDeleteBuffers(1, &ebo_);
    glDeleteBuffers(1, &vbo_);
    glDeleteVertexArrays(1, &vao_);
}

void Model::loadModelData(const float* vertices, const unsigned int* indices, size_t vertexCount, size_t indexCount) {
    indexCount_ = static_cast<GLsizei>(indexCount);

    // Bind the Vertex Array Object
    glBindVertexArray(vao_);

    // Bind and fill the Vertex Buffer Object with vertex data
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), vertices, GL_STATIC_DRAW);

    // Bind and fill the Element Buffer Object with index data
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    // Define the vertex attribute layout (assuming the vertices contain position data only)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind the Vertex Array Object to avoid accidental modifications
    glBindVertexArray(0);
}

GLuint Model::getVao() const {
    return vao_;
}

GLsizei Model::getIndexCount() const {
    return indexCount_;
}