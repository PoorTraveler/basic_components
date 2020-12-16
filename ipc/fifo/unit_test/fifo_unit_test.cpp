#include "fifo.h"
#include <iostream>


using namespace std;
using namespace ipc;

//TODO:unit test

int main(){
    auto p = new Fifo("./fifo",0666);
    p->Create();
    p->Open(O_RDWR);
    delete p;
    return 0;
}