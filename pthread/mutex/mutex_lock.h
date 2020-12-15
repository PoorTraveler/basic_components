#ifndef PTHREAD_MUTEX_LOCK_HEADER_FILE
#define PTHREAD_MUTEX_LOCK_HEADER_FILE

#include <pthread.h>
#include <time.h>
#include <assert.h>

#include "noncopyable.h"

namespace pthread{
namespace mutexlock{

class MutexLock : public common::Noncopyable{
public:
    MutexLock(const pthread_mutexattr_t *mutex_attr = nullptr);
    ~MutexLock();
    void Lock();
    void Unlock();
    pthread_mutex_t *GetMutexPtr(){ return &mutex_; }
public:
    bool TryLock();
    bool TimedLock(const struct timespec*tm);
private:
    pthread_mutex_t mutex_;
};

} //namespace mutex
} //namespace pthread

#endif