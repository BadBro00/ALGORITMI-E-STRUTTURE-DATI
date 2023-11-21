/*
    STACK generico
*/
#include "Stack.h"
#include <iostream>

int main(){
    int N;
    float F;

    Stack<int> Sti;
    Stack<float> Stf;

    Sti.Push(25);
    Stf.Push(3.141592);

    if ( Sti.Pop(N) ) std::cout << N << std::endl;
    if ( Stf.Pop(F) ) std::cout << F << std::endl;

    return 0;
}