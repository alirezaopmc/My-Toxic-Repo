#ifndef _heap_
#define _heap_

#include <iostream>
#include <vector>

#include "heap.h"


heap::heap()
{
}



heap::~heap()
{
}


int heap::min()
{
    return heapArray[0];
}


int heap::extract()
{
    if (heapArray.empty()) return INT32_MAX;

    int root = heapArray[0];

    if (heapArray.size() > 1)
    {
        heapArray[0] = heapArray[heapArray.size() - 1];
        heapify(0);
    }

    this->heapArray.pop_back();

    return root;
}



void heap::heapify(int index)
{
    int leftChild = left(index);
    int rightChild = right(index);
    int smallerChild = index;

    if (leftChild < heapArray.size() && heapArray[leftChild] < heapArray[index])
    {
        smallerChild = leftChild;
    }
    
    if (rightChild < heapArray.size() && heapArray[rightChild] < heapArray[index])
    {
        smallerChild = rightChild;
    }

    if (smallerChild != index)
    {
        std::swap(heapArray[smallerChild], heapArray[index]);
        heapify(smallerChild);
    }
}



void heap::insert(int value)
{
    heapArray.push_back(value);
    int index = heapArray.size() - 1;
    inverseHeapify(index);
}



void heap::remove(int index)
{
    set(index, INT32_MIN);
    extract();
}



void heap::set(int index, int value)
{
    heapArray[index] = value;
    inverseHeapify(index);
}



void heap::inverseHeapify(int index)
{
    while(index && heapArray[index] < heapArray[parent(index)])
    {
        std::swap(heapArray[index], heapArray[parent(index)]);
        index = this->parent(index);
    }
}



int heap::left(int index)
{
    return 2 * index + 1;
}



int heap::right(int index)
{
    return 2 * index + 2;
}



int heap::parent(int index)
{
    return (index-1) / 2;
}



void heap::log()
{
    for(auto element : heapArray)
    {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
}

#endif