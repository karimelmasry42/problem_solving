#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main() {
  char str[100];
  int int_c = 0, letter_c = 0, word_c = 1;
  gets(str);
  for (int i = 0; str[i] != '\0'; i++) {
    if ('0' <= str[i] && str[i] <= '9')
      int_c++;
    else if (('a' <= str[i] && str[i] <= 'z') ||
             ('A' <= str[i] && str[i] <= 'Z'))
      letter_c++;
    else if (' ' == str[i])
      word_c++;
  }
  // OR using ctype.h
  int_c = 0, letter_c = 0, word_c = 1;
  for (int i = 0; str[i] != '\0'; i++) {
    char c = str[i];
    if (isdigit(c))
      int_c++;
    else if (isalpha(c))
      letter_c++;
    else if (isspace(c))
      word_c++;
  }

  printf("integers : %d letters: %d words: %d\n", int_c, letter_c, word_c);
}