// cnt = 

// for _ in range(int(input())):
//     n, k = map(int, input().split())
//     f = list(map(int, input().split()))

//     dp = [0] * n

//     dp[0] = k

//     for i in range(n-1):
//         for p in range(1, n-i-1):
            

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const bool debug = false;

const int N = 1500;
const int M = 500;

#define DEBUG( x ) if(debug) { x; }

int ans[N+1];
int f[N];
int cnt[M];

void test();
void erase(int* arr, int n, int value = 0) { for(int i = 0; i < n; i++) arr[i] = value; }

int main() {
    int t;
    cin >> t;

    while(t--) test();
}

void test() {
    int n, k;
    cin >> n >> k;

    erase(ans, n+1, INT32_MAX);
    erase(f, n);

    ans[0] = 0;

    for(int i = 0; i < n; i++) {
        cin >> f[i];
        f[i]--;
    }

    int argues = 0;
    for(int taken = 1; taken != n; taken++) {
        argues += cnt[ f[taken - 1] ]++;
    }

    for(int before = 0; before < n; before++) {
        erase(cnt, M);

        int c = 0; // argues up next

        for(int next = 1; next <= n-before; next++) {
            
            c += cnt[ f[before + next - 1] ]++;
            ans[before + next] = min(ans[before + next], ans[before] + c + k);

        }
    }

    cout << ans[n] << endl;
}