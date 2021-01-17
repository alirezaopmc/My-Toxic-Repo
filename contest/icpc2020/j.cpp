#include <iostream>

using namespace std;

const int M = 1e5;
const int N = 2 * M +1;
int a[N];
int ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, d;
    cin >> n >> d;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;

        a[x+M] += 1;
    }
    
    for(int i=0; i<N; i++) {
        if(!a[i]) continue;
        ans += a[i]-1;
        int j = i+1;
        while (j < i+d) {
            ans += a[j++];
        }
        i = j-1;
    }

    cout << ans;
}