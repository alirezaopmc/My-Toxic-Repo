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
string minOf(const string &str);
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

    cout << (minOf(s) == minOf(t) ? "YES" : "NO");
}

string minOf(const string &str)
{
    int l = str.size();
    if (l % 2) return str;

    string left = minOf(str.substr(0, l/2));
    string right = minOf(str.substr(l/2, l/2));

    return min(left, right) + max(left, right);
}

/**
 * Author: Alireza Jafartash
 * Handle: alirezaopmc
 * Data: 11/30/2020 5:14 AM - Babol
 * 
 * Lexi-Min method
 * 
 * Recusively lexicographically minimum strings will be checked
 * 
 * I have another implementation of this problem
 * which was wrong. (now) not fixed yet.
 */