#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;

void test();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        test();
        cout << endl;
    }
}

void test() {
    int n, l, r, s;
    cin >> n >> l >> r >> s;

    int c = r - l;
    int k = c * (c+1) / 2;

    vector<bool> a(n, true);

    if (s - k > c && s - k <= n) {
        for(int i = 0; i <= c; i++) {
            a[i] = false;
        }
        a[s-k] = false;
    }

    int p = 1;

    for(int i = 0; i < n; i++) {
        if (a[i]) {
            cout << i+1;
        } else {
            if (i == c-1) {
                cout << s - k;
            } else {
                cout << p++;
            }
        }
        cout << " ";
    }
}