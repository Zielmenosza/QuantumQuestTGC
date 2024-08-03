#ifndef ARMANAGER_H
#define ARMANAGER_H

// Forward declarations are fine for pointers, but full definitions are needed for allocation/deallocation
class ARSession;
class ARObject;

class ARManager {
public:
    ARManager();
    ~ARManager();

    void createARObject();
    void removeARObject(ARObject* obj);

private:
    ARSession* arSession_;
};

#endif // ARMANAGER_H