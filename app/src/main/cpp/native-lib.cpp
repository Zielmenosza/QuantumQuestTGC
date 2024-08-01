#include <jni.h>
#include <string>

// This function is exposed to Java as a native method.
// It returns a simple string "Hello from C++".
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_quantumquest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}