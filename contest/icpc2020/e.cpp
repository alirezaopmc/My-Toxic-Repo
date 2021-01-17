#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;

const int N = 500;
const int M = N * N;
int a[N][N];
bool b[N][N];

int n, m;
int si, sj;
int ei, ej;

int dfs(int i, int j, bitset<M> b, int carry = INT32_MAX);

int main() {
    cin >> n >> m;

    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '*') {
                for(int k = 0; k < n; k++) {
                    for(int l = 0; l < m; l++) {
                        if (s[k][l] == '#') continue;
                        a[k][l] = min(a[k][l], min(abs(k-i), abs(l-j)));
                    }
                }
            }

            if (s[i][j] == 'S') {
                si = i;
                sj = j;
            }

            if (s[i][j] == 'E') {
                ei = i;
                ej = j;
            }
        }
    }

    cout << dfs(si, sj, ei, ej);
}


int dfs(int i, int j, bitset<M> b, int carry = INT32_MAX) {
    carry = min(a[i][j], carry);
    if (i == ei && j == ej) return carry;

    b |= (i * n + j);

    if (b[i * n + j])
}