#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  int n1, n2;
  int power = pow(n1, n2);
  printf("Enter two numbers\n");
  scanf("%d %d", &n1, &n2);
  printf("The sum is %d\n", n1 + n2);
  printf("The product is %d\n", n1 * n2);
  printf("The difference is %d\n", abs(n1 - n2));
  printf("The quotient is %d\n", n1 / n2);
  printf("The remainmder is %d\n", n1 % n2);
  printf("The power is %.0f\n", pow((double)n1, (double)n2));
  return 0;
}