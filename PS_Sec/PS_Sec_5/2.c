#include <stdio.h>

void scan2(float *a, float *b) { scanf("%d %d", a, b); }
float avg2(float a, float b) { return (a + b) / 2; }
void write_avg(FILE *f, float avg) {
  fprintf(f, "%f\n", avg);
  if (avg >= 50)
    fprintf(f, "Pass\n");
  else
    fprintf(f, "F\n");
}

int main() {
  FILE *f = fopen("out.txt", "w");
  float a, b;
  scan2(&a, &b);
  float avg = avg2(a, b);
  write_avg(f, avg);
  return 0;
}