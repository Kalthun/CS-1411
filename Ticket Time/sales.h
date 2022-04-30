#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WORKERS 4
#define PRODUCTS 5

struct slip {
  int id;
  int pn;
  float total_sold;
};

void display_slip(const struct slip *s);

struct slip create_slip(void);

void input_slip(float sales[PRODUCTS][WORKERS], const struct slip *s);

void display_sales(float sales[PRODUCTS][WORKERS]);

float total_row(float sales[PRODUCTS][WORKERS], int r, int tc);

float total_col(float sales[PRODUCTS][WORKERS], int c, int tr);