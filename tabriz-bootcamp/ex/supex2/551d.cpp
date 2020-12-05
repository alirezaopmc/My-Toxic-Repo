bool TEST_CASE = false;

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define lp(i,s,n) for(int i=s; i<n; i++)
 
typedef long long ll;
typedef unsigned long long ull;
typedef double long ld;
typedef int Mat[2][2];

// Global >
ull n, k, l, m;
Mat R, T, X, F;
// < Global

// Inline >
ll sum(int a, int b)
{
    if (a + b >= m) return a + b - m;
    else return a + b;
}

ll mul(int a, int b)
{
    return 1ll * a * b % m;
}
// < Inline

// Prototypes >
void init();
void solve();
void mul(Mat a, Mat b, Mat c);
int fibo(int n);
// < Prototypes

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n = 1;
    if (TEST_CASE) cin >> n;

    init();

    lp(i, 0, n)
    {
        solve();
        cout << endl;
    }
}

void init()
{
    R[0][0] = R[1][1] = 1;
    X[0][1] = X[1][0] = X[1][1] = 1;
    F[0][0] = 1; F[1][0] = 2;
}

void solve()
{
    cin >> n >> k >> l >> m;

    if (k < (1 << l)) {
        ll ans = 1;
        int fb = fibo(n);
        int tl = (1 << n);
        l++;
        while(l) {
            if (k & 1)
                ans = mul(ans, fb);
            else
                ans = mul(ans, tl - fb);
            k >>= 1;
            l--;
        }
        cout << ans;
    } else {
        cout << 0;
    }
    
}

void mul(Mat a, Mat b, Mat c)
{
    lp(i,0,2)lp(j,0,2) c[i][j]=0;
    lp(i,0,2)lp(j,0,2)lp(k,0,2) c[i][k] = sum(c[i][k], mul(a[i][j], b[j][k]));
}

int fibo(int n)
{
    for(; n; n >>= 1)
    {
        if (n & 1)
        {
            mul(X, R, T);
            swap(R, T);
        }
        mul(X, X, T);
        swap(T, X);
    }

    mul(R, F, T);

    return T[0][0];
}