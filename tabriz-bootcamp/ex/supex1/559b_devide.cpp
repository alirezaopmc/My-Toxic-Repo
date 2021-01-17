bool TEST_CASE = false;
bool DEBUG_MODE = false;

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
#include <string>

using namespace std;

#define DEBUG(s) if (DEBUG_MODE) {s;}
#define l(i,s,n) for(int i=s; i<n; i++)
 
typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

// Global >
string s, t;
// < Global

// Prototypes >
void solve();
bool equal(int i1, int j1, int l);
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
    cin >> s >> t;
    int n = s.size();

    cout << (equal(0, 0, n) ? "YES" : "NO");
}

bool equal(int i1, int i2, int l)
{
    DEBUG (
        printf("Comparinig %s to %s\n", s.substr(i1, l).c_str(), t.substr(i2, l).c_str());
    )

    if (s.substr(i1, l) == t.substr(i2, l))
    {
        DEBUG (
            printf("They are eqaul\n\n");
        )

        return true;
    }

    else if (l % 2)
    {
        DEBUG (
            printf("Odd Length\n");
        )

        if (s.substr(i1, l) == t.substr(i2, l))
        {
            DEBUG (
                printf("Equal!\n");
            )

            return true;
        }
        else
        {
            DEBUG (
                printf("Not Equal!\n");
            )

            return false;
        }
        
    }

    else
    {
        DEBUG (
            printf("Swap Check!\n");
        )

        bool leftToRight = equal(i1, i2 + l/2, l/2);
        bool rightToLeft = equal(i1 + l/2, i2, l/2);
        
        if (leftToRight && rightToLeft)
        {
            DEBUG (
                printf("Equal!\n");
            )

        }
        else
        {
            DEBUG (
                printf("Not Equal!\n");
            )
        }
        
        return leftToRight && rightToLeft;
    }
}



/**
 * Author: Alireza Jafartash
 * Handle: alirezaopmc
 * Data: 11/30/2020 4:53 AM - Babol
 * 
 * Devide and conquer method
 * 
 * My function checks if the length is odd then return s == t
 * Otherwise we check s == t and return if it's okay
 * For s != t:
    * let S = AB
    * let T = XY
    * return Equal(A, Y) & Equal(B, X)
 * 
 * I'm going to implement the other solution of this problem
 * which was described in the editorial. Check my submissions
 */