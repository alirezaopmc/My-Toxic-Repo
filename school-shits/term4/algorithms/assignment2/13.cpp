/*
Give a Theta(n lg n) algorithm that computes the
remainder when x^n is divided by p.
*/

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100000;

int moduleExponential(int x, int n, int p);

int main() {
    int x, n, p;
    
    cin >> x >> n >> p;
    cout << moduleExponential(x, n, p);
}

int moduleExponential(int x, int n, int p) {
    if (n == 0) return 1;
    if (n == 1) return (x >= p ? x % p : x);

    int k = moduleExponential(x, n/2, p);
    int r = (n & 1 ? x : 1);

    int result = k * k * r;
    return (result >= p ? result % p : result);
}