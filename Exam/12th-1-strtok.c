#include <stdio.h>
#include <string.h>
int CountLineWords(char x[]) {
  int count = 0;
  char copy[strlen(x) + 1], *part;
  strcpy(copy, x);
  part = strtok(copy, " \n");
  count += (strlen(part) != 0);
  while ((part = strtok(NULL, " \n")) != NULL)
    count += (strlen(part) != 0);
  return count;
}

int CountSpaces(char x[]) {
  int i = strlen(x), count = 0;
  while (i--)
    count += (x[i] == ' ');
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