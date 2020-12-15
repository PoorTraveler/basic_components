#include "mutex_lock.h"

namespace pthread{
namespace mutexlock{

MutexLock::MutexLock(const pthread_mutexattr_t *mutex_attr){
    int ret = pthread_mutex_init(&mutex_,mutex_attr);
    assert(ret == 0);
    //mutex_ = PTHREAD_MUTEX_INITIALIZER;
}

MutexLock::~MutexLock(){
    int ret = pthread_mutex_destroy(&mutex_);
    assert(ret == 0);
}

//blocking
void MutexLock::Lock(){
    pthread_mutex_lock(&mutex_);
}

//nonblocking
bool MutexLock::TryLock(){
    return 0 == pthread_mutex_trylock(&mutex_);
}

bool MutexLock::TimedLock(const struct timespec*tm){
    return 0 == pthread_mutex_timedlock(&mutex_,tm);
}

void MutexLock::Unlock(){
    pthread_mutex_unlock(&mutex_);
}

} //namespace mutex
} //namespace pthread