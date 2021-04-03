/*
Show that the function f(n) = |n^2 sin n|
is in neither O(n) nor Omega(n).
*/

/*
For enough large n, we have to prove
n^2 |sin n| > n <=> n |sin n| > 1
    <=> |sin n| > 1 / n
    RHS is almost equal to zero
    but LHS is surely more than RHS
    suppose it's smaller than 1 / n
    add one to the n then |sin n|
    will grow a bit.
*/