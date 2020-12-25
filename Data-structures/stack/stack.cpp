#ifndef _heap_
#define _heap_

#include "stack.h"

template <typename T>
stack<T>::stack()
{

}

template <typename T>
stack<T>::~stack()
{

}

template <typename T>
void stack<T>::push(T e)
{
    stackHeapArray.insert({stackHeapArray.size(), e})
}

template <typename T>
T stack<T>::pop()
{
    return heapArray.extract();
}

template <typename T>
T stack<T>::top()
{
    return heapArray.min();
}

#endif