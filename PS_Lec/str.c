#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
  char s1[20] = "Hello World";
  char s2[20] = "\0";
  strncat(s2, s1, 5);
  puts(s2);
  puts(s2[5]);
  return 0;
}