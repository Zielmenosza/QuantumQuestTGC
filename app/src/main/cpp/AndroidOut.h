#ifndef ANDROIDGLINVESTIGATIONS_ANDROIDOUT_H
#define ANDROIDGLINVESTIGATIONS_ANDROIDOUT_H

#include <android/log.h>
#include <sstream>
#include <string> // Ensure all necessary headers are included.
#include <android_native_app_glue.h>

extern std::ostream aout;  // Define this in one of your cpp files.

/*!
 * Use this class to create an output stream that writes to logcat. By default, a global one is
 * defined as @a aout
 */
class AndroidOut : public std::stringbuf {
public:
    AndroidOut(const char* logTag = "DefaultTag") : logTag_(logTag) {} // Constructor to initialize logTag_

    int overflow(int c) override {
        sputc(static_cast<char>(c)); // Example implementation
        return c;
    }

protected:
    int sync() override {
        __android_log_print(ANDROID_LOG_DEBUG, logTag_, "%s", str().c_str());
        str("");
        return 0;
    }

private:
    const char* logTag_;
};

#endif // ANDROIDGLINVESTIGATIONS_ANDROIDOUT_H