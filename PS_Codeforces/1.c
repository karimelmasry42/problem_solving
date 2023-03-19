#include <stdio.h>
int main() {
  int M, N, max_dominoes;
  while (1) {
    scanf("%d%d", &M, &N);

    if (1 > M || M > N || N > 16) {
      printf("Invalid input");
      continue;
    } else {
      max_dominoes = M * N / 2;
      printf("%d", max_dominoes);
      break;
    }
  }
}