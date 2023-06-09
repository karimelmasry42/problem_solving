#include <math.h>
#include <stdio.h>

/**
 * Karim Ossama 221005999
 * Codeforces Problem 2
 * Theatre Square

Theatre Square in the capital city of Berland has a rectangular shape with the
size n × m meters. On the occasion of the city's anniversary, a decision was
taken to pave the Square with square granite flagstones. Each flagstone is of
the size a × a. What is the least number of flagstones needed to pave the
Square? It's allowed to cover the surface larger than the Theatre Square, but
the Square has to be covered. It's not allowed to break the flagstones. The
sides of flagstones should be parallel to the sides of the Square. Input: The
input contains three positive integer numbers in the first line: n, m and a
(1 ≤   n, m, a ≤ 109). Output: Write the needed number of flagstones.

****Example****
Input 6 6 4
 Output 4

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