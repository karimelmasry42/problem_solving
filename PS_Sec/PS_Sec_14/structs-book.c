#include <stdio.h>
#include <string.h>
#define MAX_NAME_LEN 100
struct book {
  int id;
  char name[MAX_NAME_LEN];
  float price;
};
// void bubble_sort(struct book x[], int size){
//   for(int i = 0; i < size; i++){

//   }
// }
int main() {
  struct book x[4];
  int n = 4, imax;
  printf("Enter %d book ID, name, and price\n", n);
  for (int i = 0; i < n; i++)
    scanf("%d %s %f", &x[i].id, x[i].name, &x[i].price);
  float max = x[0].price;
  imax = 0;
  for (int i = 1; i < n; i++) {
    if (x[i].price > x[imax].price) {
      imax = i;
    }
  }
  printf("max price = %.2f\n", max);
  return 0;
}