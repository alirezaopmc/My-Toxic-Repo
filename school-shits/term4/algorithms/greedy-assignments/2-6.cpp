/* Answer to problem 2

Finding the minimum key
0 0 0 0 0 0 0 0 0 0
Minimum key found: 0
Mark 0
mat[0][1] < k[1]
mat[0][3] < k[3]
Finding the minimum key
1 0 0 0 0 0 0 0 0 0
Minimum key found: 3
Mark 3
mat[3][2] < k[2]
mat[3][4] < k[4]
mat[3][7] < k[7]
Finding the minimum key
1 0 0 1 0 0 0 0 0 0
Minimum key found: 7
Mark 7
mat[7][6] < k[6]
mat[7][8] < k[8]
Finding the minimum key
1 0 0 1 0 0 0 1 0 0
Minimum key found: 8
Mark 8
mat[8][9] < k[9]
Finding the minimum key
1 0 0 1 0 0 0 1 1 0
Minimum key found: 9
Mark 9
mat[9][5] < k[5]
Finding the minimum key
1 0 0 1 0 0 0 1 1 1
Minimum key found: 5
Mark 5
Finding the minimum key
1 0 0 1 0 1 0 1 1 1
Minimum key found: 2
Mark 2
mat[2][6] < k[6]
Finding the minimum key
1 0 1 1 0 1 0 1 1 1
Minimum key found: 6
Mark 6
Finding the minimum key
1 0 1 1 0 1 1 1 1 1
Minimum key found: 4
Mark 4
118
*/

/*
Answer to the problem 6 at line 138
*/


#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define range(i, n) for(int i=0; i<n; i++)

typedef vector<int> Array;
typedef vector<bool> Barry;
typedef vector<float> Farry;
typedef vector<double> Darry;
typedef vector<Array> Matrix;
typedef long long ll;

int mpst(Matrix mat);
int find_min(Array arr, Barry flags);

void connect(Matrix& mat, int i, int j, int w) { mat[i][j] = mat[j][i] = w; }

int main() {
    int n = 10;

    Matrix mat(n, Array(n));

    connect(mat, 0, 1, 32);
    connect(mat, 0, 3, 17);
    connect(mat, 1, 5, 45);
    connect(mat, 2, 3, 18);
    connect(mat, 2, 6, 5);
    connect(mat, 3, 4, 20);
    connect(mat, 3, 7, 4);
    connect(mat, 4, 5, 28);
    connect(mat, 4, 8, 25);
    connect(mat, 5, 9, 6);
    connect(mat, 6, 7, 59);
    connect(mat, 7, 8, 4);
    connect(mat, 8, 9, 12);

    cout << mpst(mat) << endl;
}

int mpst(Matrix mat) {
    int n = mat.size();

    Array p(n);
    Array k(n);
    Barry f(n);

    fill(k.begin(), k.end(), INT32_MAX);
    fill(f.begin(), f.end(), false);

    k[0] = 0;
    p[0] = -1;

    range(i, n-1) {
        cout << "Finding the minimum key" << endl;
        for(int j = 0; j < n; j++) cout << f[j] << " "; cout << endl;

        int u = find_min(k, f);
        f[u] = true;
        cout << "Minimum key found: " << u << endl;
        cout << "Mark " << u << endl;

        range(v, n) {
            if (mat[u][v] &&
                f[v] == false &&
                mat[u][v] < k[v]) {
                cout << "mat[" << u << "][" << v << "] < k[" << v << "]" << endl;
                p[v] = u;
                k[v] = mat[u][v];
            }
        }
    }

    ll result = 0;
    range(i, n-1) {
        // cout << p[i+1] << " " << i+1 << endl;
        result += mat[i+1][ p[i+1] ];
    }

    // Problem 6
    /*
        If the graph is not connected then at least one of the p[i] (parent) is not the same
        We can check find_parent(i) for all i and check if some differences happen
        We can also use compression for optimizing
        pseudo code:

        def find_parent(i):
            if p[i] == -1: return i
            else: return p[i] = find_parent(p[i])

        Like DSU Path Compression
    */

    return result;
}

int find_min(Array arr, Barry flags) {
    int index = 0;
    int minimum = INT32_MAX;

    range(i, arr.size()) {
        if (flags[i] == false && arr[i] < minimum) {
            minimum = arr[i];
            index = i;
        }
    }

    return index;
}
