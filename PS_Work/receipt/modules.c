#define MAX_COLS 4
#define MAX_ROWS 128
#define MAX_NAME_LEN 128
#define MAX_LINE_LEN 1024
#define NUM_PADDING 4    // $(NUM).00, also use for quantities and ints
#define BORDER_WIDTHS 13 // 3*3+4, includes outer border
#include "modules.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ADD CURRENCY OPTION
// "ITEM_NAME", "QUANTITY", "ITEM_PRICE", "ITEM_TOTAL"

static const char DEFAULT_TITLE[MAX_COLS][MAX_NAME_LEN] = {
    "ITEM_NAME", "QUANTITY", "ITEM_PRICE", "ITEM_TOTAL"};
static int auto_init_done = 0;
void init_receipt(receipt_t *receipt) {
  if (!auto_init_done)
    auto_init_done = 1;

  // init to 0
  receipt->items_num = 0;
  receipt->receipt_total = 0;

  // init currency
  receipt->currency = '$';

  // init separators
  receipt->row_sep = '-'; // horizontal line b/w blocks (title, item, and total)
  receipt->col_sep = '|'; // vertical line b/w columns
  receipt->intersect_sep =
      '+'; // char at intersections b/w rows_sep and col_sep

  // store column titles
  for (int i = 0; i < MAX_COLS; i++) {
    strncpy(receipt->title_text[i], DEFAULT_TITLE[i], MAX_NAME_LEN);
    receipt->col_widths[i] = strlen(DEFAULT_TITLE[i]);
  }
}

int _price_width(float n) { return log10(n) + 1 + NUM_PADDING; }

int _qty_width(int n) { return log10(n) + 1; }

void read_line(receipt_t *receipt, char line[MAX_LINE_LEN], int *i) {

  // partition and store item_name
  strncpy(receipt->items[*i].item_name, strtok(line, ","), MAX_NAME_LEN);
  // update col_width of item_name
  if (receipt->col_widths[0] < strlen(receipt->items[*i].item_name))
    receipt->col_widths[0] = strlen(receipt->items[*i].item_name);

  // partition and store item_qty and item_price
  sscanf(strtok(NULL, ""), "%d,%f", &receipt->items[*i].item_qty,
         &receipt->items[*i].item_price);
  // update col_width of item_qty
  if (receipt->col_widths[1] < _qty_width(receipt->items[*i].item_qty))
    receipt->col_widths[1] = _qty_width(receipt->items[*i].item_qty);
  // update col_width of item_price
  if (receipt->col_widths[2] < _price_width(receipt->items[*i].item_price))
    receipt->col_widths[2] = _price_width(receipt->items[*i].item_price);

  // calculate item_total (total price of item)
  // update receipt_total
  receipt->receipt_total +=
      (receipt->items[*i].item_total =
           receipt->items[*i].item_qty * receipt->items[*i].item_price);
  // update col_width of item_total
  if (receipt->col_widths[3] < _price_width(receipt->items[*i].item_total))
    receipt->col_widths[3] = _price_width(receipt->items[*i].item_total);
}

int read_items(receipt_t *receipt, FILE *receipt_csv) {
  if (!auto_init_done)
    init_receipt(receipt);

  int *i = &receipt->items_num; // items_count
  char line[MAX_LINE_LEN];

  // get line and update items_count
  for (fgets(line, MAX_LINE_LEN, receipt_csv); !feof(receipt_csv);
       fgets(line, MAX_LINE_LEN, receipt_csv), (*i)++)
    read_line(receipt, line, i);
  read_line(receipt, line, i);
  (*i)++;

  // calculate table_width
  receipt->table_width = BORDER_WIDTHS;
  for (int i = 0; i < 4; i++)
    receipt->table_width += receipt->col_widths[i];
  return *i;
}

void print_outer_row_border(receipt_t *receipt, FILE *file) {
  // 1st sep
  fprintf(file, "%c", receipt->intersect_sep);
  // border
  for (int i = 0; i < receipt->table_width - 2; i++)
    fprintf(file, "%c", receipt->row_sep);
  // last sep
  fprintf(file, "%c\n", receipt->intersect_sep);
}

void print_title(receipt_t *receipt, FILE *file) {
  // "ITEM_NAME", "QUANTITY", "ITEM_PRICE", "ITEM_TOTAL"
  for (int i = 0; i < MAX_COLS; i++) {
    fprintf(file, "%c ", receipt->col_sep); // sep
    fprintf(file, "%*s ", -(receipt->col_widths[i]), receipt->title_text[i]);
  }
  fprintf(file, "%c\n", receipt->col_sep); // sep
}

void print_inner_row_border(receipt_t *receipt, FILE *file) {
  for (int i = 0; i < 4; i++) {
    fprintf(file, "%c", receipt->intersect_sep); // intersect_sep
    // col separators have one space before and after
    for (int j = 0; j < receipt->col_widths[i] + 2; j++)
      fprintf(file, "%c", receipt->row_sep); // col_sep
  }
  fprintf(file, "%c\n", receipt->intersect_sep); // last intersect_sep
}

void print_rows(receipt_t *receipt, FILE *file) {
  // "ITEM_NAME", "QUANTITY", "ITEM_PRICE", "ITEM_TOTAL"
  for (int i = 0; i < receipt->items_num; i++) {
    fprintf(file, "%c ", receipt->col_sep); // sep
    fprintf(file, "%*s", -(receipt->col_widths[0]),
            receipt->items[i].item_name);    // ITEM_NAME
    fprintf(file, " %c ", receipt->col_sep); // sep
    fprintf(file, "%*d", receipt->col_widths[1],
            receipt->items[i].item_qty);     // QUANTITY
    fprintf(file, " %c ", receipt->col_sep); // sep
    fprintf(file, "%c%*.2f", receipt->currency, receipt->col_widths[2] - 1,
            receipt->items[i].item_price);   // ITEM_PRICE
    fprintf(file, " %c ", receipt->col_sep); // sep
    fprintf(file, "%c%*.2f", receipt->currency, receipt->col_widths[3] - 1,
            receipt->items[i].item_total);    // ITEM_TOTAL
    fprintf(file, " %c\n", receipt->col_sep); // sep
  }
}

void print_total(receipt_t *receipt, FILE *file) {
  fprintf(file, "%c ", receipt->col_sep);
  // col separators take 2+1 spaces between cols and 1+1 at table edge
  fprintf(file, "%*s",
          -(receipt->table_width - receipt->col_widths[MAX_COLS - 1] - 4),
          "TOTAL:   ");
  fprintf(file, "%c%*.2f", receipt->currency,
          receipt->col_widths[MAX_COLS - 1] - 1, receipt->receipt_total);
  fprintf(file, " %c\n", receipt->col_sep);
}

void print_table(receipt_t *receipt, FILE *file) {
  print_inner_row_border(receipt, file);
  print_title(receipt, file);
  print_inner_row_border(receipt, file);
  print_rows(receipt, file);
  print_inner_row_border(receipt, file);
  print_total(receipt, file);
  print_outer_row_border(receipt, file);
}
