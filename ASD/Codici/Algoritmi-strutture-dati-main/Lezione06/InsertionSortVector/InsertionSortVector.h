#ifndef INSERTIONSORTVECTOR_H
#define INSERTIONSORTVECTOR_H

#include <vector>

using namespace std;

class InsertionSortVector {
    public:
        template <typename T> static void insertionSort(typename vector<T>::iterator begin, typename vector<T>::iterator end);
};

template <typename T>
void InsertionSortVector::insertionSort(typename vector<T>::iterator begin, typename vector<T>::iterator end){
    typename vector<T>::iterator i;
    typename vector<T>::iterator j;
    T key;

    for ( j = begin+1; j != end; j++ ){
        key = *j;
        i = j-1;

        while ( i >= begin && *i > key ){
            *(i+1) = *i;
            i--;
        }
        *(i+1) = key;
    }
}

#endif // INSERTIONSORTVECTOR_H