/*
    Counting Sort Cormen
*/

#include <iostream>

using namespace std;

void countingSortCormen(int array[], int n){

    int max = array[0];
    int min = array[0];

    for(int i=1; i<n; i++){

        if( array[i] > max ) 
            max = array[i];
        else if( array[i] < min ) 
            min = array[i];
    }

    int lengthC = max-min+1; //Costruzione dell'array
    int c[lengthC];

    for (int i=0; i<lengthC; i++)
        c[i] = 0;

    for (int i=0; i<n; i++)
        c[array[i]-min]++;

    for (int i=1; i<lengthC; i++)
        c[i] += c[i-1];
    
    int b[n];
    for (int i=n-1; i>=0; i--){
        b[ c[ array[i] - min ]-1 ] = array[i];
        c[ array[i] - min ]--;
    }

    for (int i=0; i<n; i++)
        array[i] = b[i];
}

int main(){

    int numvar = 8;
    int a[] = {100,20,40,20,12,120,220,240};

    countingSortCormen(a,numvar);

    for (int i=0; i<numvar; i++)
        cout << a[i] << " ";
    cout << endl;
}