/*
    Esercizio

    Random Quick Sort Vector
*/

#include <vector>
#include "RandomQuickSortVector.h"
#include <iostream>

using namespace std;

int main(){

    vector<int> vec = {9,7,3,1};

    RandomQuickSortVector::randomQuickSort<int>(vec.begin(),vec.end()-1);

    vector<int>::iterator it;

    for (it = vec.begin(); it != vec.end(); it++)
        cout << endl << "Vec Ordinato: " << *it << " ";

    return 0;
}