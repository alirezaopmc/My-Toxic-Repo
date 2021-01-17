#include <iostream>
#include <vector>

using namespace std;

void oddEvenBubbleSort(vector<int> &v);

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    oddEvenBubbleSort(v);

    for(int i = 0; i < n; i++)
        cout << v[i] << " \n"[i == n-1];
}

void oddEvenBubbleSort(vector<int> &v) {
    int n = v.size();
    for(int i = 0; i < n; i += 2) {
        for(int j = 0; j <= i; j += 2) {
            if (v[i] > v[j]) swap(v[i], v[j]);
        }
    }
    
    int k = n-1;
    if (k % 2 == 0) k--;
    for(int i = k; i >= 0; i -= 2) {
        for(int j = k; j > i; j -= 2) {
            if (v[j] > v[i]) swap(v[i], v[j]);
        }
    }
}