// jni_interface.h

#ifndef QUANTUM_QUEST_JNI_INTERFACE_H
#define QUANTUM_QUEST_JNI_INTERFACE_H

#include <jni.h>
#include "quantum_quest_game.h" // Include any necessary game headers

#ifdef __cplusplus
extern "C" {
#endif

// Declare the native functions that will be called from Java
JNIEXPORT jobjectArray JNICALL Java_com_example_quantumquest_MainActivity_getCardNames(
        JNIEnv* env, jobject obj, jlongArray cardHandles);

JNIEXPORT jintArray JNICALL Java_com_example_quantumquest_MainActivity_getCardCosts(
        JNIEnv* env, jobject obj, jlongArray cardHandles);

#ifdef __cplusplus
}
#endif

#endif // QUANTUM_QUEST_JNI_INTERFACE_H