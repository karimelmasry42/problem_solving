#include <stdio.h>
#include <string.h>
#define STR_LEN 8
int main() {
  char str1[STR_LEN], str2[STR_LEN];
  char a, c, d, e, f, g, h, i, j, k, l;
  int b;
  printf("sizeof int = %d\n", sizeof(int));
  printf("&a = %d, &c = %d &f = %d\n", &a, &c, &f);
  printf("&a - &b = %d\n", (int)&a - (int)&b);
  /*printf("str2 address = %d\n", str2);
  puts("");
  printf("str1[0] address = %d\n", str1);
  printf("str2[0] address = %d\n", str2);
  puts("");
  printf("str1[-1] address = %d\n", &str1[-1]);
  printf("str2[-1] address = %d\n", &str2[-1]);
  puts("");
  printf("str1[15] address = %d\n", &str1[15]);
  printf("str2[15] address = %d\n", &str2[15]);
  puts("");
  printf("str1[STR_LEN] address = %d\n", &str1[STR_LEN]);*/
  printf("str1[0] address = %d\n", &str1[0]);
  printf("str2[STR_LEN] address = %d\n", &str2[STR_LEN]);
  puts("");

  str1[0] = 'a';
  str2[STR_LEN] = '\0';
  printf("str1[0] = '%c', should be 'a'\n", str1[0]);
  puts("");

  for (int i = 0, c = '1'; i < STR_LEN; i++, c++)
    str1[i] = str2[i] = c;
  str1[STR_LEN] = str2[STR_LEN] = '\0';
  printf("str1 = \"%s\"\n", str1);
  printf("str2 = \"%s\"\n", str2);
  return 0;
}