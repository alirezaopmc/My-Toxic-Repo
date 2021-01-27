#include "heap.h"
#include <iostream>

template <typename T>
heap<T>::heap()
{
}


template <typename T>
heap<T>::~heap()
{
}

template <typename T>
T heap<T>::min()
{
    return heapArray[0];
}


template <typename T>
T heap<T>::extract()
{
    if (heapArray.empty()) return NULL;

    T root = heapArray[0];

    if (heapArray.size() > 1)
    {
        heapArray[0] = heapArray[heapArray.size() - 1];
        heapify(0);
    }

    heapArray.pop_back();

    return root;
}



template <typename T>
void heap<T>::heapify(int index)
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



template <typename T>
void heap<T>::insert(T value)
{
    heapArray.push_back(value);
    int index = heapArray.size() - 1;
    inverseHeapify(index);
}



template <typename T>
void heap<T>::remove(int index)
{
    set(index, INT32_MIN);
    extract();
}



template <typename T>
void heap<T>::set(int index, T value)
{
    heapArray[index] = value;
    inverseHeapify(index);
}



template <typename T>
void heap<T>::inverseHeapify(int index)
{
    while(index && heapArray[index] < heapArray[parent(index)])
    {
        std::swap(heapArray[index], heapArray[parent(index)]);
        index = this->parent(index);
    }
}



template <typename T>
int heap<T>::left(int index)
{
    return 2 * index + 1;
}



template <typename T>
int heap<T>::right(int index)
{
    return 2 * index + 2;
}



template <typename T>
int heap<T>::parent(int index)
{
    return (index-1) / 2;
}



template <typename T>
void heap<T>::log()
{
    for(auto element : heapArray)
    {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
}



template <typename T>
int heap<T>::size()
{
    return heapArray.size();
}