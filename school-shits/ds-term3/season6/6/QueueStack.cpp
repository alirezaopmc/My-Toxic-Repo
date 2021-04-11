#include "QueueStack.h"

// Thera(2)
template<typename T>
QueueStack<T>::QueueStack(int MAX)
{
    this->MAX = MAX;
    this->arr = new T[MAX];

    this->queueSize = 0;
    this->queueFirstIndex = 0;
    this->queueLastIndex = 0;

    this->stackSize = 0;
}

// ~
template<typename T>
QueueStack<T>::~QueueStack()
{

}

template <typename T>
void enqueue(T e)
{
    this->arr[(this->queueLastIndex++) % (this->MAX/2) + this->MAX/2] = e;
    this->queueLastIndex %= this->MAX/2;
}

template <typename T>
void dequeue(T e)
{
    return this->arr[(this->queueFirstIndex++) % (this->MAX/2) + this->MAX/2] = e;
    this->queueFirstIndex %= this->MAX/2;
}

template <typename T>
void first(T e)
{
    this->arr[(this->queueFirstIndex) % (this->MAX/2) + this->MAX/2] = e;
}

template <typename T>
void last(T e)
{
    this->arr[(this->queuelastIndex) % (this->MAX/2) + this->MAX/2] = e;
}


// Theta(2)
template<typename T>
void QueueStack<T>::push(T e)
{
    // Error handling when aSize == MAX/2-1
    this->arr[this->stackSize++] = e;
}

// Theta (2)
template<typename T>
T QueueStack<T>::pop()
{
    // Error handling when aSize == 0
    return this->arr[this->stackSize--];
}

// Theta (1)
template<typename T>
T QueueStack<T>::top()
{
    // Error handling when aSize == 0
    return this->arr[this->stackSize];
}