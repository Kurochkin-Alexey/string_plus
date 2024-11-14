#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *last_value = S21_NULL;
  while (*str != '\0') {
    if (*str == c) {
      last_value = str;
    }
    str++;
  }

  return (char *)last_value;
}