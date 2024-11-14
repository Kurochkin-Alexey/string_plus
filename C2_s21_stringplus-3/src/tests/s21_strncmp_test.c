#include "s21_tests.h"

START_TEST(test_1) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "Alloha";
  char str2[50] = "Alloha";
  my_result = s21_strncmp(str1, str2, 6);
  orig_result = strncmp(str1, str2, 6);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_2) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "alloha";
  char str2[50] = "Alloha";
  my_result = s21_strncmp(str1, str2, 6);
  orig_result = strncmp(str1, str2, 6);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_3) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "Alloha";
  char str2[50] = "aLloha";
  my_result = s21_strncmp(str1, str2, 6);
  orig_result = strncmp(str1, str2, 6);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_4) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "";
  char str2[50] = "";
  my_result = s21_strncmp(str1, str2, 6);
  orig_result = strncmp(str1, str2, 6);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_5) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "Allohaaa";
  char str2[50] = "Alloha";
  my_result = s21_strncmp(str1, str2, 6);
  orig_result = strncmp(str1, str2, 6);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_6) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "All\0\0oha";
  char str2[50] = "Alloha";
  my_result = s21_strncmp(str1, str2, 6);
  orig_result = strncmp(str1, str2, 6);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_7) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "ALLOHA";
  char str2[50] = "alloha";
  my_result = s21_strncmp(str1, str2, 6);
  orig_result = strncmp(str1, str2, 6);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_8) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "\0";
  char str2[50] = "\0";
  my_result = s21_strncmp(str1, str2, 6);
  orig_result = strncmp(str1, str2, 6);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_9) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "!";
  char str2[50] = "  ";
  my_result = s21_strncmp(str1, str2, 6);
  orig_result = strncmp(str1, str2, 6);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

Suite *s21_test_suite_strncmp(void) {
  Suite *suite = suite_create("s21_strncmp");
  TCase *tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  tcase_add_test(tcase_core, test_6);
  tcase_add_test(tcase_core, test_7);
  tcase_add_test(tcase_core, test_8);
  tcase_add_test(tcase_core, test_9);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
