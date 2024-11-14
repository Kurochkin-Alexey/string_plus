#include "s21_tests.h"

// Тест на изменение строки
START_TEST(test_1) {
  char str1[9] = "cucumber";
  char str2[9] = "cucumber";
  char replace = 'q';
  s21_size_t n = 8;

  s21_memset(str1, replace, n);
  memset(str2, replace, n);

  ck_assert(memcmp(str1, str2, n) == 0);
}
END_TEST

// Тест на замену с заглавными буквами
START_TEST(test_2) {
  char str1[9] = "cucumber";
  char str2[9] = "cucumber";
  char replace = 'Q';
  s21_size_t n = 8;

  s21_memset(str1, replace, n);
  memset(str2, replace, n);

  ck_assert(memcmp(str1, str2, n) == 0);
}
END_TEST

// Тест на замену на число
START_TEST(test_3) {
  char str1[9] = "cucumber";
  char str2[9] = "cucumber";
  char replace = '4';
  s21_size_t n = 8;

  s21_memset(str1, replace, n);
  memset(str2, replace, n);

  ck_assert(memcmp(str1, str2, n) == 0);
}
END_TEST

Suite *s21_test_suite_memset(void) {  // Объявляем функцию
  Suite *suite = suite_create("s21_memset");  // Создаем набор тестов

  // Создаем группы тестов для набора
  TCase *tcase_core = tcase_create("s21_memset_core");

  // Добавляем тесты в группу
  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);

  // Добавляем группу тестов в набор
  suite_add_tcase(suite, tcase_core);

  return suite;
}