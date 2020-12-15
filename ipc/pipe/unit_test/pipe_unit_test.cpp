#include "pipe.h"
#include <iostream>

using namespace ipc::unnamedpipe;
using namespace std;

//TODO unit test

int main(){
    auto p = new Pipe();
    p->Open();
    p->Close();
    delete p;
    return 0;
}