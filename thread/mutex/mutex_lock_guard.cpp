#include "mutex_lock_guard.h"

namespace pthread{
namespace mutexlockguard{

MutexLockGuard::MutexLockGuard(){
    locker.Lock();
}

MutexLockGuard::~MutexLockGuard(){
    locker.Unlock();
}

} // namespace mutexlockguard
} // namespace pthread
