bool TEST_CASE = true;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define l(i,s,n) for(int i=s; i<n; i++)
 
typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

// Global >

// < Global

// Prototypes >
void solve();
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
    cout << (int) 1.2e3;
}