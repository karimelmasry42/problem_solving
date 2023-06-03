/**
 * Karim O. Elmasry 2023-05-23
 * Recursive count repetitions of a character in a string
 */
#include <stdio.h>
int char_recur(char str[], char key) {
  if (strlen(str) == 0)
    return 0;
  return (str[0] == key) + char_recur(&str[1], key);
}
int main() {
  char str[100], key;
  puts("Enter str, key");
  scanf("%s", str);
  scanf(" %c", &key);
  printf("repetitions of key = %d", char_recur(str, key));
  return 0;
}