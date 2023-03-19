#include <stdio.h>
int main() {
  int rows = 9;
  for (int row = 0; row <= rows; row++) {
    for (int col = rows - row; col >= 0; col--) {
      printf(" ");
    }
    for (int col = 0; col <= row * 2; col++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
