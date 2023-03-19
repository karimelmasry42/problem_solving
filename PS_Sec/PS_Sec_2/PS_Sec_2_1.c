#include <stdio.h>
#define PI 3.14
void instruct(void) {
  printf("This program calculates the area of a shape based on the shape");
}
void get_shape(char *);
float circle_area();
float square_area();
float triangle_area();

int main() {
  instruct();
  char shape;
  get_shape(&shape);
  float area = 0.0;
  switch (shape) {
  case 'S':
  case 's':
    area = square_area();
    break;
  case 'T':
  case 't':
    area = triangle_area();
    break;
  case 'C':
  case 'c':
    area = circle_area();
    break;
  default:
    printf("Invalid input");
  }
  printf("The area is %f", area);
  return 0;
}

/*
 * scans shape letter
 */
void get_shape(char *shape) {
  printf("Enter shape letter: \n");
  printf("S for square\n");
  printf("T for triangle\n");
  printf("C for circle\n");

  scanf(" %c", shape);
}

/*
 * gets parameters and calculates area of circle
 */
float circle_area() {
  float radius;
  printf("Enter radius: ");
  scanf("%f", &radius);
  return PI * radius * radius;
}

/*
 * gets parameters calculates area of square
 */
float square_area() {
  float length;
  printf("Enter length: ");
  scanf("%f", &length);
  return length * length;
}

/*
 * gets parameters calculates area of triangle
 */
float triangle_area() {
  float base, height;
  printf("Enter base length: ");
  scanf("%f", &base);
  printf("Enter height: ");
  scanf("%f", &height);
  return 0.5 * base * height;
}