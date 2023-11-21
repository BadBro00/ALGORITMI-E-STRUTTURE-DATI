/*
    Esercizio

    • Progettare ed implementare un algoritmo ricorsivo che dato
      un array verifichi se rappresenta un heap binario
*/

#include <iostream>
#include "IsHeap.h"

int main(){

  int arrayMax[] = {100,90,80,70,60,50};
  std::cout << "\nRis: " << IsHeap::isHeap(arrayMax,6,0);

  int arrayMin[] = {1,2,3,4,5,6,7,8};
  std::cout << "\nRis: " << IsHeap::isHeap(arrayMin,8,0);

    int array[] = {100,120,80,2,220,330};
  std::cout << "\nRis: " << IsHeap::isHeap(array,6,0);

  return 0;
}