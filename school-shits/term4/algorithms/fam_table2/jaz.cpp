#include <iostream>
#include <set>

using namespace std;

const int INF = 1e9;

int dp[1500+1];
int fam[1500+1];
int w[1500+1];
int cnt[1500+1];

int total = 0;
int test;
int n, k, g;

int cost(int l, int r) {
    printf("l,r = %d, %d\n", l, r);
    set<int> st;
    int result = 0;

    bool zowj = false;
    int zowj_num = -1;
    bool fard = false;
    int fard_num = -1;

    for(int i = l; i <= r; i++) {


        // fard ha baham ya zowj ha bahham nashan
        if (cnt[fam[i] - 1] % 2 == 0) {
            if (zowj && fam[i] != zowj_num) {
                cout << "ZOWJ" << endl;
                return INF;
            }
            zowj_num = fam[i];
            zowj = true;
        } else {
            if (fard && fam[i] != fard_num) {
                cout << "FARD" << endl;
                return INF;
            }
            fard_num = fam[i];
            fard = true;
        }

        if (st.find(fam[i]) != st.end()) {
            // if exists
            return INF;
        } else {
            st.insert(fam[i]);
            result += w[fam[i] - 1];
        }
    }

    printf("st size = %d\n", st.size());

    if (result > total / 2) {
        cout << "GHOL" << endl;
        return INF;
    } else {
        cout << result + k << endl;
        return result + k;
    }
}

int main() {
    cin >> test;

    for(int t = 0; t < test; t++) {
        total = 0; //total gholdori

        cin >> n >> k >> g;

        for(int i = 0; i <= n; i++) {
            dp[i] = INF;
        }

        dp[0] = 0;

        for(int i = 0; i < n; i++) {
            cin >> fam[i];
        }

        for(int i = 0; i < g; i++) {
            cin >> w[i];
        }

        for(int i = 0; i < n; i++) {
            total += w[ fam[i] - 1 ];
        }

        for(int i = 0; i < n; i++) {
            cnt[i] = 0;
        }

        for(int i = 0; i < n; i++) {
            cnt[fam[i]-1]++;;
        }
        
        for(int start = 0; start < n; start++) {
            for(int end = start+1; end <= n; end++) {
                int the_cost = cost(start, end-1);
                if (the_cost == INF) break;
                if (dp[end] > the_cost + dp[start]) {
                    dp[end] = the_cost + dp[start];
                }
            }
        }

        cout << dp[n] << endl;
    }
}