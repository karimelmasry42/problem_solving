#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define QUADS 4
#define STICKER_PACKS 6
int in_array(const int arr[], int size, int val) {
  int i = 0;
  while (i < size && arr[i] != val) {
    i++;
  }
  return i < size ? i : -1;
}
int main() {
  srand(time(NULL));
  int quads[QUADS] = {0};
  int j = 0;
  while (j < 4) {
    int random = 1 + rand() % STICKER_PACKS;
    if (-1 == in_array(quads, QUADS, random))
      printf("%d ", quads[j++] = random);
  }
  return 0;
}