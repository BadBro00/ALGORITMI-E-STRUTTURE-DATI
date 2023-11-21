/*
    Esercizio

    • Riscrivere il quicksort utilizzando il contenitore Vector
    ed gli iteratori
*/

#include <vector>
#include "QuickSortVector.h"
#include <iostream>

using namespace std;

int main(){

    vector<int> vec = {9,7,3,1};

    QuickSortVector<int>::quickSort(vec.begin(),vec.end()-1);

    std::vector<int>::iterator it;

    for (it = vec.begin(); it != vec.end(); it++)
        cout << endl << "Vec Ordinato: " << *it << " ";
    return 0;
}