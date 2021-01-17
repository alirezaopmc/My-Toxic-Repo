#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int N = 1e4;
int n;
int ind;
int ans[N];

void solve(bitset<N> b, string s);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    string s;
    cin >> s;

    bitset<N> b((1 << n) - 1);

    solve(b, s);

    for(int i = 0; i < ind; i++)
        cout << ans[i] << " \n"[i == ind-1];

    cout << "edn\n";
}

void solve(bitset<N> msk, string s)
{
    if (s.size() == 0) {
        int _i = 0;
        while(true) if(_i == N || msk[_i++]) {
            ans[ind++] = _i;
            break; 
        }
        return;
    }

    if (s.size() == 1) {
        int _i = 0;
        int _c = 0;
        int f[2];
        while(_c < 2) if (msk[_i++]) f[_c++] = _i;
        if(s[0] == '1') {
            ans[ind++] = f[0];
            ans[ind++] = f[1];
        } else {
            ans[ind++] = f[1];
            ans[ind++] = f[0];
        }
        return;
    }


    int t = msk.count();
    int a = t/2;
    int b = (t+1)/2;
    int tempStringLen = 0;

    int x = 0, y = 0;
    string A, B;
    for(int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] == '1')
        {
            A += '1';
            B += '0';
            a--;
        }
        else
        {
            A += '0';
            B += '1';
            b--;
        }
        
        if (!a) {
            while(b) {
                A += '0';
                B += '1';
                b--;
            }
            break;
        }

        if (!b) {
            while(a) {
                A += '1';
                B += '0';
                a--;
            }
            break;
        }

        tempStringLen++;
    }

    bitset<N> mskA(A);
    bitset<N> mskB(B);

    int bCount = mskB.count();
    int bFloor = bCount / 2;
    int bCeil = ++bCount / 2;

    string newString = s.substr(0, s.size() - tempStringLen);

    int ti = 0;
    for(int i = newString.size() - 1; i >= 0; --i)
    {
        if (s[i] == '1') bFloor--; else bCeil--;
        if (!bFloor || !bCeil) {
            ti = i;
            break;
        }
    }

    string stA = newString.substr(0, ti);
    string stB = newString.substr(ti, newString.size() - ti);

    solve(mskA, stA);
    solve(mskB, stB);
}