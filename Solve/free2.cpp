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
vector<int> x;
// < Global

// Prototypes >
void init();
void solve();
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
    x.resize(n+1, 0);
    l(i, 1, n+1)
    {
        cin >> x[i];
        if (i>1) x[i] += x[i-1];
    }

    int l=1, r=n-1;

    while(l <= r)
    {
        int mid = (l + r + 1) / 2;

        bool flag = false;
        
    }
}