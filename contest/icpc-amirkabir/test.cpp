#include <iostream>
using namespace std;

const int N=100*1000+100;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	if (n < 38) {
		cout << "no fever";
	} else {
		cout << "fever";
	}
    
}