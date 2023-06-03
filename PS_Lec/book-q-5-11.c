/*
11 Apr 2023
Karim Ossama Elmasry
Dr. Emad Elsamahy
Problem Solving
Book: C How to Program, Global Edition, 8th Edition
Page 237, question 5-11
*/
#include <math.h>
#include <stdio.h>
double roundToInteger(double number);
double roundToTenths(double number);
double roundToHundredths(double number);
double roundToThousandths(double number);

int main() {
  double number = 42.42424242;
  printf("original number =         %lf\n", number);
  printf("rounded to integer =      %lf\n", roundToInteger(number));
  printf("rounded to tenths =       %lf\n", roundToTenths(number));
  printf("rounded to hundredths =   %lf\n", roundToHundredths(number));
  printf("rounded to thousandths =  %lf\n", roundToThousandths(number));
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
