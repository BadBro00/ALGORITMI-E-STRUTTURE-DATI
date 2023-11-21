#ifndef QUICKSORTVECTOR_H
#define QUICKSORTVECTOR_H

#include <vector>

using namespace std;

template <typename T>
class QuickSortVector{
    private:
        static typename vector<T>::iterator partition(typename vector<T>::iterator, typename vector<T>::iterator);
        static void swap(T&,T&);
    public:
        static void quickSort(typename vector<T>::iterator, typename vector<T>::iterator);
};

template <typename T>
void QuickSortVector<T>::quickSort(typename vector<T>::iterator begin, typename vector<T>::iterator end){

    auto size = distance(begin, end);

    if (size <= 0)
        return;

    typename vector<T>::iterator i = partition(begin,end);
    quickSort(begin,i-1);
    quickSort(i+1,end);
}

template <typename T>
typename vector<T>::iterator QuickSortVector<T>::partition(typename vector<T>::iterator begin, typename vector<T>::iterator end){

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
void QuickSortVector<T>::swap(T &A, T &B){
    T t=A; A=B; B=t;
}

#endif // QUICKSORTVECTOR_H