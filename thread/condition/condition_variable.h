#ifndef PTHREAD_CONDITION_HEADER_FILE
#define PTHREAD_CONDITION_HEADER_FILE

#include "mutex_lock.h"
#include "noncopyable.h"

#include <time.h>
#include <assert.h>

namespace pthread{

class ConditionVariable : public common::Noncopyable{
public:
    ConditionVariable();
    ~ConditionVariable();
    void Wait();
    bool WaitForSencond(int seconds);
    void Notify();
    void NotifyAll();
private:
    pthread::MutexLock locker;
    pthread_cond_t cond{};
};

} //namespace pthread
#endif
