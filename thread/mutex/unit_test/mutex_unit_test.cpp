#include "mutex_lock.h"
#include "mutex_lock_guard.h"
#include <iostream>

using namespace pthread;
using namespace std;

//Todo unit test

int main(){
    auto mp = new MutexLock();
    mp->Lock();
    mp->Unlock();
    delete mp;

    auto mmp = new MutexLockGuard();
    delete mmp;

    return 0;
}