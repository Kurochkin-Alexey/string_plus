#include "s21_tests.h"

int main(void) {
  int number_failed = 0;
  SRunner *sr;

  // Массив указателей на функции test_suite
  Suite *(*test_suites[])() = {s21_test_suite_memchr,
                               s21_test_suite_memcmp,
                               s21_test_suite_memcpy,
                               s21_test_suite_memset,
                               s21_test_suite_strchr,
                               s21_test_suite_strncat,
                               s21_test_suite_strlen,
                               s21_test_suite_strrchr,
                               s21_test_suite_strtok,
                               s21_test_suite_strstr,
                               s21_test_suite_strncmp,
                               s21_test_suite_strncpy,
                               s21_test_suite_strcspn,
                               s21_test_suite_strpbrk,
                               s21_test_suite_strerror,
                               s21_test_suite_sprintf,
                               test_insert,
                               test_trim,
                               test_to_lower,
                               test_to_upper};

  // Создание и запуск тестов для каждого варианта test_suite
  for (size_t i = 0; i < sizeof(test_suites) / sizeof(test_suites[0]); ++i) {
    sr = srunner_create(test_suites[i]());
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
