#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2000;
const int D = 10;

string s[N];
int firstOfRow[N][D];
int lastOfRow[N][D];
int firstOfCol[N][D];
int lastOfCol[N][D];

int ans[D];

void solve() {
    memset(firstOfRow, -1, sizeof(firstOfRow));
    memset(firstOfCol, -1, sizeof(firstOfCol));
    memset(lastOfRow, -1, sizeof(lastOfRow));
    memset(lastOfCol, -1, sizeof(lastOfCol));
    memset(ans, 0, sizeof(ans));
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int d = s[i][j] - '0';
            if (firstOfRow[i][d] == -1) firstOfRow[i][d] = j;
            if (firstOfCol[j][d] == -1) firstOfCol[j][d] = i;
            lastOfRow[i][d] = j;
            lastOfCol[j][d] = i;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int d = 0; d < D; d++) {
            ans[d] = max(ans[d], max(i, n-i-1) * (lastOfRow[i][d] - firstOfRow[i][d]));
        }
    }

    for(int j = 0; j < n; j++) {
        for(int d = 0; d < D; d++) {
            ans[d] = max(ans[d], max(j, n-j-1) * (lastOfCol[j][d] - firstOfCol[j][d]));
        }
    }

    for(int d = 0; d < D; d++) {
        cout << ans[d] << " \n"[d == D - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while(n--) {
        solve();
        cout << endl;
    }
}