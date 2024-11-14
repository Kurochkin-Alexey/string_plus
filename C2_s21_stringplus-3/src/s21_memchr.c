#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *arr = str;
  char *output = S21_NULL;
  for (s21_size_t i = 0; i < n && output == S21_NULL; i++) {
    if (arr[i] == c) {
      output = (void *)(arr + i);
    }
  }
  return output;
}