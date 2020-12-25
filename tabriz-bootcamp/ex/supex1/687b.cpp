#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 1e6;
ll lcm = 1;

int gcd(int a, int b)
{
    while(b) {
        a %= b;
        swap(a, b);
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        lcm = (lcm * x) / gcd(lcm, x);
    }
    
    if(lcm % k == 0)
        cout << "Yes\n";
    else
        cout << "No\n";

    

}