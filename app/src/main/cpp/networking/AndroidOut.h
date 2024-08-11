#ifndef ANDROIDGLINVESTIGATIONS_ANDROIDOUT_H
#define ANDROIDGLINVESTIGATIONS_ANDROIDOUT_H

#include <android/log.h>
#include <sstream>
#include <string> // Include necessary headers

// Log levels to categorize messages
enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

// External declaration of the Android output stream
extern std::ostream aout;

/*!
 * AndroidOut class creates an output stream that writes to logcat.
 * By default, a global instance is defined as @a aout.
 */
class AndroidOut : public std::stringbuf {
public:
    /*!
     * Creates a new output stream for logcat
     * @param kLogTag the log tag to output
     * @param level the log level
     */
    inline explicit AndroidOut(const char* kLogTag, LogLevel level = DEBUG);

protected:
    int sync() override; // Override sync method to flush the buffer

private:
    const char* logTag_;
    LogLevel level_;
};

#endif //ANDROIDGLINVESTIGATIONS_ANDROIDOUT_H