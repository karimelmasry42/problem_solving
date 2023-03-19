#include <stdio.h>
int main() {
  int num;
  printf("Enter integer: ");
  scanf("%d", &num);
  for (int copy = num; copy; copy /= 10)
    printf("%d\n", copy % 10);
  return 0;
}