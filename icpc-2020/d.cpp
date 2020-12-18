#include <iostream>
#include <vector>
#include <set>
// #include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> v(n);
    for(int i = 0; i < n; ++i) v[i] = s[i] - '0';

    sort(v.begin(), v.end());

    multiset<int> st;
    for(int i = 0; i < k; ++i) st.insert(v[i]);

    for(int i = 0; i < n; i++)
    {
        int x = s[i] - '0';
        if (st.find(x) != st.end())
        {
            st.erase(st.find(x));
        }
        else
        {
            cout << s[i];
        }
    }
}