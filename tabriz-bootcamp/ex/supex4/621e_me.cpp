#include <iostream>

using namespace std;

const int X = 100;
const int D = 10;
const int N = 1e5;
const int MOD = 1e9 + 7;

typedef long long ll;

// Very imp
typedef int Mat[X][X];

inline int sum(int a, int b)
{
    ll c = a + b;
    if (c >= MOD)
        return c - MOD;
    return c;
}

inline int mul(int a, int b)
{
    return 1ll * a * b % MOD;
}

int n, b, k, x;


// It's a little tricky
// This function fill C it's lie (&c)
// Notice that Mat is a typedef
void mul(Mat a, Mat b, Mat c) {
    // We Reset c because we use it many times as buffer
    for (int i = 0; i < x; i++)
        for (int j = 0; j < x; j++)
            c[i][j] = 0;

    for (int i = 0; i < x; i++)
        for (int j = 0; j < x; j++)
            for(int k = 0; k < x; k++)
                c[i][k] = sum(c[i][k], mul(a[i][j], b[j][k]));
}

Mat A, R, T;
int cnt[D];

int main() {
    cin >> n >> b >> k >> x;

    // Get a
    // Digit count
    for(int i = 0; i < n; i++) {
        int d;
        cin >> d;
        cnt[d]++;
    }

    // Adj Matrix of states
    // A[p][q]: stands for the number of edges(ways) to reaach state j from state i
    // state s = (s module x)
    for(int i = 0; i < x; i++) {
        for(int d = 0; d < D; d++) {
            A[i][(10*i+d) % x] += cnt[d];
        }
    }

    // Creating an unit matrix to store the result in it => R
    for(int i = 0; i < x; i++)
        R[i][i] = 1;

    // A^b [i][j]: this is a matrix which stores the number of ways we can reach j from i with b steps
    for(; b; b >>= 1) {
        // We use T as a buffer
        if(b & 1) {
            // We can't use mul(A, R, T) because they change rapidly during the mul function
            mul(A, R, T);
            
            // Swap function changes the pointer of its two parametr, so it's so efficient
            swap(T, R);
        }
        mul(A, A, T);
        swap(A, T);
    }

    cout << R[0][k];
}

