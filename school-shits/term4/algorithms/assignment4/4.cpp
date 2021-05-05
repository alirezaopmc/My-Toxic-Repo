#include <iostream>

using namespace std;

class binomial_coefficients
{
private:
    int maxN;
    int size;
    int *dp;
public:
    binomial_coefficients(int maxN) : maxN(maxN) { init(); }
    void init();
    int get(int n, int k);
    void set(int n, int k, int value);
    void show();
};

void binomial_coefficients::init()
{
    size = maxN * (maxN + 1) / 2;
    dp = new int[size];

    for(int i = 0; i < maxN; i++) {
        for(int j = 0; j <= i; j++) {
            if (i == 0 || j == 0 || i == j) {
                set(i, j, 1);
            } else if (i == 1 || j == 1) {
                set(i, j, i+j-1);
            } else {
                set(i, j, get(i-1, j-1) + get(i-1, j));
            }
        }
    }
}

int binomial_coefficients::get(int n, int k)
{
    int index = n * (n + 1) / 2 + k;
    return dp[index];
}

void binomial_coefficients::set(int n, int k, int value)
{
    int index = n * (n + 1) / 2 + k;
    dp[index] = value;
}

void binomial_coefficients::show()
{
    for(int i = 0; i < maxN; i++) {
        for(int j = 0; j <= i; j++) {
            cout << get(i, j) << " ";
        }
        cout << endl;
    }
}


int main() {
    int n;
    cout << "Enter the maximum number of n in queries C(n, k).\n";
    cin >> n;
    binomial_coefficients bc(3);

    cout << "The Pascal triangle.";
    bc.show();
}