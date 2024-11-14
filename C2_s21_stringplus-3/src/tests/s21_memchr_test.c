#include "s21_tests.h"

START_TEST(memchr_test_1) {
  char str[100] = "ab0babop";
  void *result = s21_memchr(str, 'o', 5);
  void *expected_result = memchr(str, 'o', 5);
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(memchr_test_2) {
  char str[1000] = "ab0babop";
  void *result = s21_memchr(str, 'y', 1000);
  void *expected_result = memchr(str, 'y', 1000);
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(memchr_test_3) {
  char str[1000] = "ab0babop";
  void *result = s21_memchr(str, 'o', 3);
  void *expected_result = memchr(str, 'o', 3);
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(memchr_test_4) {
  char *str = malloc(100);
  str[0] = 'a';
  void *result = s21_memchr(str, 'b', 10);
  void *expected_result = memchr(str, 'b', 10);
  ck_assert_ptr_eq(result, expected_result);
  free(str);
}
END_TEST

START_TEST(memchr_test_5) {
  char str[100] = "ab0babop";
  void *result = s21_memchr(str, 'o', 8);
  void *expected_result = memchr(str, 'o', 8);
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

Suite *s21_test_suite_memchr(void) {
  // Содержит набор тестов. Используется для группировки тестов, связан с опр.
  // модулем или функционалом
  Suite *s;
  // Обычно содержит набор тестов, тестирующих различные аспекты одной и той же
  // функциональности. Позволяет запускать несколько тестов как единое целое
  TCase *tc_core;

  // Создает набор тестов с заданным именем
  s = suite_create("s21_memchr");
  // Создает тестовый пример
  tc_core = tcase_create("s21_memchr_case");

  // Добавление тестов в кейс
  tcase_add_test(tc_core, memchr_test_1);
  tcase_add_test(tc_core, memchr_test_2);
  tcase_add_test(tc_core, memchr_test_3);
  tcase_add_test(tc_core, memchr_test_4);
  tcase_add_test(tc_core, memchr_test_5);

  // Добавление кейса в набор
  suite_add_tcase(s, tc_core);

  return s;
}

// gcc -o s21_memchr_test s21_memchr_test.c ../s21_memchr.c -lcheck -pthread -lm
// -lrt -fprofile-arcs -ftest-coverage -lsubunit
// ./s21_memchr_test
// gcov s21_memchr_test.c
// lcov --capture --directory . --output-file coverage.info
// genhtml coverage.info --output-directory coverage_report
// coverage_report это название отчета
// внутри можно открыть index.html через проводник

// В директории src:
// gcc -c tests/*.c -ftest-coverage -lsubunit
// mv *.o tests/
// mv *.gcno tests/
// gcc *.c tests/*.o -o tests/all_tests.o -lcheck -lsubunit -pthread -lrt -lm
// -fprofile-arcs -ftest-coverage mv *.gcno tests/ tests/all_tests.o mv *.gcda
// tests/ gcov tests/*.c mv *.gcov tests/ lcov --capture --directory .
// --output-file tests/coverage.info genhtml tests/coverage.info
// --output-directory tests/coverage_report