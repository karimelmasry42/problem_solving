#include <math.h>
#include <stdio.h>
struct point {
  float x, y;
};
void print_quad(struct point p) {
  int x = p.x, y = p.y;
  printf("(%d, %d) is ", x, y);
  if (x > 0) {
    if (y > 0) {
      printf("in quad I");
    } else if (y < 0) {
      printf("in quad IV");
    } else {
      printf("on +ve x-axis");
    }
  } else if (x < 0) {
    if (y > 0) {
      printf("in quad II");
    } else if (y < 0) {
      printf("in quad III");
    } else {
      printf("on -ve x-axis");
    }
  } else {
    if (y > 0) {
      printf("on +ve y-axis");
    } else if (y < 0) {
      printf("on -ve y-axis");
    } else {
      printf("on the origin");
    }
  }
  puts("");
}
float line_length(struct point a, struct point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
int main() {
  struct point a, b;
  puts("Enter two points x, y");
  scanf("%f, %f %f, %f", &a.x, &a.y, &b.x, &b.y);
  print_quad(a);
  print_quad(b);
  printf("length b/w points = %f\n", line_length(a, b));
  return 0;
}