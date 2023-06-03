#include <stdio.h>
struct fraction {
  int n, d;
};
struct fraction sum_frac(struct fraction a, struct fraction b) {
  struct fraction s;
  if (a.d != b.d) {
    s.n = (a.n * b.d) + (b.n * a.d);
    s.d = a.d * b.d;
  } else {
    s.n = a.n + b.n;
    s.d = a.d;
  }
  return s;
}
int main() {
  struct fraction a, b, s;
  puts("Enter two fractions a/b");
  scanf("%d/%d %d/%d", &a.n, &a.d, &b.n, &b.d);
  s = sum_frac(a, b);
  printf("sum = %d/%d\n", s.n, s.d);
  return 0;
}
