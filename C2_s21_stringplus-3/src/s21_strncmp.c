#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  int result = 0;
  const char *arr1 = str1;
  const char *arr2 = str2;
  for (size_t i = 0; i < n; i++) {
    if ((arr1[i] != arr2[i]) && (result == 0)) {
      result = arr1[i] - arr2[i];
    }
    if ((arr1[i] == 0) || (arr2[i] == 0)) {
      break;
    }
  }
  return result;
}
