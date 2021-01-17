bool TEST_CASE = false;

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

// < Global

// Prototypes >
void init();
void solve();
int gcd(int a, int b);
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
    return;
}

int gcd(int a, int b)
{
    if (a == 0) return b;
    else return gcd(b % a, a);
}

void solve()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    l(i,0,n) cin >> a[i];

    sort(a.begin(), a.end());

    int g = a[0];

    l(i, 1, n) g = gcd(g, a[i]);

    l(i, 0, n) a[i] /= g;

    int ans = a[n-1] - a.size();

    // cout << g << endl;
    // l(i,0,n) cout << a[i] << " \n"[i == n-1];

    cout << (ans & 1 ? "Alice" : "Bob");
}