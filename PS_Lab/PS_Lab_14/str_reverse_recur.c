// Reverse string recursive
#include <stdio.h>
#include <string.h>
void str_reverse(char str[]) {
  if (*str != '\0') {
    str_reverse(str + 1);
    printf("%c", *str);
  }
}
int main() {
  char str[20];
  scanf("%s", str);
  str_reverse(str);
  return 0;
}