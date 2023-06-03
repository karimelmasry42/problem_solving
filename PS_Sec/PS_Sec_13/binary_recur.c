/**
 * Karim O. Elmasry 2023-05-23
 * Recursive binary search an array on ints
 */
#include <stdio.h>
int _binary_search_recur(int a[], int low, int high, int key) {
  if (high < low)
    return -1;
  int mid = (high + low) / 2;
  if (a[mid] == key)
    return mid;
  if (key > a[mid])
    return _binary_search_recur(a, mid + 1, high, key);
  else
    return _binary_search_recur(a, low, mid - 1, key);
}
int binary_search_recur(int a[], int size, int key) {
  return _binary_search_recur(a, 0, size - 1, key);
}
int main() {
  int size = 10, a[size], key;
  puts("Enter 10 ints");
  for (int i = 0; i < size; i++)
    scanf("%d", &a[i]);
  puts("Enter search key");
  scanf("%d", &key);
  printf("index = %d", binary_search_recur(a, size, key));
  return 0;
}