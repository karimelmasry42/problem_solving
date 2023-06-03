#include <stdio.h>
#include <string.h>
int CountLineWords(char x[]) {
  int len = strlen(x), count = 0, letter_exists = 0;
  for (int i = 0; i < len; i++) {
    // check if line only contains spaces
    // numbers are considered words
    if (x[i] != ' ' && !letter_exists)
      letter_exists = 1;
    // count only spaces before words
    if (x[i] == ' ' && x[i + 1] != ' ' && x[i + 1] != '\0')
      count++;
  }
  // check if line begs or ends with space
  count -= (x[0] == ' ');
  if (x[len - 1] == '\n')
    count -= (x[len - 2] == ' ');
  else
    count -= (x[len - 1] == ' ');
  if (letter_exists)
    return count + 1;
  else
    return 0;
}

int CountSpaces(char x[]) {
  int len = strlen(x), count = 0;
  for (int i = 0; i < len; i++) {
    if (x[i] == ' ')
      count++;
  }
  return count;
}

int main() {
  FILE *in = fopen("/Users/karim/repos/problem-solving/Exam/input.txt", "r");
  int lines = 1, words = 0, spaces = 0;
  char line[1000];
  fgets(line, 1000, in);
  while (!feof(in)) {
    lines++;
    words += CountLineWords(line);
    spaces += CountSpaces(line);
    fgets(line, 1000, in);
  }
  words += CountLineWords(line);
  spaces += CountSpaces(line);

  printf("lines = %d, words = %d, spaces = %d", lines, words, spaces);
  return 0;
}
