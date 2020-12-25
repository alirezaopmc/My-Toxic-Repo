#include <iostream>
#include <vector>
#include "../heap/heap.h"

template <typename T>
class stack
{
private:
    heap<std::pair<int, T>> stackHeapArray;
public:
    stack();
    ~stack();
    void push(T e);
    T pop();
    T top();
};