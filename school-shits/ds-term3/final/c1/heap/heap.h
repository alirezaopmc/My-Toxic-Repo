#ifndef HEAP_H
#define HEAP_H

#include <vector>

class heap
{
private:
    std::vector<int> heapArray;
public:
    heap();
    ~heap();
    int extract();
    int min();
    void heapify(int index);
    void insert(int value);
    void remove(int index);
    int get(int index);
    void set(int index, int value);
    void inverseHeapify(int index);
    int size();
    int left(int index);
    int right(int index);
    int parent(int index);
    void log();
    void resize(int n);
};

#endif