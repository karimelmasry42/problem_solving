#include <stdio.h>
int sum(int a, int b) { return a + b; }
int main() {
  int n = 10;
  int arr[n];
  for (int i = 0; i < 10; i++) {
    int status = scanf("%d", &arr[i]);
    while (status < 1) {
      scanf("%*c");
      status = scanf("%d", &arr[i]);
    }
  }
  printf("\n");
  for (int i = 0; i < 10; i++)
    printf("%d ", arr[i]);

  printf("\n%d", sum(10, 10));
  printf("\n%d", arr[1000]);
  printf("\n%d", (&n)[0]);
}
