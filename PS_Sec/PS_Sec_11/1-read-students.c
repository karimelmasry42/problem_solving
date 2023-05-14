#include <stdio.h>
#include <string.h>
#define STUDENT_N 6
#define STR_SIZE 30
int search_name(int arr_size, int str_size, char names[][str_size], int ids[],
                char name[]);
void sort_names(int arr_size, int str_size, char names[][str_size], int ids[]);
void swap_str(char str1[], char str2[], int arr_size);
void swap_int(int *a, int *b);

int main() {
  FILE *students_file = fopen(
      "/Users/karim/repos/problem-solving/PS_Sec/PS_Sec_11/students.txt", "r");
  int ids[STUDENT_N];
  char names[STUDENT_N][STR_SIZE];
  for (int i = 0; i < STUDENT_N && !feof(students_file); i++) {
    fscanf(students_file, "%d", &ids[i]);
    fscanf(students_file, "%s", names[i]);
    printf("%3d %s\n", ids[i], names[i]);
  }
  char student_name[] = "Yeager";
  int id = search_name(STUDENT_N, STR_SIZE, names, ids, student_name);
  printf("The ID of %s is %d\n", student_name, id);
  sort_names(STUDENT_N, STR_SIZE, names, ids);
  puts("");
  for (int i = 0; i < STUDENT_N; i++)
    printf("%3d %s\n", ids[i], names[i]);
  return 0;
}

void swap_str(char str1[], char str2[], int arr_size) {
  char temp[arr_size];
  strcpy(temp, str1);
  strcpy(str1, str2);
  strcpy(str2, temp);
}

void swap_int(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int search_name(int arr_size, int str_size, char names[][str_size], int ids[],
                char name[]) {
  int found = 0, i;
  for (i = 0; i < arr_size && !found; i++)
    if (strcmp(names[i], name) == 0)
      found = 1;
  return found ? ids[i - 1] : -1;
}
void sort_names(int arr_size, int str_size, char names[][str_size], int ids[]) {
  for (int i = 0; i < arr_size - 1; i++) {
    int swapped = 0;
    for (int j = i; j < arr_size - 1; j++) {
      if (strcmp(names[j], names[j + 1]) > 0) {
        swap_str(names[j], names[j + 1], 30);
        swap_int(&ids[j], &ids[j + 1]);
        swapped = 1;
      }
    }
    if (!swapped)
      break;
  }
}
