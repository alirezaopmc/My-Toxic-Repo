#include <iostream>
#include <algorithm>

#define l(i,s,n) for(int i=s;i<n;++i)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int a[1000][1000];
    l(i, 0, n)l(j, 0, m) cin >> a[i][j];

    int ans = 0;

    l(i1, 0, n)l(i2, i1+1, n)
    {
        int p, q;
        p = q = 0;

        l(j, 0, m)
        {
            if (a[i1][j] > ans && a[i2][j] > ans)
            {
                p = min(a[i1][j], a[i2][j]);

                /*
                In Harekat vaghean zibas
                in yani inke taa vaghti ke ma
                dovomio peyda nakardim
                kari nakone
                (ba tavajoh be kari ke bad
                azin if mikonim)
                */ 
                if (p > q) swap(p, q);
            }
            ans = max(ans, p);
        }
    }

    cout << ans;

    return 0;
}