#include "s21_string.h"

//Вычисляет длину строки str, не включая завершающий нулевой символ.

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}