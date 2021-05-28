#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int ans[1501];
    int familly[1500];
    int cnt[501];

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        for(int i = 0; i <= n; i++) ans[i] = 2e9;

        ans[0] = 0;

        for(int i = 0; i < n; i++)
            cin >> familly[i];

        int argz = 0;
        for(int i = 0; i < n-1; i++) {
            argz += cnt[familly[i]];
            cnt[familly[i]]++;
        }

        for(int i = 0; i < n; i++) {
            for(int i = 1; i <= 500; i++) {
                cnt[i] = 0;
            }
            int args = 0;
            for(int j = 1; j <= n-i; j++) {
                args += cnt[ familly[i + j - 1] ]++;
                ans[i + j] = min(ans[i + j], ans[i] + args + k);
            }
        }

        cout << ans[n] << endl;
    }
}