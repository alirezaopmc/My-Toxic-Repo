#include <iostream>
using namespace std;

void test();

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        test();
        cout << '\n';
    }
}

void test() {
    string s;
    cin >> s;

    int n = s.size();
    int a[n];

    for(int i = 0; i < n; ++i) a[i] = s[i] - 'a';

    int ans = 0;
    int cng = 0;

    for(int i = 1; i < n-1; ++i) {
        if (cng == 2) {
            cng = 0;
            continue;
        }
        if (
            (i-1 >= 0 && a[i] == a[i-1]) ||
            (i-2 >= 0 && a[i] == a[i-2]) ||
            (i+1 <  n && a[i] == a[i+1]) ||
            (i+2 <  n && a[i] == a[i+2])
        ) {
            ans++;
            cng++;
        } else {
            cng = 0;
        }

        while(
            (i-1 >= 0 && a[i] == a[i-1]) ||
            (i-2 >= 0 && a[i] == a[i-2]) ||
            (i+1 <  n && a[i] == a[i+1]) ||
            (i+2 <  n && a[i] == a[i+2])
        ) a[i] = (a[i] + 1) % 26;
        
        
    }
    
    // for(int i = 0; i < n; ++i) cout << (char)('a' + a[i]);
    // cout << endl;
    cout << ans;
}