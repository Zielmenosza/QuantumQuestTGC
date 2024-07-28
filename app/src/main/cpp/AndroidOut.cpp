#include "AndroidOut.h"
#include <android/log.h>
#include <sstream>

enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

/*!
 * Use this to log strings out to logcat. Note that you should use std::endl to commit the line
 *
 * ex:
 *  out << "Hello World" << std::endl;
 */
extern std::ostream aout;

/*!
 * Use this class to create an output stream that writes to logcat. By default, a global one is
 * defined as @a aout
 */
class AndroidOut : public std::stringbuf {
public:
    /*!
     * Creates a new output stream for logcat
     * @param kLogTag the log tag to output
     * @param level the log level
     */
    inline AndroidOut(const char* kLogTag, LogLevel level = DEBUG) : logTag_(kLogTag), level_(level) {}

protected:
    virtual int sync() override {
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
        str("");
        return 0;
    }

private:
    const char* logTag_;
    LogLevel level_;
};

#endif //ANDROIDGLINVESTIGATIONS_ANDROIDOUT_H