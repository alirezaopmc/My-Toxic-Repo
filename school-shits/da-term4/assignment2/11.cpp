/*
What is the time complexity T(n) of the nested loops
below?

for (i = 1; i <= n; i++) {
    j = n
    while(j >= 1) {
        ??? => Theta(1)

        j = [j / 2]
    }
}
*/

/*
T(n) = (1 + ln n) + (1 + ln n-1) + ... + (1 + ln 1)
    = n + ln n!
*/