#include "condition_variable.h"

namespace pthread{
namespace condition{

ConditionVariable::ConditionVariable(){
    int ret = pthread_cond_init(&cond,nullptr);
    assert(ret == 0);
}

ConditionVariable::~ConditionVariable(){
    int ret = pthread_cond_destroy(&cond);
    assert(ret == 0);
}

void ConditionVariable::Wait(){
    pthread_cond_wait(&cond,locker.GetMutexPtr());
}

bool ConditionVariable::WaitForSencond(int seconds){
    struct timespec timeout;
    clock_getres(CLOCK_REALTIME,&timeout);
    timeout.tv_sec += seconds;
    return pthread_cond_timedwait(&cond,locker.GetMutexPtr(),&timeout);
}

void ConditionVariable::Notify(){
    pthread_cond_signal(&cond);
}

void ConditionVariable::NotifyAll(){
    pthread_cond_broadcast(&cond);
}

} //namespace condition
} //namespace pthread

