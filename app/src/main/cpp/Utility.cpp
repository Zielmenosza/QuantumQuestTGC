#include "Utility.h"
#include "AndroidOut.h"
#include <GLES3/gl3.h>

#define CHECK_ERROR(e) case e: aout << "GL Error: "#e << std::endl; break;

bool Utility::checkAndLogGlError(bool alwaysLog) {
    GLenum error = glGetError();
    if (error == GL_NO_ERROR) {
        if (alwaysLog) {
            aout << "No GL error" << std::endl;
        }
        return true;
    } else {
        switch (error) {
            CHECK_ERROR(GL_INVALID_ENUM)
            CHECK_ERROR(GL_INVALID_VALUE)
            CHECK_ERROR(GL_INVALID_OPERATION)
            CHECK_ERROR(GL_INVALID_FRAMEBUFFER_OPERATION)
            CHECK_ERROR(GL_OUT_OF_MEMORY)
            default:
                aout << "Unknown GL error: " << error << std::endl;
        }
        return false;
    }
}

float *Utility::buildOrthographicMatrix(float *outMatrix, float halfHeight, float aspect, float near, float far) {
    float halfWidth = halfHeight * aspect;
    // Zero the matrix here (initialize all elements to 0)
    std::fill_n(outMatrix, 16, 0.0f); // Ensure matrix is initially zeroed

    // Now fill the matrix as an orthographic projection
    outMatrix[0] = 1.f / halfWidth;
    outMatrix[5] = 1.f / halfHeight;
    outMatrix[10] = -2.f / (far - near);
    outMatrix[11] = -(far + near) / (far - near);
    outMatrix[15] = 1.f;
    return outMatrix;
}

float *Utility::buildIdentityMatrix(float *outMatrix) {
    std::fill_n(outMatrix, 16, 0.0f); // Zero the matrix
    outMatrix[0] = 1.f;
    outMatrix[5] = 1.f;
    outMatrix[10] = 1.f;
    outMatrix[15] = 1.f;
    return outMatrix;
}