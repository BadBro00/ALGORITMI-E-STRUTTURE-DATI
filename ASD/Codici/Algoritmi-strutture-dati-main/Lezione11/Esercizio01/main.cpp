/*
    Esercizio

    • Implementare counting sort decrescente
*/

#include "../CountingSort/CountingSort.h"
#include <vector>
#include <iostream>

using namespace std;

int main(){

    int numvar = 8;
    vector<int> vecInvercse = {100,20,40,22,12,120,220,240};

    CountingSort::countingSortInverse(&vecInvercse,numvar);

    for (auto i:vecInvercse)
        cout << i << " ";

    return 0;
}