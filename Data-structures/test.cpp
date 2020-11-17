#include "./heap/heap.h"

int main()
{

    /**
     * Heap - Begin
     */
    heap myHeap;

    myHeap.insert(3);
    myHeap.insert(2);
    myHeap.remove(1);
    myHeap.insert(15);
    myHeap.insert(4);
    myHeap.insert(5);
    myHeap.insert(45);

    std::cout << myHeap.extract() << std::endl;
    std::cout << myHeap.min() << std::endl;

    myHeap.set(2, 1);

    std::cout << myHeap.min() << std::endl;

    myHeap.log();

    /**
     * Heap - End
     */
}