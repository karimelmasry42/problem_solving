#include <stdio.h>
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void bubble_sort(int x[], int size) {
  int swapped = 0, i;
  for (i = 0; i < size; i++) {
    swapped = 0;
    for (int j = 0; j < size - i - 1; j++) {
      if (x[j] > x[j + 1]) {
        swap(&x[j], &x[j + 1]);
        swapped = 1;
      }
    }
    if (!swapped) {
      break;
    }
  }
  // printf("runs = %d\n", i + 1);
}
int main() {
  int x[10];
  for (int i = 0; i < 10; i++)
    scanf(" %d", &x[i]);
  bubble_sort(x, 10);
  for (int i = 0; i < 10; i++)
    printf("%d ", x[i]);
  printf("\n");
  return 0;
}