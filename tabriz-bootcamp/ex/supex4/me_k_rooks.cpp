#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

const int N = 15;

string s[N];
int n;
ll dp[N][N][2][ (1<<N) ];

ll bt(int i, int j, bool tahdid, int mask) {
    if (i == n)
        return 1;
    
    if (j == n)
        return bt(i+1, j, tahdid, mask);

    if (dp[i][j][tahdid][mask] != -1)
        return dp[i][j][tahdid][mask];
    
    if (s[i][j] == '#') {
        if ((mask >> j> & 1))
            // mask ^= (1<<j);
            mask &= -1-(1<<j);
        return dp[i][j][tahdid][mask] = dp(i, j+1, false, mask);
    }

    ll ans = 0 ;

    // Put a rook
    if(!tahdid && !((mask>>j) & 1)) {
        ans += bt(i, j+1, true, mask | (1<<j));
    }

    // Don't put
    
    // ?
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> s[i];
    
    memset(s, -1, dp)
    cout << bt(0, 0, false, 0);
}