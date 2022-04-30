#include "sales.h"

void display_slip(const struct slip *s) {
  puts("==================================");
  printf("id: %d, pn: %d, total sold: $%7.2f\n", s->id, s->pn, s->total_sold);
  puts("==================================");
}

struct slip create_slip(void) {
  int id;
  int pn;
  float ts;
  puts("Please enter a valid:\n\n- salesperson number\n- product number\n- total dollar value of product sold.");
  scanf("%d%d%f", &id, &pn, &ts);
  struct slip s = {id, pn, ts};;
  return s;
}

void input_slip(float sales[PRODUCTS][WORKERS], const struct slip *s) {
  display_slip(s);
  sales[s->pn-1][s->id-1] += s->total_sold;
}

float total_row(float sales[PRODUCTS][WORKERS], int r, int tc){
  float total = 0;
  for (int c = 0; c < tc; c++) {
    total += sales[r][c];
  }
  return total;
}

float total_col(float sales[PRODUCTS][WORKERS], int c, int tr){
  float total = 0;
  for (int r = 0; r < tr; r++) {
    total += sales[r][c];
  }
  return total;
}

void display_sales(float sales[PRODUCTS][WORKERS]) {
  puts("");
  printf("--------------------------------------------------------------\n");
  printf("%5s |%10d|%10d|%10d|%10d|%10s|\n", "sales", 1, 2, 3, 4, "total");
  printf("--------------------------------------------------------------\n");
  for (int r = 0; r < PRODUCTS; r++) {
    printf("%5d |$%9.2f|$%9.2f|$%9.2f|$%9.2f|$%9.2f|\n", r + 1, sales[r][0],sales[r][1],sales[r][2],sales[r][3], total_row(sales, r, 4));
    printf("--------------------------------------------------------------\n");
  }
  printf("%5s |$%9.2f|$%9.2f|$%9.2f|$%9.2f|%11s\n", "total", total_col(sales, 0, PRODUCTS), total_col(sales, 1, PRODUCTS),total_col(sales, 2, PRODUCTS), total_col(sales, 3, PRODUCTS), "end|");
  printf("--------------------------------------------------------------\n");
  puts("");
}