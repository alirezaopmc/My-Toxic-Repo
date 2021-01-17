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
        return bt(i+1, 0, false, mask);

    if (dp[i][j][tahdid][mask] != -1)
        return dp[i][j][tahdid][mask];
    
    if (s[i][j] == '#') {
        if ((mask >> j) & 1)
            mask &= -1-(1<<j);
            // mask ^= (1<<j);
        ll ans = bt(i, j+1, false, mask);
        return dp[i][j][tahdid][mask] = ans;
    } else {
        ll ans = 0 ;

        // Put a rook
        if(!tahdid && ((mask>>j) & 1) == 0) {
            ans += bt(i, j+1, true, mask | (1<<j));
        }
        
        // Don't put
        ans += bt(i, j+1, tahdid, mask);

        return dp[i][j][tahdid][mask] = ans;;
    }
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> s[i];

    cout << bt(0, 0, false, 0) << endl;
}

/**
 * Author: Alireza Jafartash
 * I just rewrite the backtracking solution to the rooks problem.
 * Statement:
 *  We have n x n grid with some blocks shown with '#'
 *  We wanna put some rooks so that no two of them
 *  attacks each other
 * 
 * This is just a bit smart backtracking which passes
 * some mask over calls.
 * 
 * mask: status of columns of the grid (which are ((filled)) attack currently)
 * tahdid: status of rows of the grid (which are ((filled)) attack currently)
 * 
 * i use bt function rom (0,0) up to (n-1, n-1)
 * 
 * 
 * Thx to LiTi <3
 * 12/2/2020 - 7AM - Babol
 */