#ifndef MODULES_H
#define MODULES_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 4
#define MAX_ROWS 128
#define MAX_NAME_LEN 128
#define MAX_LINE_LEN 1024
#define NUM_PADDING 4    // $(NUM).00, also use for quantities and ints
#define BORDER_WIDTHS 13 // 3*3+4, includes outer border

static const char DEFAULT_TITLE[MAX_COLS][MAX_NAME_LEN];

typedef struct _item_t {
  float item_price, item_total;
  int item_qty;
  char item_name[MAX_NAME_LEN];
} item_t;

typedef struct _receipt_t {
  item_t items[MAX_ROWS];
  float receipt_total;
  int col_widths[MAX_COLS], table_width, items_num;
  char title_text[MAX_COLS][MAX_NAME_LEN], row_sep, col_sep, intersect_sep,
      currency;
} receipt_t;

void init_receipt(receipt_t *receipt);
void read_line(receipt_t *receipt, char line[MAX_LINE_LEN], int *i);
int read_items(receipt_t *receipt, FILE *receipt_csv);
void print_title(receipt_t *receipt, FILE *file);
void print_rows(receipt_t *receipt, FILE *file);
void print_total(receipt_t *receipt, FILE *file);
void print_inner_row_border(receipt_t *receipt, FILE *file);
void print_outer_row_border(receipt_t *receipt, FILE *file);
void print_table(receipt_t *receipt, FILE *file);

#endif