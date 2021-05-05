Alireza Jafartash
9831120290
Problem 1 - Final

1. My Solution

Heap H = new Heap()
H[0] = INT_MIN // Minus Infinity

int MapA = new Array(A.size())
int MapB = new Array(B.size())

MapA[0] = 1
MapB[0] = 2

for(int i = 1; i < A.size(); i++) {
    if (i % 2 == 1) {
        MapA[i] = MapA[i/2] + 1;
    } else {
        MapA[i] = MapA[i/2] + 2;
    }
}

for(int i = 1; i < B.size(); i++) {
    if (i % 2 == 1) {
        MapB[i] = MapB[i/2] + 1;
    } else {
        MapB[i] = MapB[i/2] + 2;
    }
}

2. Correct Solution

Heap H = new Heap()
H[0] = INT_MIN // Minus Infinity

int MapA = new Array(A.size())
int MapB = new Array(B.size())

MapA[0] = 1
MapB[0] = 2

for(int i = 1; i < A.size(); i++) {
    if (i % 2 == 1) {
        MapA[i] = 2 * MapA[(i-1)/2] + 1;
    } else {
        MapA[i] = 2 *  MapA[(i-1)/2] + 2;
    }
}

for(int i = 1; i < B.size(); i++) {
    if (i % 2 == 1) {
        MapB[i] = MapB[(i-1)/2] + 1;
    } else {
        MapB[i] = MapB[(i-1)/2] + 2;
    }
}

// 100% Working you can check the attached files