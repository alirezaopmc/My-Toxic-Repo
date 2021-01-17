#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        if (i % m == 0) cout << (1 << i); // bit-wise shift 1000
        else {
            for(int j=0; j<i+1; j++) {
                // 20 * 20 => tebghe tarifi ke khode soal behet dade
                // function ( k az n ) = n! / (k! * (n-k)!)
                // cout << j az i << " ";
            }
            cout << endl;
        }
    }
}