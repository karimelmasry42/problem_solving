// C program to illustrate situation
// where flush(stdin) is required only
// in certain compilers.
#include <stdio.h>
#include <stdlib.h>
int main() {
  char a, b;
  scanf("%c", &a);
  scanf("%c ", &b);
  printf("%c\n", a);
  printf("%c\n", b);
  return 0;
}