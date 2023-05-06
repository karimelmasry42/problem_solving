#include <stdio.h>
void selection_sort(int size, int arr[size]);
void swap(int *, int *);

int main() {
  int arr[10];
  for (int i = 0; i < 10; i++)
    scanf("%d", &arr[i]);
  selection_sort(10, arr);
  for (int i = 0; i < 10; i++)
    printf("%d ", arr[i]);
  return 0;
}
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void selection_sort(int size, int arr[size]) {
  for (int j = 0, *min; j < size - 1; j++) {
    min = &arr[j];
    for (int i = j + 1; i < size; i++) {
      if (arr[i] < *min) {
        min = &arr[i];
      }
    }
    swap(min, &arr[j]);
  }
}