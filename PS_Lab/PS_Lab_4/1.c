#include <stdio.h>
int main() {
  int n, sum = 0;
  printf("Enter an integer: ");
  scanf("%d", &n);
  for (int copy = n; copy; copy /= 10)
    sum += copy % 10;
  if (sum % 9)
    printf("%d is not divisible by 9", n);
  else
    printf("%d is divisible by 9", n);
  return 0;
}