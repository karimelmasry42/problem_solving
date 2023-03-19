#include <stdio.h>
int main() {
  int num, odd_sum = 0, even_max = 0, odd_count = 1;
  float odd_avg;

  // get input
  printf("Enter a positive integer: ");
  scanf("%d", &num);

  while (num != -1) {
    // sort input
    if (num < 0)
      printf("Enter only a positive integer or -1\n");
    else if (num % 2 == 1) {
      odd_sum += num;
      odd_count++;
    } else if (num > even_max)
      even_max = num;

    // get input
    printf("\nEnter an integer: ");
    scanf("%d", &num);
  }
  odd_avg = (double)odd_sum / odd_count;

  // print output
  printf("Average of odds = %f\n", odd_avg);
  printf("Maximum even number = %d\n", even_max);
  return 0;
}