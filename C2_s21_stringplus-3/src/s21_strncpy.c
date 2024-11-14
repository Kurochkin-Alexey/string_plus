#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
  char *result = dest;
  const char *arr = src;
  for (size_t i = 0; i < n; i++) {
    result[i] = arr[i];
    if (arr[i] == 0) {
      break;
    }
  }
  return result;
}
