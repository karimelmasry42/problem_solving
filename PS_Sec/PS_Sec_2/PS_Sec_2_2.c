#include <stdio.h>
int main() {
  float item1_price = 3, item2_price = 4, item3_price = 5;
  int item_number, qty;
  float invoice = 0;
  while (1) {
    printf("\nEnter 0 to calculate invoice\n");
    printf("Enter item number (1, 2, or 3): ");
    scanf("%d", &item_number);
    if (item_number == 0) {
      if (invoice >= 1000) {
        invoice *= 0.9;
        printf("Your invoice is %.2f, with a 10%% discount applied", invoice);
      } else {
        printf("Your invoice is %.2f (no discount applied)", invoice);
      }
      break;
    }
    printf("Enter quantity: ");
    scanf("%d", &qty);
    switch (item_number) {
    case 1:
      invoice += item1_price * qty;
      break;
    case 2:
      invoice += item2_price * qty;
      break;
    case 3:
      invoice += item3_price * qty;
      break;
    default:
      printf("Invalid item number");
    }
  }
}