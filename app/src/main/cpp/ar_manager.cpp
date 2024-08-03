#include "ar_manager.h"
#include "ar_session.h"  // Include the full definition of ARSession
#include "ar_object.h"   // Include the full definition of ARObject

ARManager::ARManager() {
    arSession_ = new ARSession();
}

ARManager::~ARManager() {
    delete arSession_;
}

void ARManager::createARObject() {
    ARObject* newObj = new ARObject();
    // Use newObj as needed
    delete newObj; // Properly delete the object when done
}

void ARManager::removeARObject(ARObject* obj) {
    delete obj; // Ensure ARObject is fully defined before deleting
}