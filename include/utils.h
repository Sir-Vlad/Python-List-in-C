#ifndef UTILS_H
#define UTILS_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "color.h"
#include "type.h"

#define NOT_IMPLEMENTED                                                  \
  fprintf(stderr, "Not implemented " RED_BOLD "%s()\n" RESET, __func__); \
  abort();

__attribute__((unused)) int random_range(int min, int max);

__attribute__((unused)) int* random_array(int num_el, int min, int max);

#endif  // UTILS_H
