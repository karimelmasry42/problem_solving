#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_PRODUCTS 4 // total number of unique products for sale
/**
 * Karim Ossama Elmasry 221005999
 */
void instruct();
float calc_invoice(float[], int[]);

int main() {
  float item_prices[] = {5, 10, 20, 15}; // item number = index +1
  int item_qty[NUM_OF_PRODUCTS] = {0};   // item number = index + 1
  int item_num, qty;                     // number and quantity of current item
                     // qty can be < 1 to REMOVE or RETURN items
  float invoice = 0; // can be < 0 to RETURN items
  if (NUM_OF_PRODUCTS != sizeof(item_prices) / sizeof(item_prices[0]) ||
      NUM_OF_PRODUCTS != sizeof(item_qty) / sizeof(item_qty[0])) {
    printf("LOGICAL ERROR: variable number of unique products");
    return 0;
  }
  while (1) {

    // get item number
    printf("\nEnter 0 to calculate invoice\n");
    printf("Enter item number (1 to %d): ", NUM_OF_PRODUCTS);
    scanf("%d", &item_num);

    if (item_num == 0) {

      // print invoice
      invoice = calc_invoice(item_prices, item_qty);
      if (invoice >= 1000) {
        // with discount
        invoice *= 0.9;
        printf("Your invoice is %.2f, with a 10%% discount applied", invoice);
        break;
      } else {
        // without discount
        printf("Your invoice is %.2f (no discount applied)", invoice);
        break;
      }
    } else if (item_num < 1 || item_num > NUM_OF_PRODUCTS) {
      // invalid item number message
      printf("Invalid input, item number must be between 1 and %d",
             NUM_OF_PRODUCTS);
      continue;
    }

    // get quantity
    printf("Enter quantity: ");
    scanf("%d", &qty);

    // store quantity
    item_qty[item_num - 1] += qty;
  }
}

void instruct() {
  printf("This program takes the items bought at a store and their ammount and "
         "returns the final price, with a 10%% discount if invoice >= $1000");
}

/**
 * calculates the total invoice WITHOUT discout
 */
float calc_invoice(float item_prices[], int item_qty[]) {
  float invoice = 0, price;
  int qty;
  for (int i = 0; i < NUM_OF_PRODUCTS; i++) {
    price = item_prices[i];
    qty = item_qty[i];
    invoice += price * qty;
    // printf("%.2f\n", invoice);
  }
  return invoice;
}