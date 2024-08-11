// texture.h
#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <GLES3/gl3.h> // Include OpenGL ES 3 header for GLuint
#include <android/asset_manager.h>

class Texture {
public:
    Texture(AAssetManager* assetManager, const std::string& filePath);
    ~Texture();

    // Getter to retrieve the OpenGL texture ID
    GLuint getTextureID() const;

private:
    GLuint textureID; // OpenGL texture ID
    std::string filePath; // File path to the texture image

    // Helper method to load texture from a file
    void loadTexture(AAssetManager* assetManager, const std::string& filePath);// Add AAssetManager*
};

#endif // TEXTURE_H