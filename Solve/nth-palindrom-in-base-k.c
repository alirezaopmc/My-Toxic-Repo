#include <stdio.h>
#include <math.h>

int is_prime(int n);
int palindrome(int n, int b);
int digits (int n, int b);
int fast_pow (int a, int b);

int main()
{
    int n, b;
    scanf("%d %d", &n, &b);

    int c = 0;

    if (palindrome(2, b)) c++;

    if (c == n)
    {
        printf("%d", 2);
        return 0;
    }

    if (palindrome(3, b)) c++;

    if (c == n)
    {
        printf("%d", 3);
        return 0;
    }
    
    for (int i = 5; i <= 5000000; i += 6)
    {
        if (is_prime(i) && palindrome(i, b)) c++;

        if (c == n)
        {
            printf("%d", i);
            return 0;
        }
        
        if (is_prime(i+2) && palindrome(i+2, b)) c++;

        if (c == n)
        {
            printf("%d", i+2);
            return 0;
        }
    }
}

int is_prime (int n)
{
    if (n == 2) return 1;
    if (n == 3) return 1;
    if (n == 4) return 0;
    if (n == 5) return 1;
    
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return 0;

    for (int i = 5; i <= sqrt(n) + 1; i += 6)
    {
        if (n % i == 0 || n % (i+2) == 0) return 0;
    }

    return 1;
}

int palindrome (int n, int b)
    {
        int d = digits(n, b);
        int p = fast_pow(b, d-1);

        int tmp = n;

        while (n > 0 && d > 0)
        {

            if (n % b != (tmp / p) % b && d != 1)
            {
                return 0;
            }

            n /= b;
            p /= b;
            d -= 2;
        }

        return 1;
    }

int digits (int n, int b)
{
    int result = 0;

    while (n)
    {
        result++;
        n /= b;
    }
    
    return result;
}

int fast_pow (int a , int b)
{
    int result = 1;

    while(b)
    {
        if (b & 1) result *= a;
        a *= a;
        b >>= 1;
    }

    return result;
}
