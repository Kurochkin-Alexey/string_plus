#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *check = S21_NULL;

  if (*needle == '\0') {
    check = (char *)haystack;
  }

  while (*haystack != '\0') {
    const char *h = haystack;
    const char *n = needle;

    while (*n != '\0' && *h == *n) {
      h++;
      n++;
    }

    if (*n == '\0') {
      check = (char *)haystack;
      break;
    }
    haystack++;
  }

  return check;
}