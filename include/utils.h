#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "color.h"

#define NOT_IMPLEMENTED                                                  \
  fprintf(stderr, "Not implemented" BOLD RED " %s()\n" RESET, __func__); \
  abort();

int random_range(int min, int max);
int* random_array(int num_el, int min, int max);

#endif  // UTILS_H
