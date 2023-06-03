#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main() {
  char input[1000];
  int lower_count = 0, upper_count = 0;
  gets(input);
  for (int i = 0; i < strlen(input); i++) {
    if (islower(input[i]))
      lower_count++;
    else if (isupper(input[i]))
      upper_count++;
  }
  printf("lower count = %d, upper count = %d", lower_count, upper_count);
  return 0;
}