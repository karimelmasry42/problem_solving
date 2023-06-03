/**
 * Karim Elmasry 2023-05-16
 * read line from file
 * switch letter cases
 * write switched line below original line in file
 * delete original line and move switched line to its place
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main() {
  FILE *io =
      fopen("/Users/karim/repos/problem-solving/PS_Sec/PS_Sec_12/in.txt", "r+");
  char line[1000];
  fgets(line, 1000, io);
  int len = strlen(line);
  for (int i = 0; i < len; i++) {
    if (islower(line[i]))
      line[i] = toupper(line[i]);
    else if (isupper(line[i]))
      line[i] = tolower(line[i]);
  }
  fprintf(io, "\n%s", line);
  fseek(io, 0, SEEK_SET);
  fprintf(io, "%s", line);
  fseek(io, 1, SEEK_CUR);
  return 0;
}