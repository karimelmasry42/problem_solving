#include <stdio.h>
void swap(int *a, int *b);
void bubble_sort(int size, int arr[]);
void selection_sort(int size, int arr[]);
int binary_search(int size, int arr[], int key);

int main() {
  int arr[10];
  for (int i = 0; i < 10; i++) // scan array
    scanf("%d", &arr[i]);
  selection_sort(10, arr);     // sort it
  for (int i = 0; i < 10; i++) // print sorted
    printf("%d ", arr[i]);
  printf("\n");
  int index = binary_search(10, arr, 3); // search for 3
  printf("index of value 3 is: %d", index);
  return 0;
}
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void bubble_sort(int size, int arr[]) { // ASCENDING (smaller first)
  for (int i = 0; i < size; i++) {
    // minimum element will be placed at i
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] < arr[i]) { // for DESCENDING use arr[j] > arr[i]
        // if current element (j) is smaller than ith element, swap them
        swap(&arr[i], &arr[j]);
      }
    }
  }
}
void selection_sort(int size, int arr[]) { // ASCENDING (smaller first)
  for (int i = 0, *min; i < size - 1; i++) {
    // minimum element will be placed at i
    min = &arr[i]; // pointer to the minimum element in the sub-array
    for (int j = i + 1; j < size; j++) {
      // find the minimum element in the unsorted sub-array
      if (arr[j] < *min) { // for DESCENDING use arr[j] > *min
        // if current element is smaller than min, make current
        // element the new min
        min = &arr[j];
      }
    }
    swap(min, &arr[i]); // place minimum at j
  }
}
int binary_search(int size, int arr[],
                  int key) { // array must be in ASCENDING order
  for (int start = 0, end = size - 1, mid = size / 2; start <= end;
       mid = (start + end) / 2) {
    if (arr[mid] == key)
      return mid;            // key found, return its index
    else if (arr[mid] < key) // if DESCENDING use arr[mid] > key
      // if key not in smaller half, then it must be in greater half
      start = mid + 1;
    else
      // if key not in greater half, then it may be in smaller half
      end = mid - 1;
  }
  return -1; // loop ended and key not found
}
