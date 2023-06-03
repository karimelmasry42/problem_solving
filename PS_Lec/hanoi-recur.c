#include <stdio.h>
void hanoi(char from, char to, char aux, int n) {
  if (n == 1)
    printf("Move disc 1 from %c to %c\n", from, to);
  else {
    hanoi(from, aux, to, n - 1);
    printf("Move disc %d from %c to %c\n", n, from, to);
    hanoi(aux, to, from, n - 1);
  }
}
int main() {
  hanoi('A', 'C', 'B', 3);
  return 0;
}