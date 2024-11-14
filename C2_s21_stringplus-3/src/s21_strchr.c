#include "s21_string.h"

//Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке,
//на которую указывает аргумент str.

char *s21_strchr(const char *str, int c) {
  char *result = S21_NULL;
  while (*str != '\0') {
    if (*str == c) {
      result = (char *)str;
      break;
    }
    str++;
  }
  return result;
}
