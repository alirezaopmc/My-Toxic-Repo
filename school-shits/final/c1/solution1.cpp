#include <iostream>
#include "./heap/heap.h"

using namespace std;

heap mix(heap& A, heap& B);

int main() {
    heap A, B;

    A.insert(7);
    A.insert(8);
    A.insert(1);
    A.insert(3);
    A.insert(2);

    B.insert(3);
    B.insert(1);
    B.insert(2);

    A.log();
    B.log();

    heap C = mix(A, B);
    C.extract();
    C.log();
}

heap mix(heap& A, heap& B) {
    heap C;
    C.resize(A.size() + B.size() + 1);
    C.set(0, INT32_MIN);
    
    vector<int> MapA(A.size());
    vector<int> MapB(B.size());

    MapA[0] = 1;
    MapB[0] = 2;

    for(int i = 1; i < A.size(); i++) {
        if (i % 2 == 1) {
            MapA[i] = 2 * MapA[(i-1)/2] + 1;
        } else {
            MapA[i] = 2 * MapA[(i-1)/2] + 2;
        }
    }
    

    for(int i = 1; i < B.size(); i++) {
        if (i % 2 == 1) {
            MapB[i] = 2 * MapB[(i-1)/2] + 1;
        } else {
            MapB[i] = 2 * MapB[(i-1)/2] + 2;
        }
    }

    for(int i = 0; i < A.size(); i++) {
        C.set(
            MapA[i],
            A.get(i)
        );
        // cout << "Set " << MapA[i] << " " << A.get(i) << endl;
    }

    for(int i = 0; i < B.size(); i++) {
        C.set(
            MapB[i],
            B.get(i)
        );
        // cout << "Set " << MapB[i] << " " << B.get(i) << endl;
    }

    return C;
}