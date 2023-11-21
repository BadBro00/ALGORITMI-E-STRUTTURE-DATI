/*
    Riscrivere il Merge Sort utilizzando il contenitore Vector ed un iteratore
*/
#include <vector>
#include "MergeSortVector.h"
#include <iostream>
#include <string>

int main(){

    std::vector<int> vec = {120,34,21,1,23,12};
    
    MergeSortVector<int>::mergeSortVec(vec.begin(),vec.end());

    std::vector<int>::iterator it;

    for (it = vec.begin(); it != vec.end(); it++)
        std::cout << endl << "Vec Ordinato: " << *it << " ";

    std::vector<string> vecS;
    vecS.push_back("ciao");
    vecS.push_back("prova");
    vecS.push_back("alto");
    vecS.push_back("basso");
    
    MergeSortVector<string>::mergeSortVec(vecS.begin(),vecS.end());

    std::vector<string>::iterator itt;

    for (itt = vecS.begin(); itt != vecS.end(); itt++)
        std::cout << endl << "Vec Ordinato: " << *itt << " ";
        
    return 0;
}