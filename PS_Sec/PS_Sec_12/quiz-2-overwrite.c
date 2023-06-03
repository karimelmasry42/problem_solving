/**
 * Karim Elmasry 2023-05-16
 * file of supermarket receipt
 * name qty price
 * calc total per item_t and final total
 * store in receipt file
 */
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define NAMEL 20
#define NUML 10
typedef struct item_t {
  char name[1000];
  float price, total;
  int qty;
} item_t;

int main() {
  FILE *receipt = fopen("/Users/karim/repos/problem-solving/PS_Sec/"
                        "PS_Sec_12/receipt-overwrite.txt",
                        "r"); // name qty price [add total]
  item_t items[1000];
  int item_no = 1;
  float total = 0;
  fscanf(receipt, "%s %d %f", items[0].name, &items[0].qty, &items[0].price);
  total += items[0].price * items[0].qty;
  while (!feof(receipt)) {
    fscanf(receipt, "%s %d %f", items[item_no].name, &items[item_no].qty,
           &items[item_no].price);
    total += items[item_no].total = items[item_no].price * items[item_no].qty;
    item_no++;
  }
  fclose(receipt);
  receipt = fopen("/Users/karim/repos/problem-solving/PS_Sec/"
                  "PS_Sec_12/receipt-overwrite.txt",
                  "w");
  fprintf(receipt, "| %-18s | %-10s | %-10s | %-10s |\n", "ITEM_NAME",
          "QUANTITY", "ITEM_PRICE", "ITEM_TOTAL");
  for (int i = 0; i < 61; i++)
    fprintf(receipt, "=");
  fprintf(receipt, "\n");

  for (int i = 0; i < item_no; i++) {
    fprintf(receipt, "| %-18s | %10d | $%9.2f | $%9.2f |\n", items[i].name,
            items[i].qty, items[i].price, items[i].total);
  }
  fprintf(receipt, "%40s  $%8.2f\n", "TOTAL: ", total);
  return 0;
}