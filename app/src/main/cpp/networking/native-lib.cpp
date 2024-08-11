#include <jni.h>
#include <string>

// This function is exposed to Java as a native method.
// It returns a simple string "Hello from C++".
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_quantumquest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    // Create a C++ string
    std::string hello = "Hello from C++";

    // Convert the C++ string to a JNI string (jstring) and return it
    return env->NewStringUTF(hello.c_str());
}