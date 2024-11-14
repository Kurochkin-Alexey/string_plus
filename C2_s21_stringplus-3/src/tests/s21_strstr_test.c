#include "s21_tests.h"

START_TEST(s21_strstr_test_1) {
  char str[100] = "ab0babop";
  char *result = s21_strstr(str, "bo");
  char *expected_result = strstr(str, "bo");
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(s21_strstr_test_2) {
  char str[1000] = "ab0babop";
  char *result = s21_strstr(str, "xyz");
  char *expected_result = strstr(str, "xyz");
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(s21_strstr_test_3) {
  char str[1000] = "ab0babop";
  char *result = s21_strstr(str, "ba");
  char *expected_result = strstr(str, "ba");
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(s21_strstr_test_4) {
  char str[100] = "ab0babop";
  char *result = s21_strstr(str, "op");
  char *expected_result = strstr(str, "op");
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(s21_strstr_test_5) {
  char str[100] = "ab0babop";
  char *result = s21_strstr(str, "ab");
  char *expected_result = strstr(str, "ab");
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(s21_strstr_test_6) {
  char str[100] = "ab0babop";
  char *result = s21_strstr(str, "\0");
  char *expected_result = strstr(str, "\0");
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

Suite *s21_test_suite_strstr(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_strstr");

  tc_core = tcase_create("s21_strstr_core");

  // Добавление тестов в кейс
  tcase_add_test(tc_core, s21_strstr_test_1);
  tcase_add_test(tc_core, s21_strstr_test_2);
  tcase_add_test(tc_core, s21_strstr_test_3);
  tcase_add_test(tc_core, s21_strstr_test_4);
  tcase_add_test(tc_core, s21_strstr_test_5);
  tcase_add_test(tc_core, s21_strstr_test_6);

  // Добавление кейса в набор
  suite_add_tcase(s, tc_core);

  return s;
}