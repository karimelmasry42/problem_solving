/*
11 Apr 2023
Karim Elmasry

Scan into array
Linear search
Binary search
*/
#include <stdio.h>
void scan_int_array(int size, int array[size]);
int linear_get_index(int size, int array[size], int key);
void bubble_sort(int size, int array[size]);
int binary_search(int size, int array[size], int key);
int swap(int *a, int *b);

int main() {
  int size = 10, key;
  int arr[size];

  // scan array
  puts("Enter integer array:");
  scan_int_array(size, arr);

  // scan key
  puts("Enter key:");
  int status = scanf("%d", &key);
  while (status < 1) {
    scanf("%*c");
    status = scanf("%d", &key);
  }

  // linear search
  printf("Linear search index = %d\n", linear_get_index(size, arr, key));

  // sort
  bubble_sort(size, arr);

  // print array
  puts("Bubble sorted array = ");
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  puts("");

  // binary search
  printf("Binary search index = %d\n", binary_search(size, arr, key));
  return 0;
}

void scan_int_array(int size, int array[size]) {
  for (int i = 0; i < size; i++) {
    int status = scanf("%d", &array[i]);
    while (status < 1) {
      scanf("%*c");
      status = scanf("%d", &array[i]);
    }
  }
}
int linear_get_index(int size, int array[size], int key) {
  for (int i = 0; i < size; i++)
    if (array[i] == key)
      return i;
  return -1;
}
int swap(int *a, int *b) {
  *b ^= *a;
  *a ^= *b;
  *b ^= *a;
  return 1;
}
void bubble_sort(int size, int array[size]) {
  // break if no swaps occur
  for (int i = 0, swapped = 1; swapped; ++i) {
    swapped = 0;
    // bubble [0] over unsorted slice of array
    for (int j = 0; j < size - i - 1; ++j) {
      if (array[j] > array[j + 1])
        swapped = swap(&array[j], &array[j + 1]);
    }
  }
}
int binary_search(int size, int array[size], int key) {
  for (int start = 0, end = size - 1, index = size / 2; start <= end;
       index = (start + end) / 2)
    if (array[index] == key)
      return index;
    else if (array[index] < key)
      start = index + 1;
    else
      end = index - 1;
  return -1;
}
