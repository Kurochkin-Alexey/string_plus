#include "s21_tests.h"

START_TEST(test_1) {
  char str1[50] = "Salut";
  char str2[50] = "Alloha";
  void *my_result = s21_strncpy(str1, str2, 6);
  void *orig_result = strncpy(str1, str2, 6);
  ck_assert_ptr_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_2) {
  char str1[50] = "Salu\0t";
  char str2[50] = "Alloha";
  void *my_result = s21_strncpy(str1, str2, 6);
  void *orig_result = strncpy(str1, str2, 6);
  ck_assert_ptr_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_3) {
  char str1[50] = "Alloha";
  char str2[50] = "ALloha";
  void *my_result = s21_strncpy(str1, str2, 6);
  void *orig_result = strncpy(str1, str2, 6);
  ck_assert_ptr_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_4) {
  char str1[50] = "";
  char str2[50] = "";
  void *my_result = s21_strncpy(str1, str2, 6);
  void *orig_result = strncpy(str1, str2, 6);
  ck_assert_ptr_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_5) {
  char str1[50] = "";
  char str2[50] = "Alloha";
  void *my_result = s21_strncpy(str1, str2, 6);
  void *orig_result = strncpy(str1, str2, 6);
  ck_assert_ptr_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_6) {
  char str1[50] = "All\0\0oha";
  char str2[50] = "Alloha";
  void *my_result = s21_strncpy(str1, str2, 6);
  void *orig_result = strncpy(str1, str2, 6);
  ck_assert_ptr_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_7) {
  char str1[50] = "Alloha";
  char str2[50] = "";
  void *my_result = s21_strncpy(str1, str2, 6);
  void *orig_result = strncpy(str1, str2, 6);
  ck_assert_ptr_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_8) {
  char str1[50] = "\0";
  char str2[50] = "\0";
  void *my_result = s21_strncpy(str1, str2, 6);
  void *orig_result = strncpy(str1, str2, 6);
  ck_assert_ptr_eq(my_result, orig_result);
}
END_TEST

Suite *s21_test_suite_strncpy(void) {
  Suite *suite = suite_create("s21_strncpy");
  TCase *tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  tcase_add_test(tcase_core, test_6);
  tcase_add_test(tcase_core, test_7);
  tcase_add_test(tcase_core, test_8);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
