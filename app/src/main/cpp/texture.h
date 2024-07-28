#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

class Texture {
public:
    Texture(const std::string& filePath);
    ~Texture();

    GLuint getTextureID() const;

private:
    GLuint textureID;
};

#endif // TEXTURE_H