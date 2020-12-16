#include "posix_semaphore.h"

namespace ipc{

//see  man 7 sem_overview  on linux
static const uint_t MaxLengthOfSemaphoreName = 250u;
static const uint_t MinLengthOfSemaphoreName = 2u;
static const char PrefixOfSemaphoreName = '/';

Semaphore::Semaphore(int psharead, uint_t init_value):is_named(false){
    int ret = sem_init(sem_addr,psharead,init_value);
    assert(ret > 0);
    is_process_shared = (0 != psharead);
}

Semaphore::Semaphore(const std::string &name, int flag)
    :name(name),is_named(true),is_process_shared(true){
    int name_size = name.size();
    if(name_size > MaxLengthOfSemaphoreName || 
    name_size < MinLengthOfSemaphoreName ||
       name[0] != PrefixOfSemaphoreName){
        //LOG();
        return;
    }
    sem_addr = sem_open(name.c_str(),flag);
    assert(sem_addr != SEM_FAILED);
}

Semaphore::Semaphore(const std::string &name, int flag, mode_t mode,uint_t init_value)
    :name(name),is_named(true),is_process_shared(true){
    int name_size = name.size();
    if(name_size > MaxLengthOfSemaphoreName || 
    name_size < MinLengthOfSemaphoreName ||
       name[0] != PrefixOfSemaphoreName){
        //LOG();
        return;
    }
    sem_addr = sem_open(name.c_str(),flag,mode,init_value);
    assert(sem_addr != SEM_FAILED);
}

Semaphore::~Semaphore(){
    if(is_named){
        sem_close(sem_addr);
        //The semaphore is destroyed once all other processes that have the semaphore open close it.
        sem_unlink(name.c_str());
    }else{
        sem_destroy(sem_addr);
    }
}

bool Semaphore::Wait(){
    return 0 == sem_wait(sem_addr);
}

bool Semaphore::Post(){
    return 0 == sem_post(sem_addr);
}

bool Semaphore::TryWait(){
    return 0 == sem_trywait(sem_addr);
}

bool Semaphore::TimedWait(const struct timespec *abs_timeout){
    return 0 == sem_timedwait(sem_addr, abs_timeout);
}

int Semaphore::GetValue(){
    int value = -1;
    if(-1 == sem_getvalue(sem_addr,&value)){
        return -1;
    }
    return value;
}

}// namespace ipc
