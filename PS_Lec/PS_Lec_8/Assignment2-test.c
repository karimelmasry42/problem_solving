#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
  float x = 13.33;
  float y = floor(x * 10 + .5) / 10;
  printf("%f\n", y);
  return 0;
}