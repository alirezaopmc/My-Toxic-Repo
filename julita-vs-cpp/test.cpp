#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

int main() {
    auto start = high_resolution_clock::now();


    int s = 0;
    for(int i = 0; i < 100000; i++) {
        s++;
    }
    cout << s << endl;

    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
}