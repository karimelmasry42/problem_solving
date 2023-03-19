#include <stdio.h>

void speeds() {
  float speed, average, sum = 0;
  int cm = 0, ch = 0, cs = 0;
  printf("Enter speed (enter -ve number to exit): ");
  scanf("%f", &speed);
  while (speed >= 0) {
    if (speed >= 90) {
      printf("high speed\n");
      ch++;
    } else if (speed >= 50) {
      printf("medium speed\n");
      cm++;
    } else {
      printf("slow speed\n");
      cs++;
    }
    sum += speed;
    printf("Enter speed (enter -ve number to exit): ");
    scanf("%f", &speed);
  }
  int count = ch + cm + cs;
  printf("\nThe count of fast cars: %d\n", ch);
  printf("The count of medium cars: %d\n", cm);
  printf("The count of slow cars: %d\n", cs);
  printf("The average speed of all vehicles is %f mph", sum / count);
}

int main() {
  speeds();
  return 0;
}