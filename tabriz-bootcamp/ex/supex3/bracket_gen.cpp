/**
 * Backtracking solotion for bracket problem
 * 4:
 * (())
 * ()()
 */

#include <iostream>

using namespace std;

const int N = 30;

char c[N];

void bt(int n, int cnt, int i) {
    if (i == n && cnt == 0) {
        for(int i = 0; i < n; ++i) cout << c[i];
        cout << endl;
        return;
    }

    if (i + cnt >= n) {
        while(i < n) c[i++] = ')';
        for(int i = 0; i < n; ++i) cout << c[i];
        cout << endl;
        return;
    }

    c[i] = '(';
    bt(n, cnt+1, i+1);

    if (cnt > 0) {
        c[i] = ')';
        bt(n, cnt-1, i+1);
    }
}

int main() {
    int n;
    cin >> n;

    bt(n, 0, 0);
}