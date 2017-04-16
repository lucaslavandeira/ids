#ifndef IDS_LOCK_H
#define IDS_LOCK_H

#include <mutex>

// Generic Lock class for easier locking and unlocking of mutexes
class Lock {
    std::mutex& m;

public:
    explicit Lock(std::mutex &m);
    ~Lock();
};


#endif //IDS_LOCK_H
