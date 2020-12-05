bool TEST_CASE = false;

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

#define l(i,s,n) for(int i=s; i<n; i++)
 
typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

// Global >
const int N = 2e6;
int pr[N/10];
int prs = 0;
int lp[N+10];

int prPartial[N+10];
int plPartial[N+10];
// < Global

// Prototypes >
void init();
void solve();
void sieve();
bool isPal(int n);
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

void sieve()
{
    for(int i = 2; i < N; ++i) {
        if (lp[i] == 0) {
            pr[prs++] = lp[i] = i;
        }

        for(int j = 0; j < prs; ++j) {
            if (pr[j] * i > N || pr[j] > lp[i]) break;
            lp[i * pr[j]] = pr[j];
        }
    }
}

void init()
{
    sieve();

    lp[1] = -1;
    prPartial[0] = plPartial[0] = 0;
    for(int i = 1; i < N; ++i)
    {
        prPartial[i] = prPartial[i-1] + (lp[i] == i);
        plPartial[i] = plPartial[i-1] + isPal(i);
    }

    return;
}

bool isPal(int n)
{
    string s = to_string(n);
    for(int i = 0; i < s.size() / 2; ++i)
        if (s[i] != s[s.size() - i - 1]) return false;
    return true;
}

void solve()
{
    int p, q;
    cin >> p >> q;

    int ans = -1;
    for(int i = 1; i < N; i++) {
        if (p * plPartial[i] >= q * prPartial[i]) {
            // printf("i = %d, p * plPartial[i] = %d, q * prPartial[i] = %d\n", i, p * plPartial[i], q * prPartial[i]);
            ans = i;
        }
    }

    cout << ans;
}