/**
 * Karim Elmasry 2023-05-06
 * read 5 student names and grades
 * store them in file
 * print name of student with highest score
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
void swap_int(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void swap_str(char *a, char *b) {
  char temp[100];
  strcpy(temp, a);
  strcpy(a, b);
  strcpy(b, temp);
}
void bubble_sort(int size, int grades[], char names[][100]) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (grades[j] < grades[j + 1]) {
        swap_int(&grades[j], &grades[j + 1]);
        swap_str(names[j], names[j + 1]);
      }
    }
  }
}
int main() {
  // FILE *outfile = fopen(
  //     "/Users/karim/repos/problem-solving/PS_Sec/PS_Sec_10/students.txt",
  //     "w");
  char names[5][100];
  int grades[5];
  // input from user
  printf("Enter first name and grade of each student:\n");
  for (int i = 0; i < 5; i++) {
    scanf("%s", names[i]);
    scanf("%d", &grades[i]);
  }
  // sort
  bubble_sort(5, grades, names);
  for (int i = 0; i < 5; i++) {
    printf("name: %10s grade: %d\n", names[i], grades[i]);
  }
  return 0;
}