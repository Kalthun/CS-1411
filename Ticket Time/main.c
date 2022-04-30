#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sales.h"

#define SLIPS 150

int main(void) {

  srand(time(NULL));

  float sales[PRODUCTS][WORKERS] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
  };

  display_sales(sales);

  // Generating previous month
  struct slip slips[SLIPS][WORKERS];
  int item = 1;
  for (int c = 0; c < WORKERS; c++) {
    for (int r = 0; r < SLIPS; r++) {
      if (item > 5) {
        item = 1;
      }
      slips[r][c].id = c + 1;
      slips[r][c].pn = item;
      slips[r][c].total_sold = (rand() % 100000) / 100.0;
      item++;
    }
  }

  // loading the table
  for (int c = 0; c < WORKERS; c++) {
    for (int r = 0; r < SLIPS; r++) { 
      input_slip(sales, &slips[r][c]);
    }
  }

  display_sales(sales);

}