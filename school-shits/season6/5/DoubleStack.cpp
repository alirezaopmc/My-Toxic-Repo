#include "DoubleStack.h"

// Thera(2)
template<typename T>
DoubleStack<T>::DoubleStack(int MAX)
{
    this->MAX = MAX;
    this->arr = new T[MAX];
    this->aSize = 0;
    this->bSize = 0;
}

// ~
template<typename T>
DoubleStack<T>::~DoubleStack()
{

}

// Theta(2)
template<typename T>
void DoubleStack<T>::pushA(T e)
{
    // Error handling when aSize == MAX/2-1
    this->arr[this->aSize++] = e;
}

// Theta (2)
template<typename T>
void DoubleStack<T>::pushB(T e)
{
    // Error handling when bSize == MAX/2 - 1
    this->arr[this->MAX - 1 - this->bSize++] = e;
}

// Theta (2)
template<typename T>
T DoubleStack<T>::popA()
{
    // Error handling when aSize == 0
    return this->arr[this->aSize--];
}

// Theta (2)
template<typename T>
T DoubleStack<T>::popB()
{
    // Error handling when bSize == 0
    return this->arr[this->MAX - 1 - this->bSize--];
}

// Theta (1)
template<typename T>
T DoubleStack<T>::topA()
{
    // Error handling when aSize == 0
    return this->arr[this->aSize];
}

// Theta (1)
template<typename T>
T DoubleStack<T>::topB()
{
    // Error handling when bSize == 0
    return this->arr[this->MAX - 1 - this->bSize];
}
