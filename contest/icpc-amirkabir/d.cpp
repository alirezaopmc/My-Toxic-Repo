#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define l(i,s,n) for(int i=s; i<n; i++)
#define ll long long

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
    cin >> n >> k;
    
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> a(n-2);
    for(int i=0; i<n; i++) cin >> x[i] >> y[i];
    for(int i=0; i<n; i++) cout << x[i] << " " << y[i] << endl;

    for(int i=0; i<n-2; i++)
    {
        ll x1 = x[i];
        ll y1 = y[i];
        ll x2 = x[i+1];
        ll y2 = y[i+1];
        ll x3 = x[i+2];
        ll y3 = y[i+2];

        ll area = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);

        a[i] = abs(area);
        // cout << area << endl;
    }

    sort(a.begin(), a.end());

    printf("%.9f", (float)a[k-1] / 2);
}