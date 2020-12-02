#include <iostream>

using namespace std;

int main ()
{
    bool flag = true;

    for (int i = 0; i < 100 && flag; i++) {
        for(int j = 0; j < 100 && flag; j++) {
            cout << i << " " << j << endl;
            if (i == 31 && j == 2) flag = false;
        }
    }
}