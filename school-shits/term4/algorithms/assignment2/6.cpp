/*
There are two algorithms called Algl and Alg2
for a problem of size n. Alg 1 runs in n^2 microseconds
and A1g2 runs in 100n log n microseconds. Alg 1 can
be implemented using 4 hours of programmer time and
needs 2 minutes of CPU time. On the other hand, Alg2
requires 15 hours of programmer time and 6 minutes of
CPU time. If programmers are paid 20 dollars per hour
and CPU time costs 50 dollars per minute, how many
times must a problem instance of size 500 be solved
using Alg2 in order to justify its development cost? 
*/

/*
Alg1:
    n^2 = 500^2 = 2500 microseconds
    4h development
    2 mins

    Income for one instance: 4 * 20 = 80

Alg2:
    100n log n = 100000 log 5 microseconds
    15h development
    6 mins

    Income for one instance: 15 * 20 = 300
    Then we have:
        300 = 50 * t => t = 6 minutes
        6 minutes = instances * 100k log 5
        => instances = 6 * 60 * 10^6 / 10^5 log 5
            = 3600 / log 5 ~ 5150
