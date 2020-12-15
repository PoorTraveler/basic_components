#include "mutex_lock.h"
#include "mutex_lock_guard.h"
#include <iostream>

using namespace pthread::mutexlock;
using namespace pthread::mutexlockguard;
using namespace std;

int main(){
    auto mp = new MutexLock();
    mp->Lock();
    mp->Unlock();
    delete mp;

    auto mmp = new MutexLockGuard();
    delete mmp;

    return 0;
}