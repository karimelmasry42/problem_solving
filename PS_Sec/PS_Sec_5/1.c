#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
  printf("swap: a = %d &a = %d *a = %d", a, &a, *a);
}

int main() {
  int a = 3, b = 4;
  swap(&a, &b);
  printf("\nmain: a = %d &a = %d\n", a, &a);
  return 0;
}