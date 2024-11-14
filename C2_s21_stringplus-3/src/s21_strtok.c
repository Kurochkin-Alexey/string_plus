#include "s21_string.h"

s21_size_t _find(const char *a, const char *b) {
  s21_size_t i = 0, j = 0;
  int result = -1;
  int flag = 0;
  for (; i < s21_strlen(a) && result == -1; ++i) {
    flag = 0;
    for (; j < s21_strlen(b) && !flag; ++j) {
      if (a[i] == b[j]) flag = 1;
    }
    if (!flag) result = i;
  }
  if (result == -1) result = s21_strlen(a);
  return (s21_size_t)result;
}

char *s21_strtok(char *str, const char *delim) {
  static int index;
  static char *result;
  if (str != S21_NULL) {
    result = str;
    index = 0;
  } else {
    str = &result[index + 1];
    result = str;
  }

  s21_size_t start = _find(str, delim);
  if (start < s21_strlen(str)) {
    char *finish = s21_strpbrk(str + start + 1, delim);
    if (finish == S21_NULL) {
      result = s21_strncpy(result, str + start, s21_strlen(str));
      index = s21_strlen(str);
      result[index] = '\0';
    } else {
      size_t res = finish - str - start;
      result = s21_strncpy(result, str + start, res);
      result[res] = '\0';
      index = start + res;
    }
  } else
    result = S21_NULL;
  return result;
}