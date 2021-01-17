#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define l(i,s,n) for(int i=s;i<n;++i)
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n+1, 0);
    l(i, 1, n+1) cin >> a[i];

    l(i, 1, n+1) a[i] += a[i-1];
    // l(i, 0, n+1) cout << a[i] << " "; cout << endl;

    

    int i1=0, i2=0, i3=0;
    ll record = 0;
    
    if (n < 50)
    {
        l(i, 0, n+1) l(j, i, n+1) l(k, j, n+1)
        {
            ll ez = a[i] - a[j] + a[i] + a[k] - a[j] - a[n] + a[k];
            // cout << i << " " << j << " " << k << " => " << ez << endl;
            if (ez > record)
            {
                record = ez;
                i1 = i;
                i2 = j;
                i3 = k;
            }
        }
    }
    else
    {
        abs(a[n]);
        i1 = i2 = i3 = (a[n] > 0 ? n : 0);

        l(p, 1, n)
        {
            ll bestLeft = abs(a[p]);
            ll iLeft = (a[p] > 0 ? p : 0);

            l(q, 1, p)
            {
                ll curSum = a[q] - (a[p] - a[q]);
                if (curSum > bestLeft)
                {
                    bestLeft = curSum;
                    iLeft = q;
                }
            }

            ll bestRight = abs(a[n]-a[p]);
            ll iRight = (a[n] - a[p] > 0 ? n : p); // ?
            
            l(q, p+1, n)
            {
                ll curSum = (a[q] - a[p]) - (a[n] - a[q]);
                if (curSum > bestRight)
                {
                    bestRight = curSum;
                    iRight = q;
                }
            }

            if (bestLeft + bestRight > record)
            {
                record = bestLeft + bestRight;
                i1 = iLeft;
                i2 = p;
                i3 = iRight;
            }
        } 
    }
    

    

    // cout << record << endl;
    cout << i1 << " " << i2 << " " << i3 << endl;
}