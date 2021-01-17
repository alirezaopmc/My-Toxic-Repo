bool TEST_CASE = true;

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define l(i,s,n) for(int i=s; i<n; i++)
 
typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

// Global >
const int N = 10e6;
int lp[N+1];
vector<int> pr;
// < Global

// Prototypes >
void init();
void solve();
void sieve();
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
    sieve();
}

void sieve()
{
    l(i, 2, N+1)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }

        for(int p : pr)
        {
            if (p > lp[i] || i * p >= N) break;
            lp[i * p] = p;
        }
    }

}

void solve()
{
    ll x;
    cin >> x;

    ll sq = sqrt(x);
    if (sq * sq == x && lp[sq] == sq) cout << "YES"; else cout << "NO";
}