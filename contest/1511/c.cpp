#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;

const int N = 51;
const int M = 1e6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<int> f(N, INT32_MAX);

    vector<int> d(M);
    int _i = 0;

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f[x] = min(f[x], i);
    }

    
}