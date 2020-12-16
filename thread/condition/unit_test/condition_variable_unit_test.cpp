#include "condition_variable.h"
#include <iostream>

using namespace pthread;
using namespace std;

//TODO: unit test

int main(){
    auto p = new ConditionVariable();
    delete p;
    return 0;
}