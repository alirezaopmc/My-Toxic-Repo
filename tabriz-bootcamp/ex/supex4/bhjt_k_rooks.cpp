#include <iostream>
#include <cstring>
using namespace std; 
typedef long long ll;

const int N = 15;

string s[N]; 
int n; 

ll dp[N][N][2][(1<<N)];

ll bt(int i, int j, bool tahdid, int mask) { 
    if (i == n) 
        return 1;

    if (j == n) 
        return bt(i+1, 0, false, mask); 

    // i, j, tahdid, mask
    if (dp[i][j][tahdid][mask] != -1) 
        return dp[i][j][tahdid][mask];

    if (s[i][j] == '#') {
        if ((mask >> j) & 1)
            mask ^= (1<<j);
        ll ans = bt(i, j + 1, false, mask);
        dp[i][j][tahdid][mask] = ans;
        return ans;
    }

    ll ans = 0;
    if (!tahdid && ((mask >> j) & 1) == 0) { 
        // Rokh bezar
        int nmask = mask | (1<<j);
        ans += bt(i, j + 1, true, nmask);
    }

    // Rokh nazar
    ans += bt(i, j + 1, tahdid, mask);

    dp[i][j][tahdid][mask] = ans;
    return ans;
}

int main() { 
    memset(dp, -1, sizeof dp);

    cin >> n; 
    for(int i = 0; i < n; i++) 
        cin >> s[i]; 
    cout << bt(0, 0, false, 0) << endl;
}   