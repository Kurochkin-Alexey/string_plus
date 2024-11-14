#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *fp = S21_NULL;  // Используем NULL вместо S21_NULL
  while (*str1 != '\0' && fp == S21_NULL) {
    const char *s = str2;
    while (*s != '\0') {
      if (*str1 == *s) {
        fp = (char *)str1;  // Сохраняем указатель на первое вхождение
        break;
      }
      s++;
    }
    str1++;
  }
  return fp;
}
