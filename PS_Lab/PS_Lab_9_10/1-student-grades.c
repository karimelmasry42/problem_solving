/**
 * Karim Elmasry 2023-05-06
 * Lab 10 Question 1
 * I used structs instead of parallel arrays
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student_t {
  char first_name[20], second_name[20];
  float deg1, deg2, deg3, total;
  int id;
} student_t;

void swap(student_t *a, student_t *b) {
  student_t temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(student_t x[], const int size) {
  int swapped = 0;
  int i = 0;
  for (; i < size; i++) {
    swapped = 0;
    for (int j = 0; j < size - i - 1; j++) {
      if (x[j].id > x[j + 1].id) {
        swap(&x[j], &x[j + 1]);
        swapped = 1;
      }
    }
    if (!swapped) {
      break;
    }
  }
  printf("runs = %d\n", i + 1);
}

int main() {
  FILE *students_file = fopen(
      "/Users/karim/repos/problem-solving/PS_Lab/PS_Lab_9_10/students.txt",
      "r");
  if (students_file == NULL) {
    puts("Couldn't open students.txt");
    exit(1);
  }
  student_t students_arr[100];
  int student_n = 0;
  for (; !feof(students_file) && student_n < 100; student_n++) {
    fscanf(students_file, "%d", &students_arr[student_n].id);
    fscanf(students_file, "%s", students_arr[student_n].first_name);
    fscanf(students_file, "%s", students_arr[student_n].second_name);
    fscanf(students_file, "%f %f %f", &students_arr[student_n].deg1,
           &students_arr[student_n].deg2, &students_arr[student_n].deg3);
    students_arr[student_n].total = students_arr[student_n].deg1 +
                                    students_arr[student_n].deg2 +
                                    students_arr[student_n].deg3;
  }
  bubble_sort(students_arr, student_n);
  for (student_t *student_p = &students_arr[0];
       student_p < &students_arr[student_n]; student_p++) {
    printf("%7d %-10s %-10s %5.2f\n", student_p->id, student_p->first_name,
           student_p->second_name, student_p->total);
    printf("%ld\n", student_p - students_arr);
  }
  return 0;
}