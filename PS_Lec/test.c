#include <stdio.h>
// CODE HERE MAY BE WRONG
void sum_arr(const int[], int *);
int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  printf("%d\n", size);
  int sum;
  sum_arr(arr, &sum);
  printf("%d\n", sum);
  return 0;
}
void sum_arr(const int arr[], int *sum) {
  *sum = 0;
  int size = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < size; i++)
    *sum += arr[i];
}