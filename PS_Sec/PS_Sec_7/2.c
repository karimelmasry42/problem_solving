#include <stdio.h>
#define ARR_SIZE 10
int main() {
  char array[ARR_SIZE];
  int is_palindrome = 1;
  scanf(" %s", array);
  for (int i = 0; i < (ARR_SIZE - 1) / 2; i++)
    if (array[i] != array[ARR_SIZE - 1 - i]) {
      is_palindrome = 0;
      printf("Array is not a palindrome");
      break;
    }
  if (is_palindrome)
    printf("Array is a palindrome");
  return 0;
}