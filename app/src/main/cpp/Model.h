#ifndef MODEL_H
#define MODEL_H

#include <GLES3/gl3.h>

class Model {
public:
    Model();
    ~Model();

    // Load model data from vertices and indices
    void loadModelData(const float* vertices, const unsigned int* indices, size_t vertexCount, size_t indexCount);

    // Getter for Vertex Array Object
    GLuint getVao() const;

    // Getter for the number of indices
    GLsizei getIndexCount() const;

private:
    GLuint vao_;  // Vertex Array Object
    GLuint vbo_;  // Vertex Buffer Object
    GLuint ebo_;  // Element Buffer Object
    GLsizei indexCount_; // Count of indices
};

#endif // MODEL_H