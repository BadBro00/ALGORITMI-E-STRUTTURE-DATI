#ifndef RANDOMQUIKSORTVECTOR_H
#define RANDOMQUIKSORTVECTOR_H

#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

class RandomQuickSortVector{
    private:
        template <typename T> static typename vector<T>::iterator randomizedPartition(typename vector<T>::iterator,typename vector<T>::iterator); 
        template <typename T> static typename vector<T>::iterator partition(typename vector<T>::iterator,typename vector<T>::iterator);
        template <typename T> static void compswap (T&,T&);
        template <typename T> static void swap(T&,T&);
    public:
        template <typename T> static void randomQuickSort(typename vector<T>::iterator,typename vector<T>::iterator);
};

template <typename T>
void RandomQuickSortVector::randomQuickSort(typename vector<T>::iterator begin, typename vector<T>::iterator end) {

    srand(1);
    srand ((unsigned)time(0));

    if (end <= begin)
        return;

    typename vector<T>::iterator i = randomizedPartition<T>(begin,end);
    randomQuickSort<T>(begin,i-1);
    randomQuickSort<T>(i+1,end);
}

template <typename T>
typename vector<T>::iterator RandomQuickSortVector::randomizedPartition(typename vector<T>::iterator begin, typename vector<T>::iterator end){

    int i = rand()%distance(begin,end);

    swap(*(begin+i),*begin);

    return partition<T>(begin,end);
}

template <typename T>
typename vector<T>::iterator RandomQuickSortVector::partition(typename vector<T>::iterator begin, typename vector<T>::iterator end){

    typename vector<T>::iterator i = begin-1;
    typename vector<T>::iterator j = end;

    T v = *end;

    while(1){

        while(*(++i) < v);
        while(v < *(--j))
            if ( j == begin)
                break;

        if ( i >= j)
            break;
        
        swap(*i,*j);
    }
    swap(*i,*end);
    return i;
}

template <typename T>
void RandomQuickSortVector::compswap(T &A, T &B){
    if (B < A) swap(A, B);
}

template <typename T>
void RandomQuickSortVector::swap(T &A, T &B){
    T t=A; A=B; B=t;
}

#endif // RANDOMQUIKSORTVECTOR_H