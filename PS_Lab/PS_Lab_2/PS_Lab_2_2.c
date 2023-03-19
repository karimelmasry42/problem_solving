#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
  double square, cube;
  for (double i = 0; i <= 10; i++) {
    square = pow(i, 2.0);
    cube = pow(i, 3.0);
    printf("%2.0f^2 = %6.0f \t %2.0f^3 = %6.0f\n", i, square, i, cube);
  }
  return 0;
}