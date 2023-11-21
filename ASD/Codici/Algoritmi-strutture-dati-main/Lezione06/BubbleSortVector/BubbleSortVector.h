#ifndef BUBBLESORTVECTOR_H
#define BUBBLESORTVECTOR_H

#include <vector>

using namespace std;

class BubbleSortVector{
    private:
        template <typename T> static void compswap (T&,T&);
        template <typename T> static void swap(T&,T&);
    public:
        template <typename T> static void bubbleSort(typename vector<T>::iterator,typename vector<T>::iterator);
};

template <typename T>
void BubbleSortVector::bubbleSort(typename vector<T>::iterator begin, typename vector<T>::iterator end){
    typename vector<T>::iterator i;
    typename vector<T>::iterator j;

    for (i = begin; i != end; i++)
        for (j = end; j != i; j--)
            compswap(*(j-1),*j);
}

template <typename T>
void BubbleSortVector::compswap(T& A, T& B){
    if (B < A) swap(A, B);
}

template <typename T>
void BubbleSortVector::swap(T& A, T& B){
    T t=A; A=B; B=t;
}

#endif // BUBBLESORTVECTOR_H