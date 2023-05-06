#include <stdio.h>
int main() {
  char x[10];
  gets(x);
  printf("\n%c\n", x[11]);
  puts(x);
}