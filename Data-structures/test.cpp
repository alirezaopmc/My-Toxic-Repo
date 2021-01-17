#include "./heap/heap.h"
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <bitset>



int main()
{

    /**
     * Heap - Begin
     */
    heap<int> myHeap;

    myHeap.insert(3);
    myHeap.insert(2);
    myHeap.remove(1);
    myHeap.insert(15);
    myHeap.insert(4);
    myHeap.insert(5);
    myHeap.insert(45);

    // std::cout << myHeap.extract() << std::endl;
    // std::cout << myHeap.min() << std::endl;

    // myHeap.set(2, 1);

    // std::cout << myHeap.min() << std::endl;

    myHeap.log();

    /**
     * Heap - End
     */
}