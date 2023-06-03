/**
 * Karim O. Elmasry 2023-05-23
 * Recursive calculate power of a number
 */
#include <stdio.h>
double pow_iter(double n, int power) {
  if (power < 0)
    return -1;
  double ans = 1;
  for (int i = 0; i < power; i++) {
    ans *= n;
  }
  return ans;
}
double pow_recur(double n, int power) {
  if (power == 0)
    return 1;
  return n * pow_recur(n, power - 1);
}
int main() {
  double n;
  int power;
  puts("Enter n, power");
  scanf("%lf %d", &n, &power);
  printf("iter:  %lf\n", pow_iter(n, power));
  printf("recur: %lf\n", pow_recur(n, power));
  return 0;
}