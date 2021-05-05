/*

Sum { i in (1,n-1) } [ (n-i) * i ]
    = Sum { i in (1,n-1) } [ n * i ]
    - Sum { i in (1,n-1) } [ i * i ]

    = n * Sum { i in (1,n-1) } [ i ]
    - Sum { i in (1,n-1) } [ i * i ]

    = (n-1) * (n) / 2
    - (n-1) * (n) * (2n - 1) / 6

    = (n / 6) * (3n^2 - 3n - 2n^2 + 3n - 1)
    = (n / 6) * (n^2 - 1)
    = n(n-1)(n+1) / 6. Done

*/