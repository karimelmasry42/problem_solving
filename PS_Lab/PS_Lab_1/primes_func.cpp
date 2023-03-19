#include <stdio.h>
#include <iostream>
using namespace std;
bool is_prime(int n)
{
    /*returns 1 if n is prime
    returns 0 if n is not prime */
    for (int i = 2; i < n; i++)
        if ((n % i) == 0)
            return false;
    return true;
}
int main()
{
    int x;
    bool sum_of_primes = false;
    printf("Enter an integer: ");
    scanf("%d", &x);
    for (int i = 2, j = x - 2; i <= j; i++, j--)
    {
        if (is_prime(i) && is_prime(j))
        {
            printf("%d is the sum of two primes: %d and %d\n", x, i, j);
            sum_of_primes = true;
        }
    }
    if (!sum_of_primes)
        printf("%d is not a sum of two primes\n", x);
    return 0;
}