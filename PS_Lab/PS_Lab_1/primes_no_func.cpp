#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int x;
    bool sum_of_primes = false, i_prime = true, j_prime = true;

    printf("Enter an integer: ");
    scanf("%d", &x);
    for (int i = 2, j = x - 2; i <= j; i++, j--)
    {
        i_prime = true;
        j_prime = true;
        for (int k = 2; k < i; k++)
            if ((i % k) == 0)
            {
                i_prime = false;
                break;
            }
        for (int k = 2; k < j; k++)
            if ((j % k) == 0)
            {
                j_prime = false;
                break;
            }
        if (i_prime && j_prime)
        {
            printf("%d is the sum of two primes: %d and %d\n", x, i, j);
            sum_of_primes = true;
        }
    }
    if (!sum_of_primes)
        printf("%d is not a sum of two primes\n", x);
    return 0;
}