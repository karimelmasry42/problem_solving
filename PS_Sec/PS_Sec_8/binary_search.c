#include <stdio.h>

int main() {
  
  return 0;
  }

int binary_search(int size, int array[size], int key) {
  // Binary search. All variables, loop step and conditions are automatic local
  // in for loop
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
