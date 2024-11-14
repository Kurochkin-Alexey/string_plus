#include "s21_tests.h"

// Обычный тест
START_TEST(test_1) {
  char str1[16] = "cucumber";
  char str2[16] = "cucumber";
  char add_str[] = "tomato";
  s21_size_t n = 8;

  s21_strncat(str1, add_str, n);
  strncat(str2, add_str, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Тест на добавление в пустую строку
START_TEST(test_2) {
  char str1[8] = "";
  char str2[8] = "";
  char add_str[] = "tomato";
  s21_size_t n = 8;

  s21_strncat(str1, add_str, n);
  strncat(str2, add_str, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Тест на добавление пустой строки
START_TEST(test_3) {
  char str1[16] = "cucumber";
  char str2[16] = "cucumber";
  char add_str[] = "";
  s21_size_t n = 6;

  s21_strncat(str1, add_str, n);
  strncat(str2, add_str, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Тест на добавление 0 символов из строки
START_TEST(test_4) {
  char str1[16] = "cucumber";
  char str2[16] = "cucumber";
  char add_str[] = "tomato";
  s21_size_t n = 0;

  s21_strncat(str1, add_str, n);
  strncat(str2, add_str, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// Тест на добавление не всех символов
START_TEST(test_5) {
  char str1[16] = "cucumber";
  char str2[16] = "cucumber";
  char add_str[] = "tomato";
  s21_size_t n = 4;

  s21_strncat(str1, add_str, n);
  strncat(str2, add_str, n);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_test_suite_strncat(void) {  // Объявили функцию
  Suite *suite = suite_create("s21_strncat");
  TCase *tcase_core = tcase_create("s21_strncat_core");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);

  // Добавляем группу тестов в набор
  suite_add_tcase(suite, tcase_core);

  return suite;
}
