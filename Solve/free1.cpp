bool TEST_CASE = true;

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

const int N=1e5+10;;
int a[N];

void solve(){
	int n,k;
	cin >> n >> k;
	l(i, 0, n) cin >> a[i];
	
	int ans=1e7;

	l(i,1,101)
    {
		int in=0;
		int res=0;
		while(in < n){
		
			while(in < n && a[in] == i) in++;
			
			
			if(in < n)
            {
				int t=0;
				res++;
				while(t < k && in < n){
					in++;
					t++;	
				}
			}	
		}
		ans = min(ans, res);	
	}
	cout<<ans;
}

int main(){
	int q=1;
	cin>>q;
	while(q--){
		solve();
		cout<<'\n';
	}
}
