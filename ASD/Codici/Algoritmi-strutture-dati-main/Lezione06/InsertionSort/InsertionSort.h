#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

class InsertionSort{
    public:
        static void insertionSort(int[],int);
};

void InsertionSort::insertionSort(int ptr[], int numvar){
    int key,i;
    for (int j=1; j<numvar; j++){
        key = ptr[j];
        i = j-1;

        while ( i >= 0 && ptr[i] > key ){
            ptr[i+1] = ptr[i];
            i--;
        }
        ptr[i+1] = key;
    }
}

#endif // INSERTIONSORT_H