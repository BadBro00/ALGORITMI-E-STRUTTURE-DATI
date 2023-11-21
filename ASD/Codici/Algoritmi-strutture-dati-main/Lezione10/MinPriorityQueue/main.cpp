/*
    MinPriorityQueue
*/

#include "MinPriorityQueue.h"
#include <iostream>

int main(){

    MinPriorityQueue<int> minQueue;

    minQueue.queueInsert(100);
    minQueue.queueInsert(200);
    minQueue.queueInsert(20);
    minQueue.queueInsert(420);
    minQueue.queueInsert(80);
    minQueue.queueInsert(820);
    minQueue.queueInsert(1020);
    minQueue.queueInsert(600);

    minQueue.printAsciiTree();

    std::cout << "Minimum 1: " << minQueue.minimum() << std::endl;
    std::cout << "Minimum 2: " << minQueue.minimum() << std::endl;

    std::cout << "Extract Min 1: " << minQueue.extractMin() << std::endl;
    std::cout << "Extract Min 2: " << minQueue.extractMin() << std::endl;

    minQueue.printAsciiTree();
 
    minQueue.decreasePriority(2,20);  

    minQueue.printAsciiTree();

    return 0;
}