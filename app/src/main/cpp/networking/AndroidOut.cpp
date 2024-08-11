#include "AndroidOut.h"

// Initialize the global Android output stream with a default log tag
std::ostream aout(new AndroidOut("AndroidOut"));

// Constructor implementation
AndroidOut::AndroidOut(const char* kLogTag, LogLevel level)
        : logTag_(kLogTag), level_(level) {}

// Override the sync method to send the buffer content to Android log
int AndroidOut::sync() {
    int androidLogLevel = ANDROID_LOG_DEBUG;
    switch (level_) {
        case INFO:
            androidLogLevel = ANDROID_LOG_INFO;
            break;
        case WARNING:
            androidLogLevel = ANDROID_LOG_WARN;
            break;
        case ERROR:
            androidLogLevel = ANDROID_LOG_ERROR;
            break;
        default:
            break;
    }
    __android_log_print(androidLogLevel, logTag_, "%s", str().c_str());
    str(""); // Clear the buffer after logging
    return 0;
}