#include <stdio.h>
#include <string.h>
int main() {
  char input[100];
  scanf("%[^1-9]", input); // space is after conversion specifier
  printf("entered: '%s'\n", input);
  return 0;
}