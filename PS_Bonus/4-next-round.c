/**
 * Karim Elmasry 2023-05-20
 * Codeforces Problem 4
 * Next Round
 */
#include <stdio.h>
#include <stdlib.h>
int main() {
  int n, k, a[50], min_score, adv;
  scanf("%d %d", &n, &k);
  if (n < k) {
    printf("invalid input\n");
    exit(0);
  }
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  min_score = a[k - 1];
  for (adv = 0; adv < n && a[adv] >= min_score && a[adv] > 0; adv++) {
  }
  printf("%d\n", adv);
  return 0;
}