#include <math.h>
#include <stdio.h>
double roundToInteger(double number);
double roundToTenths(double number);
double roundToHundredths(double number);
double roundToThousandths(double number);

int main() {
  double number = 42.42424242;
  printf("%lf\n", roundToInteger(number));
  printf("%lf\n", roundToTenths(number));
  printf("%lf\n", roundToHundredths(number));
  printf("%lf\n", roundToThousandths(number));
  return 0;
}

double roundToInteger(double number) { return floor(number + .5); }
double roundToTenths(double number) { return floor(number * 10 + .5) / 10; }
double roundToHundredths(double number) {
  return floor(number * 100 + .5) / 100;
}
double roundToThousandths(double number) {
  return floor(number * 1000 + .5) / 1000;
}
