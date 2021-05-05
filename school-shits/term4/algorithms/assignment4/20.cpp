/*

Suppose we have:
    z [d x d] matrices
    x [d x 1] matrices
    y [1 x d] matrices
    t [1 x 1] matrices

Let all of these parameters be positive for skipping bad cases.
But the condition for problem trueness is that abs(x-y) = 1
We prove it at the end (*2)

(*1) Note that [d x d] and [1 x 1] can not be merged with no help of using [d x 1]
and [1 x d] matrices. So for ending the merging process we need to merge these
matrices.

We are forces to multiply all [d x d] matrices with one of [d x 1] or [1 x d].
So after merging these is no [d x d] left because:
    merging [d x d] with [d x 1] will result a [d x 1] matrix
    merging [1 x d] with [d x d] will result a [1 x d] matrix
Same for [1 x 1]:
    merging [1 x 1] with [1 x d] will result a [1 x d] matrix
    merging [d x 1] with [1 x 1] will result a [d x 1] matrix

After this forced move all [d x d] and [1 x 1] matrices are gone.

So the problem is smaller now.

We have x [d x 1] matrices and y [1 x d] matrices. And the main problem so on...

Now we have two possible moves:
     I. Merging [d x 1] with [1 x d] => Result: [d x d]
    II. Merging [1 x d] with [d x 1] => Result: [1 x 1]

As we said in (*1) we can not merge [d x d] with [1 x 1] so we are forced to
merge them with other matrices. So after using move I or II we may revert the
moves.

As bonus we can merge [1 x 1] matrices with themselves to minimize the cost.

Consider matrix multiplication of [p x q] and [q x r] will cost pqr actions.

So it's better to use the move II to minimize the cost.

Let m = min(x, y) and M = max(x, y)

The time complexity:
    T(z, x, y, t) =
        z * (d ^ 2): Multipling [d x d] with [d x 1] or [1 x d]
        + (t - 1) + m: Multipling all [1 x 1] with themselves

(*2) After all processes these will be left M - m matrix from same type ([d x 1] or [1 x d])
Note that if M - m > 1 the multiplication can not be continued. So it must be equal to 1.

Done.


*/