#include <stdio.h>
int main()
{
    int x;
    int sum_of_primes = 0, i_prime = 1, j_prime = 1;

    printf("Enter an integer: ");
    scanf("%d", &x);
    for (int i = 2, j = x - 2; i <= j; i++, j--)
    {
        i_prime = 1;
        j_prime = 1;
        for (int k = 2; k < i; k++)
            if ((i % k) == 0)
            {
                i_prime = 0;
                break;
            }
        for (int k = 2; k < j; k++)
            if ((j % k) == 0)
            {
                j_prime = 0;
                break;
            }
        if (i_prime && j_prime)
        {
            printf("%d is the sum of two primes: %d and %d\n", x, i, j);
            sum_of_primes = 1;
        }
    }
    if (!sum_of_primes)
        printf("%d is not a sum of two primes\n", x);
    return 0;
}