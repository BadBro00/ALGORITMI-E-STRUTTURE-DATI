/*
    Max Priority Queue
*/

#include "MaxPriorityQueue.h"
#include <iostream>

int main(){

    MaxPriorityQueue<int> maxQueue;

    maxQueue.queueInsert(100);
    maxQueue.queueInsert(200);
    maxQueue.queueInsert(20);
    maxQueue.queueInsert(420);
    maxQueue.queueInsert(80);
    maxQueue.queueInsert(820);
    maxQueue.queueInsert(1020);
    maxQueue.queueInsert(600);

    maxQueue.printAsciiTree();

    std::cout << "Maximum 1: " << maxQueue.maximum() << std::endl;
    std::cout << "Maximum 2: " << maxQueue.maximum() << std::endl;

    std::cout << "Extract Max 1: " << maxQueue.extractMax() << std::endl;
    std::cout << "Extract Max 2: " << maxQueue.extractMax() << std::endl;

    maxQueue.printAsciiTree();
 
    maxQueue.increasePriority(2,20);  

    maxQueue.printAsciiTree();

    return 0;
}