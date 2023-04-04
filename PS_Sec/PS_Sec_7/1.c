#include <stdio.h>
int main() {
  float num[10], sum = 0, max, min, check;
  int count = 0;
  printf("Enter 10 numbers\n");
  for (int i = 0; i < 10; i++)
    scanf("%f", &num[i]);
  printf("Count its repetitions of: ");
  scanf("%f", &check);
  max = min = num[0];
  for (int i = 0; i < 10; i++) {
    float n = num[i];
    sum += n;
    if (n == check)
      count++;
    if (n > max)
      max = n;
    if (n < min)
      min = n;
  }
  printf("sum = %f\n", sum);
  printf("average = %f\n", sum / 10.0);
  printf("min = %f\n", min);
  printf("max = %f\n", max);
  printf("%f is repeated %d times", check, count);
  return 0;
}