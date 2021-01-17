#include <iostream>

int main()
{
    int n, d;
    std::cin >> n >> d;

    int a[n];
    for(int i = 0; i < n; ++i)
        std::cin >> a[i];

    d %= n;
    for (int i = 0; i < n; i++)
        std::cout << a[ (i+d) % n ] << ",\n"[i == n-1];
}