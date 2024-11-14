#include "s21_tests.h"

START_TEST(memcpy_test_1) {
  char dest[100] = "biba";
  char src[100] = "boba";
  void *result = s21_memcpy(dest, src, 8);
  void *expected_result = memcpy(dest, src, 8);
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(memcpy_test_2) {
  char dest[100] = "biba\0";
  char src[100] = "boba\0";
  void *result = s21_memcpy(dest, src, 8);
  void *expected_result = memcpy(dest, src, 8);
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(memcpy_test_3) {
  char dest[100] = "aboba";
  char *src = malloc(100);
  src[0] = 'a';
  src[1] = 'b';
  src[2] = 'o';
  src[3] = 'b';
  src[4] = 'a';
  void *result = s21_memcpy(dest, src, 8);
  void *expected_result = memcpy(dest, src, 8);
  ck_assert_ptr_eq(result, expected_result);
  free(src);
}
END_TEST

START_TEST(memcpy_test_4) {
  char dest[100] = "biba\0boba";
  char src[100] = "boba\0";
  void *result = s21_memcpy(dest, src, 10);
  void *expected_result = memcpy(dest, src, 10);
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(memcpy_test_5) {
  char *dest = malloc(10);
  char *src = malloc(100);
  dest = NULL;
  src = NULL;
  void *result = s21_memcpy(dest, src, 0);
  void *expected_result = memcpy(dest, src, 0);
  ck_assert_ptr_eq(result, expected_result);
  free(dest);
  free(src);
}
END_TEST

START_TEST(memcpy_test_6) {
  char dest[100];
  char src[100] = "aboba\0";
  void *result = s21_memcpy(dest, src, 5);
  void *expected_result = memcpy(dest, src, 5);
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(memcpy_test_7) {
  char dest[100] = "aboba";
  char src = 'a';
  void *result = s21_memcpy(dest, &src, 1);
  void *expected_result = memcpy(dest, &src, 1);
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

START_TEST(memcpy_test_8) {
  char *dest = NULL;
  char src[100] = "aboba\0";
  void *result = s21_memcpy(dest, src, 0);
  void *expected_result = memcpy(dest, src, 0);
  ck_assert_ptr_eq(result, expected_result);
}
END_TEST

Suite *s21_test_suite_memcpy(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_memcpy");

  tc_core = tcase_create("s21_memcpy_case");

  // Добавление тестов в кейс
  tcase_add_test(tc_core, memcpy_test_1);
  tcase_add_test(tc_core, memcpy_test_2);
  tcase_add_test(tc_core, memcpy_test_3);
  tcase_add_test(tc_core, memcpy_test_4);
  tcase_add_test(tc_core, memcpy_test_5);
  tcase_add_test(tc_core, memcpy_test_6);
  tcase_add_test(tc_core, memcpy_test_7);
  tcase_add_test(tc_core, memcpy_test_8);

  // Добавление кейса в набор
  suite_add_tcase(s, tc_core);

  return s;
}