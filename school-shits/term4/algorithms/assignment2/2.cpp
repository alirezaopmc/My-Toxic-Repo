/*
Write an algorithm that finds both the smallest and the largest numbers
in a  list of n numbers. Try to find a method that does at most about
1.5 comparisions of array items.
*/

#include <iostream>
#include <vector>
#include <math.h>
// #include <pair>

using namespace std;

pair<int, int> findMinMax(vector<int> &arr, int l, int r);

int main() {
    vector<int> arr = {1, 4, 2, -1, 2, 12};
    auto min_max = findMinMax(arr, 0, 5);
    printf("Min = %d\n", min_max.first);
    printf("Max= %d\n", min_max.second);
}

pair<int, int> findMinMax(vector<int> &arr, int l, int r) {
    if (l == r) return {arr[l], arr[r]};
    
    if (l == r-1) return { min(arr[l], arr[r]), max(arr[l], arr[r]) };

    int mid = (l + r) / 2;

    auto left = findMinMax(arr, l, mid);
    auto right = findMinMax(arr, mid, r);

    return { min(left.first, right.first), max(left.second, right.second) };
}