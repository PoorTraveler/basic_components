#include "mutex_lock_guard.h"

namespace pthread{

MutexLockGuard::MutexLockGuard(){
    locker.Lock();
}

MutexLockGuard::~MutexLockGuard(){
    locker.Unlock();
}

} // namespace pthread
