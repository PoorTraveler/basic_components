#ifndef PTHREAD_MUTEX_LOCK_GUARD_HEADER_FILE
#define PTHREAD_MUTEX_LOCK_GUARD_HEADER_FILE

#include "mutex_lock.h"
#include "noncopyable.h"

namespace pthread{

class MutexLockGuard:public common::Noncopyable{
public:
    MutexLockGuard();
    ~MutexLockGuard();
private:
    pthread::MutexLock locker;
};

} // namespace pthread
#endif
