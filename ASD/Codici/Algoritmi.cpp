// SORTING

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INT_MAX 255

template<class T>
void compswap(T &a, T &b){
	if(a < b){
		T tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
}

//1) Insertion Sort - T(n) = O(n^2)
template <class T>
void Ins_Sort(T a[],int l,int r){
	for(int j=1;j<r;j++){
		T key = a[j];
		//Sequence a[1...j-1]
		int i = j-1;
		while(j>=0 && a[j] > key){
			compswap(a[j-1],a[j]);
			j--;
		}
		a[j+1] = key;
	 }
}

//2) Merge Sort - T(n) = theta(nlogn)
template<class T>
void merge(T a[],int p,int q,int r){
	int i,j;
	int n1 = q-p+1;
	int n2 = r-q;
	T L[n1+1],R[n2+1];
	for(i=0;i<n1;i++){
		L[i] = a[p+i-1];
	}
	for(j=0;j<n2;j++){
		R[j] = a[q+j];
	}
	L[n1+1] = INT_MAX;
	R[n2+1] = INT_MAX;
	i=j=0;
	for(int k=p;k<r;k++){
		if(L[i] <= R[j]){
			a[k] = L[i];
			i++;
		}else{
			a[k] = R[j];
			j++;
		}
	}
}

template <class T>
void mergesort(T a[],int p, int r){
	if(p<r){
		int q = floor((p+r)/2);
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}



int main(){
	srand(time(0));
	int dim = 8;
	int a[dim];
	int i;
	for(i=0;i<dim;i++)
		a[i] = (dim-i)-(i+1);
	for(i=0;i<dim;i++){
		printf("a[%d] = %d\n",i,a[i]);
	}
	printf("\n\n");
	printf("\t\t1)Inserition Sort\n");
	Ins_Sort<int>(a,0,dim);
	printf("\t\t|Array Ordinato|\n");

	for(i=0;i<dim;i++){
		printf("a[%d] = %d\n",i,a[i]);
	}
	for(i=0;i<dim;i++)
		a[i] = (dim-i)-(i+1);
	printf("\n\n");
	printf("\t\t2)Merge Sort\n");
	mergesort<int>(a,0,dim);
	for(i=0;i<dim;i++){
		printf("a[%d] = %d\n",i,a[i]);
	}
	printf("\n\n");
}
