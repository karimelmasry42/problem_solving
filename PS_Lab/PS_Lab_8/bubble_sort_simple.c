#include <stdio.h>
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void bubble_sort(int x[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (x[j] > x[j + 1]) {
        swap(&x[j], &x[j + 1]);
      }
    }
  }
}
int main() {
  int x[10];
  for (int i = 0; i < 10; i++)
    scanf("%d", &x[i]);
  bubble_sort(x, 10);
  for (int i = 0; i < 10; i++)
    printf("%d ", x[i]);
  return 0;
}