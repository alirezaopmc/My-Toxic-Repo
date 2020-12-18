#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200;
const int M = 11;
const int D = 10;
const int MOD = 1e9 + 7;

typedef long long ll;

inline int sum(int a, int b) { 
    ll c = a + b; 
    if (c >= MOD)
        c -= MOD; 
    return c;
}

vector<int> cnt(11, 0);

ll solve(int n, int m)
{
    if (n == 1) if(cnt[m] > 0) return 1; else return 0;

    bool flag = false;
    int k = -1;
    for(int i = 0; i < D; ++i)
    {
        if (cnt[i] > 0 && !flag) {
            flag = true;
            k = i;
            continue;
        }
        if (cnt[i] > 0 && flag) {
            flag = false;
            break;
        }
    }

    if (flag) {
        if (m == 10) return 0;
        if (m == k && cnt[k] % 2 == 1) return 1;
        if (m == 0 && cnt[k] % 2 == 0) return 1;
        return 0;
    }

    ll ans = 0;

    for(int d = 0; d < D; ++d)
    {
        if(cnt[d] > 0)
        {
            int x = (11 + d - m) % 11;
            cnt[d]--;
            ans = (ans + solve(n-1, x)) % MOD;
            cnt[d]++;
        }
    }

    return ans;
}

int main()
{
    cnt[10] = 0;
    for(int i = 0; i < D; ++i) cin >> cnt[i];
    
    int k = 0;
    for(int i = 0; i < D; ++i) k += cnt[i];

    // cout << k << endl;
    cout << solve(k, 0);
}