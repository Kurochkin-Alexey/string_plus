#include "s21_tests.h"

START_TEST(s21_strrchr_test_1) {
  char str[100] = "ab0babop";
  char *result = s21_strrchr(str, 'o');
  char *expected_result = strrchr(str, 'o');
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(s21_strrchr_test_2) {
  char str[100] = "ab0babop";
  char *result = s21_strrchr(str, 'y');
  char *expected_result = strrchr(str, 'y');
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(s21_strrchr_test_3) {
  char str[100] = "ab0babop";
  char *result = s21_strrchr(str, 'b');
  char *expected_result = strrchr(str, 'b');
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(s21_strrchr_test_4) {
  char str[100] = "ab0babop";
  char *result = s21_strrchr(str, 'p');
  char *expected_result = strrchr(str, 'p');
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(s21_strrchr_test_5) {
  char str[100] = "ab0babop";
  char *result = s21_strrchr(str, 'a');
  char *expected_result = strrchr(str, 'a');
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

Suite *s21_test_suite_strrchr(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strrchr");

  tc_core = tcase_create("s21_strrchr_core");

  // Добавление тестов в кейс
  tcase_add_test(tc_core, s21_strrchr_test_1);
  tcase_add_test(tc_core, s21_strrchr_test_2);
  tcase_add_test(tc_core, s21_strrchr_test_3);
  tcase_add_test(tc_core, s21_strrchr_test_4);
  tcase_add_test(tc_core, s21_strrchr_test_5);

  // Добавление кейса в набор
  suite_add_tcase(s, tc_core);

  return s;
}