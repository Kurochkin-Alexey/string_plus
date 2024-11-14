#include "s21_string.h"

/* Возвращает новую строку, в которой указанная строка (str) вставлена в
   указанную позицию (start_index) в данной строке (src). В случае какой-либо
   ошибки следует вернуть значение NULL. */

char *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == NULL || str == NULL) {
    return NULL;
  }
  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);

  if (start_index > src_len) {
    return NULL;
  }
  char *result = (char *)calloc(src_len + str_len + 1, sizeof(char));
  if (result == NULL) {
    return NULL;
  }
  s21_memcpy(result, src, start_index);
  s21_memcpy(result + start_index, str, str_len);
  s21_memcpy(result + start_index + str_len, src + start_index,
             src_len - start_index + 1);

  return result;
}