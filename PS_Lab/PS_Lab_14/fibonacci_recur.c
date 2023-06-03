// Fibonacci recursive
#include <stdio.h>
int fib_recur(int n) {
  if (n <= 1)
    return n;
  return fib_recur(n - 1) + fib_recur(n - 2);
}
int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", fib_recur(n));
  return 0;
}