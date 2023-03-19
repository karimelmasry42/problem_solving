#include <stdio.h>
int main() {
  int n, sum = 0, term = 0;
  printf("Enter n: ");
  scanf("%d", &n);
  while (n--)
    sum += term = term * 10 + 1;
  printf("The sum is : %d", sum);
  return 0;
}