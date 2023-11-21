/*
    Implementazione del Bubble Sort con vector
*/
#include <vector>
#include <iostream>
#include "BubbleSortVector.h"

void visualizzaVec(std::vector<int> vec){
    for (int i: vec)
        std::cout << i << " ";
}

int main(){

    std::vector<int> vec = {9,7,3,1};
    BubbleSortVector::bubbleSort<int>(vec.begin(),vec.end()-1);
    visualizzaVec(vec);

    return 0;
}