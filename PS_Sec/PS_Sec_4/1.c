#include <stdio.h>
#include <stdlib.h>
int main() {
  FILE *read;
  if ((read = fopen("read.txt", "r")) == NULL) {
    printf("No read.txt file");
    exit(1);
  }
  FILE *even = fopen("even.txt", "w");
  FILE *odd = fopen("odd.txt", "w");
  int num;
  while (!feof(read)) {
    fscanf(read, "%d", &num);
    if (num % 2)
      fprintf(odd, "%d\n", num);
    else
      fprintf(even, "%d\n", num);
  }
  fclose(read);
  fclose(even);
  fclose(odd);
  return 0;
}