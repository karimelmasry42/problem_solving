#include <stdio.h>
int main() {
  int arr[10], max;
  FILE *outfp = fopen("/Users/karim/file.txt", "w");
  scanf("%d", &arr[0]);
  fprintf(outfp, "{%d", arr[0]);
  max = arr[0];
  for (int i = 1; i < 10; i++) {
    scanf("%d", &arr[i]);
    fprintf(outfp, ", %d", arr[i]);
    if (arr[i] > max)
      max = arr[i];
  }
  fprintf(outfp, "}\nmax = %d", max);
  return 0;
}