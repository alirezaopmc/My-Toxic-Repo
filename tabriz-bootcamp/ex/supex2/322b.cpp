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

void solve()
{
    int a[3];
    l(i,0,3) cin >> a[i];
    sort(a, a+3);
    
    int ans = 0;
    l(i,0,min(a[0]+1,3)) ans = max(
        ans,
        i + (a[0]-i) / 3 + (a[1]-i) / 3 + (a[2]-i) / 3
    );

    cout << ans;
    
}