// https://codeforces.com/problemsets/acmsguru/problem/99999/179

#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    int bestI = -1;
    int bestCnt = 0;

    int n = s.size();

    for(int i = 0; i < n; ++i) {
        if (s[i] == '(' && cnt > 0) {
            bestI = i;
            bestCnt = cnt;
        }

        cnt += (s[i] == '(' ? +1 : -1);
    }

    if (bestI == -1) {
        cout << "No solution";
        return 0;
    }

    for(int i = 0; i < bestI; ++i) {
        cout << s[i];
    }

    cout << ')';

    for(int i = 0; i < n - bestI - bestCnt; ++i) {
        cout << ")("[i < (n - bestI - bestCnt) / 2];
    }

    for (int i = 0; i < bestCnt-1; ++i)
    {
        cout << ')';
    }
    
}