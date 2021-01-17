#include <iostream>

using namespace std;

const int N = 2;
const int MOD = 1e9 + 7;

typedef long long ll;
typedef int Mat[N][N];

inline int sum(int a, int b) {
    ll c = a + b;
    if (c >= MOD) {
        return c - MOD;
    }
    return c;
}

inline int mul(int a, int b) {
    return 1ll * a * b % MOD;
}

void mul(Mat a, Mat b, Mat c) {
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            c[i][j] = 0;
     
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            for(int k = 0; k < N; ++k)
                c[i][j] += a[i][j] * b[j][k];
}

Mat X, F, T, R;
int n, k, l, m;

int main() {
    cin >> n >> k >> l >> m;

    if (k >= (1<<l)) {
        cout << 0 << endl;
    } else
    {
        F[0][0] = 1;
        F[1][0] = 2;

        X[0][0] = 0;
        X[0][1] = 1;
        X[1][0] = 1;
        X[1][1] = 1;    /* code */
    
        R[0][0] = R[1][1] = 1;

        for(; n; n >>= 1) {
            if (n & 1) {
                mul(R, X, T);
                swap(T, R);
            }
            mul(X, X, T);
            swap(T, X);
        }
    }
    

    for(; b ; b >>= 1) {

    }
}