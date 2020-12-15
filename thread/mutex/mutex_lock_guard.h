#ifndef PTHREAD_MUTEX_LOCK_GUARD_HEADER_FILE
#define PTHREAD_MUTEX_LOCK_GUARD_HEADER_FILE

#include "mutex_lock.h"
#include "noncopyable.h"

namespace pthread{
namespace mutexlockguard{

class MutexLockGuard:public common::Noncopyable{
public:
    MutexLockGuard();
    ~MutexLockGuard();
private:
    pthread::mutexlock::MutexLock locker;
};

} // namespace mutexlockguard
} // namespace pthread
#endif
