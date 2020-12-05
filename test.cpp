#include <iostream>
#include <cstring>

using namespace std;

int main ()
{
    int cnt[10];
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;

    while(n) {
        cnt[n % 10]++;
        n /= 10;
    }

    for(int i = 0; i < 10; i++) {
        cout << i << ": " << cnt[i] << endl;
    }
}