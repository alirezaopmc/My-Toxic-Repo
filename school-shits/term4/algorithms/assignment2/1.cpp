/*
Write an algorithm that prints out all the subsets of three elements
of n elements. The elements of this set are stored in a list that is
the input to the algorithm.
*/

#include <iostream>
#include <vector>

using namespace std;

void threeSubsets(vector<int> &arr);

int main() {
    vector<int> arr = {1, -4, 9, 6, 3};
    threeSubsets(arr);
}

void threeSubsets(vector<int> &arr) {
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                printf("[%d, %d, %d]\n", arr[i], arr[j], arr[k]);
            }
        }
    }
}