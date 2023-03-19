#include <stdio.h>
int main() {
  float wt_lb, ht_in;
  printf("Enter weight in wt_lb: ");
  scanf("%f", &wt_lb);
  printf("Enter height in ht_in: ");
  scanf("%f", &ht_in);
  float bmi = 703 * wt_lb / (ht_in * ht_in);
  if (bmi >= 30.0) {
    printf("Obese");
  } else if (bmi >= 25.0) {
    printf("Overweight");
  } else if (bmi >= 18.5) {
    printf("Normal");
  } else {
    printf("Underweight");
  }
  return 0;
}