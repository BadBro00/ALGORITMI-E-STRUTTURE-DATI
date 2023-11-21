/*
    Insertion Sort Vector
*/

#include <iostream>
#include "InsertionSortVector.h"
#include <vector>

int main(){

    std::vector<int> vec = {9,7,3,1};

    InsertionSortVector::insertionSort<int>(vec.begin(),vec.end());

    for (auto i: vec)
        std::cout << i << " ";


    return 0;
}