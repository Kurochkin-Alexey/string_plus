#include "s21_tests.h"

START_TEST(memcmp_test_1) {
  char str1[100] = "abobabop";
  char str2[100] = "abobabop";
  int result = s21_memcmp(str1, str2, 8);
  int expected_result = memcmp(str1, str2, 8);
  ck_assert_int_eq(result, expected_result);
}
END_TEST

START_TEST(memcmp_test_2) {
  char str1[100] = "aboBabop";
  char str2[100] = "abobabop";
  int result = s21_memcmp(str1, str2, 8);
  int expected_result = memcmp(str1, str2, 8);
  ck_assert_int_eq(result, expected_result);
}
END_TEST

START_TEST(memcmp_test_3) {
  char str1[100] = "abobabop";
  char str2[100] = "abobAbop";
  int result = s21_memcmp(str1, str2, 8);
  int expected_result = memcmp(str1, str2, 8);
  ck_assert_int_eq(result, expected_result);
}
END_TEST

START_TEST(memcmp_test_4) {
  char str1[100] = "aboba";
  char str2[100] = "abobabop";
  int result = s21_memcmp(str1, str2, 8);
  int expected_result = memcmp(str1, str2, 8);
  ck_assert_int_eq(result, expected_result);
}
END_TEST

START_TEST(memcmp_test_5) {
  char str1[100] = "abobaBop";
  char str2[100] = "abobabop";
  int result = s21_memcmp(str1, str2, 5);
  int expected_result = memcmp(str1, str2, 5);
  ck_assert_int_eq(result, expected_result);
}
END_TEST

START_TEST(memcmp_test_6) {
  char str1[100] = "aboba";
  char *str2 = malloc(100);
  str2[0] = 'a';
  str2[1] = 'b';
  str2[2] = 'o';
  str2[3] = 'b';
  str2[4] = 'a';
  int result = s21_memcmp(str1, str2, 5);
  int expected_result = memcmp(str1, str2, 5);
  ck_assert_int_eq(result, expected_result);
  free(str2);
}
END_TEST

START_TEST(memcmp_test_7) {
  char *str1 = malloc(10);
  char *str2 = malloc(100);
  str1 = NULL;
  str2 = NULL;
  int result = s21_memcmp(str1, str2, 0);
  int expected_result = memcmp(str1, str2, 0);
  ck_assert_int_eq(result, expected_result);
  free(str1);
  free(str2);
}
END_TEST

Suite *s21_test_suite_memcmp(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_memcmp");

  tc_core = tcase_create("s21_memcmp_case");

  // Добавление тестов в кейс
  tcase_add_test(tc_core, memcmp_test_1);
  tcase_add_test(tc_core, memcmp_test_2);
  tcase_add_test(tc_core, memcmp_test_3);
  tcase_add_test(tc_core, memcmp_test_4);
  tcase_add_test(tc_core, memcmp_test_5);
  tcase_add_test(tc_core, memcmp_test_6);
  tcase_add_test(tc_core, memcmp_test_7);
  // Добавление кейса в набор
  suite_add_tcase(s, tc_core);

  return s;
}