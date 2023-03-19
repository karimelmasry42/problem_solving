#include <math.h>
#include <stdio.h>

/*
 * Karim Ossama 221005999
 * Codeforces Problem 2
 * Theatre Square
 */

int main() {
  int n, m, a, count_n, count_m, stones;
  // get n, m, a
  scanf(" %d %d %d", &n, &m, &a);

  // calculate number of flagstones
  while (1)
    if ((1 <= n && n <= 109) && (1 <= m && m <= 109) && (1 <= a && a <= 109)) {
      count_n = ceil((double)n / a);
      count_m = ceil((double)m / a);
      stones = count_n * count_m;
      break;
    } else {
      printf("Invalid input\n");
      continue;
    }

  // print number of flagstones
  printf("%d", stones);

  return 0;
}