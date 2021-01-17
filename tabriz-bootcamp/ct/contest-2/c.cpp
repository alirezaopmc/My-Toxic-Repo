#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = .5e6;

int n;
int m[N];
int ans[N];

void ret(int s, int e);
bool isSorted(int s, int e);
ll solve(int s, int e);


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for(int i=0; i<n; ++i) cin >> m[i];

    int s = -1;
    int e = n;

    int mn = 1e9;
    for(int i=s+1; i<e; i++) mn = min(mn, m[i]);

    ll bestSum = 0;
    int bestI = s;
    int bestJ = e;
    
    int i = s;
    int j = s+1;
    for(; j <= e; ++j) {
        if (j == e || m[j] == mn) {
            ll tmp = solve(i, j);
            if (tmp > bestSum) {
                bestSum = tmp;
                bestI = i;
                bestJ = j;
            }
            i = j;
        }
    }

    for(int i=s+1; i<e; i++) ans[i] = mn;
    ret(bestI, bestJ);


    for(int i=s+1; i<e; i++) cout << ans[i] << " \n"[i==n];
}

void ret(int s, int e) {
    ll bestSum = 0;
    int bestI = s;
    int bestJ = e;

    if (e - s == 1) return;

    if (e - s == 2) {
        ans[s+1] = m[s+1];
        return;
    }

    if (isSorted(s, e)) {
        for(int i=s+1; i<e; i++) ans[i] = m[i];
        return;
    }

    int mn = 1e9;
    for(int i=s+1; i<e; i++) mn = min(mn, m[i]);
    
    int i=s;
    int j=s+1;
    for(; j <= e; ++j) {
        if (j == e || m[j] == mn) {
            ll tmp = solve(i, j);
            if (tmp > bestSum) {
                bestSum = tmp;
                bestI = i;
                bestJ = j;
            }
            i = j;
        }
    }

    for(int i=s+1; i<e; i++) ans[i] = mn;
    ret(bestI, bestJ);

}

bool isSorted(int s, int e) {
    bool flag = true;
    for(int i=s+1; i<e; i++) {
        if(i+1<e && m[i] > m[i+1]) {
            flag = false;
            break;
        }
    }

    if(flag) return true;
    flag = true;
    
    for(int i=s+1; i<e; i++) {
        if(i+1<e && m[i] < m[i+1]) {
            flag = false;
            break;
        }
    }

    if(flag) return true;

    return false;
}

ll solve(int s, int e) {
    if (e - s <= 1) return 0;

    if (e - s == 2) return m[s+1];

    if (isSorted(s, e)) {
        ll an = 0;
        for(int i=s+1; i<e; i++) an += m[i];
        return an;
    }

    int mn = 1e9;
    for(int i=s+1; i<e; i++) mn = min(mn, m[i]);

    ll bestSum = 0;
    int bestI = s;
    int bestJ = e;
    
    int i = s;
    int j = s+1;
    for(; j <= e; ++j) {
        if (j == e || m[j] == mn) {
            ll tmp = solve(i, j);
            if (tmp > bestSum) {
                bestSum = tmp;
                bestI = i;
                bestJ = j;
            }
            i = j;
        }
    }

    return (e - s + bestI - bestJ) * mn + bestSum;
}