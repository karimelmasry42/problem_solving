/**
 * Karim Elmasry 2023-05-06
 * Comparing strings
 */
#include <stdio.h>
#include <string.h>
int main() {
  char str[20] = "Hello";
  int i = 0;
  for (; str[i] != '\0'; i++) {
    printf("%c", str[i]);
  }
  puts("");
  char *str_in;
  // scanf("%20[^\n]s", str_in);
  // strncpy(str, str_in, strlen());
  puts(str);
  char str1[20], str2[20];
  scanf("%s", str1);
  scanf("%s", str2);
  printf("%s. %s.\n", str1, str2);
  printf("1 v 1: %d\n", strcmp(str1, str1));
  printf("1 v 2: %d\n", strcmp(str1, str2));
  printf("2 v 1: %d\n", strcmp(str2, str1));
  return 0;
}