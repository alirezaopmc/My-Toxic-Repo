#include <iostream>
#include <cstring>

using namespace std;

int main ()
{
    long long n;
    cin >> n;

    long long two = 1;
    while(two * 2 <= n) two *= 2;

    long long ans = 0;

    while(two) {
        if (two <= n) {
            ans++;
            n -= two;
        }
        two /= 2;
        ans *= 10;
    }

    ans /= 10;

    cout << ans;
}