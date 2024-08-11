#include "texture.h"
#include <android/imagedecoder.h>
#include <android/asset_manager.h>
#include <stdexcept>
#include "Utility.h"
#include <vector>

// Constructor to load the texture from the given file path
Texture::Texture(AAssetManager* assetManager, const std::string& filePath) {
    loadTexture(assetManager, filePath);
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
void Texture::loadTexture(AAssetManager* assetManager, const std::string& filePath) { // Add AAssetManager*
    // Ensure assetManager is valid
    if (!assetManager) {
        throw std::runtime_error("Invalid asset manager.");
    }

    if (!Utility::checkAndLogGlError()){
        // ...Handle OpenGL error
    }

    // Open the asset using AAssetManager
    AAsset* asset = AAssetManager_open(assetManager, filePath.c_str(), AASSET_MODE_BUFFER);
    if (!asset) {
        throw std::runtime_error("Failed to open texture file: " + filePath);
    }

    // Create an image decoder from the asset
    AImageDecoder* decoder = nullptr;
    AImageDecoder_createFromAAsset(asset, &decoder);
    if (!decoder) {
        AAsset_close(asset);
        throw std::runtime_error("Failed to create image decoder for: " + filePath);
    }

    // Set bitmap format to RGBA 8888
    AImageDecoder_setAndroidBitmapFormat(decoder, ANDROID_BITMAP_FORMAT_RGBA_8888);

    // Retrieve header information
    const AImageDecoderHeaderInfo* headerInfo = AImageDecoder_getHeaderInfo(decoder);
    if (!headerInfo) {
        AImageDecoder_delete(decoder);
        AAsset_close(asset);
        throw std::runtime_error("Failed to get image header info for: " + filePath);
    }

    // Get image dimensions and stride
    int width = AImageDecoderHeaderInfo_getWidth(headerInfo);
    int height = AImageDecoderHeaderInfo_getHeight(headerInfo);
    int stride = AImageDecoder_getMinimumStride(decoder);

    // Decode image data
    std::vector<uint8_t> imageData(height * stride);
    AImageDecoder_decodeImage(decoder, imageData.data(), stride, imageData.size());

    // Generate and bind an OpenGL texture
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload texture data to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData.data());

    // Clean up resources
    AImageDecoder_delete(decoder);
    AAsset_close(asset);

    // Check for OpenGL errors
    if (!Utility::checkAndLogGlError()) {
        throw std::runtime_error("OpenGL error occurred while loading texture: " + filePath);
    }
}