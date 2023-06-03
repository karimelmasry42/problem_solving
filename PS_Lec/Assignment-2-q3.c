/*
11 Apr 2023
Karim Ossama Elmasry
Dr. Emad Elsamahy
Problem Solving
Assignment 2 question 3
*/
#include <stdio.h>
void instruct() {
  puts("This program draws a diamond using * that is missing one quarter");
}
void DrawDiamond(int Quarter);
void DrawTriangle(int orientation, int base_size, char left_char,
                  char right_char);

int main() {
  instruct();
  puts("Enter empty quarter: ");
  int quart, status;
  status = scanf("%d", &quart);
  while (status < 1) {
    puts("Quarter must be a number");
    scanf("%*c");
    status = scanf("%d", &quart);
  }
  DrawDiamond(quart);
  return 0;
}

void DrawDiamond(int quart) {
  // quarters 1-4 = index 0-3.
  if (1 > quart || quart > 4) {
    puts("Quarter must be between 1 and 4");
    return;
  }
  char char_set[4] = {'*', '*', '*', '*'};
  char_set[quart - 1] = ' ';
  int base_size = 10;
  // print top triangle
  DrawTriangle(1, base_size, char_set[1], char_set[0]);
  // print bottom triangle
  DrawTriangle(-1, base_size, char_set[2], char_set[3]);
}

void DrawTriangle(int orient, int base_size, char left_char, char right_char) {
  // prints an isosceles triangles.
  // left half is filled with left_char, right with right_char.
  // orient > 0 prints triangle pointing up
  // orient < 0 prints triangle pointing down

  // base_size is the target number of chars printed on the long side of the
  // triangle.

  // actual base_size rounds down to even number to make triangle halves equal
  // in size.
  int half_base = base_size / 2;
  for (int row = 0; row < half_base; ++row) {
    // number of spaces before the characters in each row.
    int buffer_col_size = (orient > 0) ? (half_base - row - 1) : row;
    // half number of characters on each row.
    int char_col_size = (orient > 0) ? row : (half_base - row - 1);
    // print buffer spaces
    for (int col = 0; col < buffer_col_size; ++col)
      printf(" ");
    // print left half
    for (int col = 0; col <= char_col_size; ++col)
      printf("%c", left_char);
    // print right half
    for (int col = 0; col <= char_col_size; ++col)
      printf("%c", right_char);
    puts("");
  }
}