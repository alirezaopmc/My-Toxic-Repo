/*
Give an algorithm for the following problem. 
Given a list of n distinct positive
integers, partition the list into two
sublists, each of size n/2, such that the
difference between the sums of the integers
in the two sublists is minimized. Determine
the time complexity of your algorithm.
You may assume that n is a multiple of 2. 
*/

/*
Simple naive brute-force algorithm that checks
all subsets.
*/

/*
Time complexity O(ns) where:
    n: the number of elements
    s: sum of all elements
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void partitionWithMinDifference(vector<int> &arr, vector<bool> &record, int i, int &sum, int total);

int main() {
    vector<int> arr = {
        9, 2, 11, 12, 45, 1, 3
    };
    int n = arr.size();

    int total = 0;
    for(int x : arr) total += x;

    int sum = 0;
    vector<bool> partition(n+1);
    partitionWithMinDifference(arr, partition, 0, sum, total);

    for(int i = 0; i < n; i++) {
        if (partition[i]) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    for(int i = 0; i < n; i++) {
        if (!partition[i]) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void partitionWithMinDifference(vector<int> &arr, vector<bool> &record, int i, int &sum, int total) {
    int n = arr.size();

    if (i == n) {
        return;
    }

    vector<bool> with = record, without = record;
    with[i] = true;
    int withSum = sum + arr[i], withoutSum = sum;
    
    partitionWithMinDifference(arr, with, i+1, withSum, total);
    partitionWithMinDifference(arr, without, i+1, withoutSum, total);

    if (abs(total - 2 * withSum) < abs(total - 2 * withoutSum)) {
        record = with;
        sum += arr[i];
    } else {
        record = without;
    }
}