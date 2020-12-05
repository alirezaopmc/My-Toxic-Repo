bool TEST_CASE = false;

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

#define l(i,s,n) for(int i=s; i<n; i++)
 
typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

// Global >
ll n;
map<pair<int, int>, ll> mp;
const int MOD = 1e9+7;
// < Global

// Prototypes >
void init();
void solve();
ll f(int a, int b);
// < Prototypes

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n = 1;
    if (TEST_CASE) cin >> n;

    init();

    l(i, 0, n)
    {
        solve();
        cout << endl;
    }
}

void init()
{
    
}

void solve()
{
    int n;
    cin >> n;

    cout << f(n, n);
}

ll f(int a, int b)
{
    if (b == 0 || a == 0) return (a + b + 1) % MOD;

    if (mp[{a, b}] == 0)
    {
        if (a == b) {
            mp[{a, b}] = mp[{b, a}] = (2LL * f(a-1, a) + 1) % MOD;
        } else {
            mp[{a, b}] = mp[{b, a}] = (1LL + f(a-1, b) + f(a, b-1)) % MOD;
        }
    }

    return mp[{a, b}];
}