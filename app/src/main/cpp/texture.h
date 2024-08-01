#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GLES3/gl3.h> // Include OpenGL ES 3 header for GLuint

class Texture {
public:
    // Constructor to load texture from a file path
    Texture(const std::string& filePath);

    // Destructor to free texture resources
    ~Texture();

    // Getter to retrieve the OpenGL texture ID
    GLuint getTextureID() const;

private:
    GLuint textureID; // OpenGL texture ID
    std::string filePath; // File path to the texture image

    // Helper method to load texture from a file
    void loadTexture(const std::string& filePath);
};

#endif // TEXTURE_H