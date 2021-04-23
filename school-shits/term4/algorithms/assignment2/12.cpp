/*
What is the time complexity T(N) of the nested loops
below?

i = n
while (i >= 1) {
    j = i
    while (j <= n) {
        ??? => Theta(1)

        j *= 2
    }

    i = [i / 2]
}
*/

/*
T(N) = 1 + 2 + ... + ln n = (ln n)(ln n + 1) / 2
*/