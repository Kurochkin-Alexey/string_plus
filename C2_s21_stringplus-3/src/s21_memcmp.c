#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int output = 0;
  const char *arr1 = str1;
  const char *arr2 = str2;
  for (s21_size_t i = 0; i < n; i++) {
    if (arr1[i] != arr2[i] && output == 0) {
      output = arr1[i] - arr2[i];
    }
  }
  // #ifdef __linux__
  //     if (output > 0) {
  //         output = 1;
  //         }
  //     else if (output < 0) {
  //         output = -1;
  //     }
  // #endif
  return output;
}