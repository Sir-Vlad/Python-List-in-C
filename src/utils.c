#include "utils.h"

int random_range(int min, int max) {
  int result = 0, low_num = 0, hi_num = 0;
  if (min < max) {
    low_num = min;
    hi_num = max + 1;
  } else {
    low_num = max + 1;
    hi_num = min;
  }

  srand(time(NULL));
  result = (rand() % (hi_num - low_num)) + low_num;
  return result;
}

bool isUnique(int arr[], int size, int num) {
  for (size_t i = 0; i < size; i++) {
    if (arr[i] == num) {
      return false;
    }
  }
  return true;
}

int* random_array(int num_el, int min, int max) {
  int low_num = 0, hi_num = 0;
  int* result = (int*)malloc(sizeof(int) * num_el);
  if (min < max) {
    low_num = min;
    hi_num = max + 1;
  } else {
    low_num = max + 1;
    hi_num = min;
  }

  srand(time(NULL));
  for (size_t i = 0; i < num_el; i++) {
    int randomNum;
    do {
      randomNum = (rand() % (hi_num - low_num)) + low_num;
    } while (!isUnique(result, i, randomNum));

    result[i] = randomNum;
  }

  return result;
}