bool TEST_CASE = false;

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
#include <string>

using namespace std;

#define l(i,s,n) for(int i=s; i<n; i++)
 
typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

// Global >
vector<int> a;
// < Global

// Prototypes >
void solve();
void update(int i, int h);
// < Prototypes

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n = 1;
    if (TEST_CASE) cin >> n;

    l(i, 0, n) solve();
}

void solve()
{
    int n, m;
    cin >> n >> m;
    n = pow(2, n);
    // cout << n << endl;
    a.resize(2*n, 0);
    
    for(int i = n; i < 2*n; i++) cin >> a[i];
    
    int c = 0;
    int t = 0;
    int k = n;
    for(int i = 2*n-1; i > 1; i--)
    {
        int p = i / 2;
        
        if (t % 2)
        {
            a[p] ^= a[i];
        }
        else
        {
            a[p] |= a[i];
        }

        c += 1;
        if (c == k) {
            k /= 2;
            t++;
            c = 0;
        }
    }

    // for(int i = 0; i < 2*n; i++) cout << a[i] << " \n"[i == 2*n-1];

    for(int i = 0; i < m; i++)
    {
        int p, b;
        cin >> p >> b;
        a[p + n -1] = b;
        update(p + n - 1, 0);
        cout << a[1] << endl;
        // for(int i = 0; i < 2*n; i++) cout << a[i] << " \n"[i == 2*n-1];
    }
}

void update(int i, int h)
{
    if (i == 1) return;

    int p = i / 2;
    int l = 2 * p;
    int r = 2 * p + 1;

    if (h % 2)
    {
        a[p] = a[l] ^ a[r];
    }
    else
    {
        a[p] = a[l] | a[r];
    }

    update(p, h^1);
}