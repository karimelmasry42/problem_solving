/**
 * Karim Elmasry 2023-05-06
 * read 5 student names and grades
 * store them in file
 * print name of student with highest score
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main() {
  FILE *outfile = fopen(
      "/Users/karim/repos/problem-solving/PS_Sec/PS_Sec_10/students.txt", "w");
  for (int i = 1; i <= 5; i++) {
    char str[20];
    int grade;
    printf("Enter first name and grade of student %d: ", i);
    scanf("%19s %d", str, &grade);
    fprintf(outfile, "%s %d\n", str, grade);
  }
  return 0;
}