#include "posix_semaphore.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace ipc;

//TODO unit test

int main(){
    auto p1 = new Semaphore(0,1u);
    auto p2 = new Semaphore("/test1",O_CREAT);
    auto p3 = new Semaphore("/test2", O_CREAT, 0, 0u);

    delete p1;
    delete p2;
    delete p3;
    return 0;
}