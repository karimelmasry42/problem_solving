/**
 * Karim Elmasry 2023-05-16
 * file of supermarket receipt_csv
 * name qty price
 * calc total per item_t and final total
 * store in receipt_csv file
 */
#include "modules.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *receipt_csv = fopen(
      "/Users/karim/repos/problem-solving/PS_Work/receipt/receipt.csv", "r");
  receipt_t receipt;
  read_items(&receipt, receipt_csv);
  print_table(&receipt, stdout);
}