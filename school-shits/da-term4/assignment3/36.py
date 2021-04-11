"""

we use strassen's approach so:
if n >= t:
    F(n) = { T(n) = 7T(n/2) + 18T(n/2)^2 }
else:
    F(n) = n^3 microseconds

let them equal (we solved strassen's in class)

t^3 = 7(t/2)^3 + 18(t/2)^6 + 12t^6 ====> t = root_3(1/168)


These limits make the algorithm faster for small input size
however the faster method is faster for large inputs.
So we can use faster method (strassen's) for all cases,
because small inputs can be solved fast any way.

"""