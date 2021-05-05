#include <iostream>
#include <string>

using namespace std;

const int INF = INT32_MAX;
bool debug_mode = true;

#define __DEBUG__(x) if (debug_mode) { x; }

class floyd
{
private:
    int v;
    int **A;
    int **D;
    int **P;
public:
    floyd(int v) : v(v) { init(); }
    void init();
    void connect(int i, int j, int weight);
    void fill();
    void run();
    bool is_valid(int i, int j) { return D[i][j] != INF; }
    int min_path(int i, int j) { return D[i][j]; };
    void show_path(int i, int j);
    void debug();
};

void floyd::init()
{
    A = (int **) malloc(v * sizeof(int *));
    D = (int **) malloc(v * sizeof(int *));
    P = (int **) malloc(v * sizeof(int *));

    for(int i = 0; i < v; i++) {
        A[i] = (int *) malloc(v * sizeof(int));

        for(int j = 0; j < v; j++)
            A[i][j] = INF;

        D[i] = (int *) malloc(v * sizeof(int));
        P[i] = (int *) malloc(v * sizeof(int));
    }
}

void floyd::connect(int i, int j, int weight) {
    __DEBUG__(
        printf("[!] Adding edge between %d and %d with weight %d\n", i, j, weight);
    )
    A[i][j] = weight;
    P[i][j] = i;
}

void floyd::fill() {
    __DEBUG__(
        printf("\t[!] Filling matrices D and P.\n");
    )
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            D[i][j] = A[i][j];

            if (i == j) {
                P[i][j] = 0;
            } else if (is_valid(i, j)) {
                P[i][j] = i;
            } else {
                P[i][j] = -1;
            }
        }
    }
}

void floyd::run() {
    __DEBUG__(
        printf("[!] Running the floyd algorithm...\n");
    )

    fill();

    __DEBUG__(
        printf("The main loop started:")
    )

    for(int k = 0; k < v; k++) {
        __DEBUG__(
            printf("\t+ k=%d\n", k);
        )

        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                __DEBUG__(
                    printf("\t\t * i=%d, j=%d:\n", i, j);
                )

                if (k == i || k == j) {
                    __DEBUG__(
                        printf("\t\t[!] k is equal to i either j. Skipping...\n");
                    )
                    continue;
                }
                if (is_valid(i, k) && is_valid(k, j) && D[i][k] + D[k][j] < D[i][j]) {
                    __DEBUG__(
                        printf("\t\t[#] Found a better path! :)\n");
                        printf("\t\tUpdating...\n");
                        printf("\t\tP[i][j] = P[k][j]\n");
                        printf("\t\tD[i][j] = D[i][k] + D[k][j]\n");
                    )
                    P[i][j] = P[k][j];
                    D[i][j] = D[i][k] + D[k][j];
                }
            }

            if (D[i][i] < 0) {
                cout << "Negative-weight cycle found!" << endl;
                return;
            }
        }
    }
}

void floyd::show_path(int i, int j) {
    __DEBUG__(
        printf("Showing path from %d to %d\n", i, j);
    )
    if (is_valid(i, j)) {
        if (P[i][j] == i) {
            __DEBUG__(
                printf("Reached end-point.\n");
            )
            cout << i << " " << j << " ";
            return;
        }

        __DEBUG__(
            printf("Calling recursively show_path(i, P[i][j]).\n");
        )

        show_path(i, P[i][j]);
        cout << j << " ";
        // cout << P[i][j] << " ";
    } else {
        cout << "These is no path." << endl;
    }
}

void floyd::debug() {
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            cout << P[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }

    
}


int main() {
    cout << "Debug mode? (y/n) ";
    string debug_input;
    cin >> debug_input;
    debug_mode = (debug_input == "y" ? true : debug_mode);
    debug_mode = (debug_input == "n" ? false : debug_mode);

    const int v = 7;
    
    floyd f(7);

    f.connect(0, 1, 4);
    f.connect(0, 5, 10);
    f.connect(1, 0, 3);
    f.connect(1, 3, 18);
    f.connect(2, 1, 6);
    f.connect(3, 1, 5);
    f.connect(3, 2, 15);
    f.connect(3, 4, 2);
    f.connect(3, 6, 5);
    f.connect(3, 5, 19);
    f.connect(4, 2, 12);
    f.connect(4, 3, 1);
    f.connect(5, 6, 10);
    f.connect(6, 3, 8);

    f.run();
    // f.debug();

    int x, y;
    cin >> x >> y;
    while(x != -1 && y != -1) {
        cout << f.min_path(x, y) << endl;
        f.show_path(x, y);
        cout << endl;

        cin >> x >> y;
    }
}