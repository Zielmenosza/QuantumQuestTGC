#include "texture.h"
#include <android/imagedecoder.h>
#include <android/asset_manager.h>
#include <stdexcept>
#include <vector>

// Constructor to load the texture from the given file path
Texture::Texture(const std::string& filePath) : textureID(0), filePath(filePath) {
    loadTexture(filePath);
}

// Destructor to delete the OpenGL texture
Texture::~Texture() {
    if (textureID != 0) {
        glDeleteTextures(1, &textureID);
    }
}

// Getter for the texture ID
GLuint Texture::getTextureID() const {
    return textureID;
}

// Private method to load the texture using AImageDecoder
void Texture::loadTexture(const std::string& filePath) {
    // Obtain the AAssetManager from your Android app
    // You will need to pass this into your constructor or initialize it somehow
    AAssetManager* assetManager = ...; // Initialize with actual asset manager

    AAsset* asset = AAssetManager_open(assetManager, filePath.c_str(), AASSET_MODE_BUFFER);
    if (!asset) {
        throw std::runtime_error("Failed to open texture file: " + filePath);
    }

    AImageDecoder* decoder = nullptr;
    AImageDecoder_createFromAAsset(asset, &decoder);
    if (!decoder) {
        AAsset_close(asset);
        throw std::runtime_error("Failed to create image decoder for: " + filePath);
    }

    AImageDecoder_setAndroidBitmapFormat(decoder, ANDROID_BITMAP_FORMAT_RGBA_8888);
    const AImageDecoderHeaderInfo* headerInfo = AImageDecoder_getHeaderInfo(decoder);

    int width = AImageDecoderHeaderInfo_getWidth(headerInfo);
    int height = AImageDecoderHeaderInfo_getHeight(headerInfo);
    int stride = AImageDecoder_getMinimumStride(decoder);

    std::vector<uint8_t> imageData(height * stride);
    AImageDecoder_decodeImage(decoder, imageData.data(), stride, imageData.size());

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData.data());

    AImageDecoder_delete(decoder);
    AAsset_close(asset);
}