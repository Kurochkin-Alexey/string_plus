#include "s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  int count = 0;
  int f = 0;
  const char *arr1 = str1;
  const char *arr2 = str2;
  size_t len_1 = s21_strlen(arr1);
  size_t len_2 = s21_strlen(arr2);
  for (size_t i = 0; i < len_1; i++) {
    for (size_t j = 0; j < len_2; j++) {
      if (arr1[i] == arr2[j]) f = 1;
    }
    if (f == 1)
      break;
    else
      count++;
  }
  return count;
}
