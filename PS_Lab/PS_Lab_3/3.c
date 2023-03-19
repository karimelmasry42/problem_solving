#include <stdio.h>
int main() {
  float x, y;
  printf("Enter x coordinate: ");
  scanf("%f", &x);
  printf("Enter y coordinate: ");
  scanf("%f", &y);
  if (x > 0) {
    if (y > 0) {
      printf("(%.1f, %.1f) is in quadrant I", x, y);
    } else if (y < 0) {
      printf("(%.1f, %.1f) is in quadrant IV", x, y);
    } else {
      printf("(%.1f, %.1f) is on the y-axis", x, y);
    }
  } else if (x < 0) {
    if (y > 0) {
      printf("(%.1f, %.1f) is in quadrant II", x, y);
    } else if (y < 0) {
      printf("(%.1f, %.1f) is in quadrant III", x, y);
    } else {
      printf("(%.1f, %.1f) is on the y-axis", x, y);
    }
  } else {
    if (y == 0) {
      printf("(%.1f, %.1f) is on the origin", x, y);
    } else {
      printf("(%.1f, %.1f) is on the x-axis", x, y);
    }
  }
  printf("\n");
  return 0;
}