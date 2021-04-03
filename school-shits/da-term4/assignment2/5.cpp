/*
Write a linear-time algorithm that sorts n distinct
integers ranging from 1 to 500, inclusive.
*/

#include <iostream>
#include <vector>

using namespace std;

void linearSort(vector<int> &arr, int N);

int main() {
    int N = 500;
    vector<int> arr = {1, 500, 250, 500, 7, 1, 7, 1};

    linearSort(arr, N);

    for(int x : arr) {
        cout << x << " ";
    }
}

void linearSort(vector<int> &arr, int N) {
    vector<int> count(N, 0);
    for(int x : arr) {
        count[x-1]++;
    }

    int index = 0;
    for(int i = 0; i < N; i++) {
        for(int cnt = 0; cnt < count[i]; cnt++) {
            arr[index++] = i+1;
        }
    }
}