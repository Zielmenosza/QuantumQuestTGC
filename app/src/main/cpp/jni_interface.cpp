#include <jni.h>
#include <string>
#include <vector>
#include "card.h"

extern "C" JNIEXPORT jobjectArray JNICALL
Java_com_example_quantumquest_MainActivity_getCardNames(JNIEnv* env, jobject /* this */, jlongArray cardHandles) {
    // Get the size of the cardHandles array
    jsize len = env->GetArrayLength(cardHandles);

    // Create a new array of jstrings to hold the card names
    jclass stringClass = env->FindClass("java/lang/String");
    jobjectArray cardNames = env->NewObjectArray(len, stringClass, nullptr);

    if (cardNames == nullptr) {
        // Handle memory allocation failure
        return nullptr;
    }

    // Get the elements of the cardHandles array
    jlong* handles = env->GetLongArrayElements(cardHandles, nullptr);

    if (handles == nullptr) {
        // Handle memory access failure
        return nullptr;
    }

    // Iterate through each handle, retrieve the card name, and add it to the array
    for (jsize i = 0; i < len; i++) {
        Card* card = reinterpret_cast<Card*>(handles[i]);
        jstring name = env->NewStringUTF(card->getName().c_str());
        if (name == nullptr) {
            // Handle string creation failure
            env->ReleaseLongArrayElements(cardHandles, handles, 0);
            return nullptr;
        }
        env->SetObjectArrayElement(cardNames, i, name);
        env->DeleteLocalRef(name); // Delete local reference to avoid memory leaks
    }

    // Release the elements of the cardHandles array
    env->ReleaseLongArrayElements(cardHandles, handles, 0);

    return cardNames;
}

extern "C" JNIEXPORT jintArray JNICALL
Java_com_example_quantumquest_MainActivity_getCardCosts(JNIEnv* env, jobject /* this */, jlongArray cardHandles) {
    // Get the size of the cardHandles array
    jsize len = env->GetArrayLength(cardHandles);

    // Create a new array of jints to hold the card costs
    jintArray cardCosts = env->NewIntArray(len);
    if (cardCosts == nullptr) {
        // Handle memory allocation failure
        return nullptr;
    }

    // Get the elements of the cardHandles array
    jlong* handles = env->GetLongArrayElements(cardHandles, nullptr);

    if (handles == nullptr) {
        // Handle memory access failure
        return nullptr;
    }

    // Create a temporary array to hold the costs
    std::vector<jint> tempCosts(len);

    // Iterate through each handle, retrieve the card cost, and add it to the array
    for (jsize i = 0; i < len; i++) {
        Card* card = reinterpret_cast<Card*>(handles[i]);
        tempCosts[i] = card->getCost();
    }

    // Set the temporary array to the jintArray
    env->SetIntArrayRegion(cardCosts, 0, len, tempCosts.data());

    // Release the elements of the cardHandles array
    env->ReleaseLongArrayElements(cardHandles, handles, 0);

    return cardCosts;
}