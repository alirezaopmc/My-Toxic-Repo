#ifndef _heap_
#define _heap_

#include "stack.h"

/**
 * Explanation:
 * 
 * The heap used in this example is MinHeap
 * 
 */


template <typename T>
stack<T>::stack()
{
    cnt = 0;
}

template <typename T>
stack<T>::~stack()
{

}

template <typename T>
void stack<T>::push(T e)
{
    stackHeapArray.insert({cnt++, e});
}

template <typename T>
T stack<T>::pop()
{
    return stackHeapArray.extract();
}

template <typename T>
T stack<T>::top()
{
    return stackHeapArray.min();
}

#endif