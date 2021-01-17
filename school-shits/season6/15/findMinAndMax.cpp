#include <utility>
#include <iostream>


template<typename T, std::size_t N>
void findMinAndMax(T (&arr)[N], int i, int &minElement, int &maxElement)
{
    if (i == N) return;

    if (arr[i] > maxElement) maxElement = arr[i];
    if (arr[i] < minElement) minElement = arr[i];

    findMinAndMax(arr, i+1, minElement, maxElement);
}

int main()
{
    int arr[] = {1, 5, -2, 3, 3, 2};
    int minElement = INT32_MAX;
    int maxElement = INT32_MIN;
    findMinAndMax(arr, 0, minElement, maxElement);
    printf("Min Element = %d\n", minElement);
    printf("Max Element = %d\n", maxElement);
}

// How to convert non-recursive using stacks