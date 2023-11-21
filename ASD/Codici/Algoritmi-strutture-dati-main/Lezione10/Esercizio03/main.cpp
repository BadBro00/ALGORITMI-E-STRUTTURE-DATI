/*
    • Dato un array di n elementi, trovare il massimo numero di
      elementi distinti dopo aver rimosso k elementi (k<=n)
    
    • Es.: {5,4,4,3,4,6,2,1,2}, per k=2 maximum=5(5,3,6,2,1), per k=3 maxnum=6(5,4,3,6,2,1)
*/
#include <iostream>
#include <vector>
#include "../../ASD/StruttureDati/MaxPriorityQueue.h"
#include <map>

int main(){

  std::vector<int> seq = {5, 4, 4, 3, 4, 6, 2, 1, 2};
  const int k = 2;

  std::cout << "K=" << k << std::endl;

  map<int,int> amap;
  map<int,int>::iterator cii;
  int num;

  // conto occorrenze con una mappa
  for (int i=0; i<seq.size(); i++){

    num = seq.at(i);

    cii = amap.find(num);
    if ( cii == amap.end())
        amap.insert(make_pair(num,1));
    else   
        amap.at(num)++;
  }

  map<int,int>::iterator it;
  for ( it = amap.begin(); it != amap.end(); it++)
      std::cout << "map [" << it->first << "] = " << it->second << std::endl;


  MaxPriorityQueue<int> maxQueue;
  for ( cii = amap.begin(); cii != amap.end(); cii++)
    maxQueue.queueInsert(cii->second);

  maxQueue.printAsciiTree();

  std::vector<int>::iterator its = seq.begin();

  int z = 0;
  while (seq.size() > k){
    std::cout << std::endl << "i=" << z++ << std::endl;

    for (int l=0; l<k; l++){

      int max = maxQueue.maximum(), j = 0;

      its = seq.begin();
      cii = amap.begin();

      while ( max != cii->second ) cii++;
      while ( cii->first != *its ) its++;

      seq.erase(its);
      cii->second--;
      maxQueue.decreasePriority(0,max-1);
    }

    for ( int i=0; i<seq.size(); i++)
      std::cout << "seq [" << i << "] = " << seq.at(i) << std::endl;
  }

  return 0;
}