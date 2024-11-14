#include "s21_tests.h"

START_TEST(test_1) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "Salut";
  char str2[50] = "Alloha";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_2) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "PPPQQj";
  char str2[50] = "Alloha";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_3) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "Alloha";
  char str2[50] = "Alloha";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_4) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "";
  char str2[50] = "";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_5) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "Salut";
  char str2[50] = "";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_6) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "";
  char str2[50] = "Alloha";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_7) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "S\0alut";
  char str2[50] = "Alloha";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_8) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "S\0alut";
  char str2[50] = "All\0oha";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_9) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = " ";
  char str2[50] = "All\0oha";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_10) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "S\0alut";
  char str2[50] = " ";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_11) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "Salut";
  char str2[50] = "S a l u t";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_12) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "Salut";
  char str2[50] = " s a l u t ";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_13) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = " s a l u t";
  char str2[50] = "salut";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_14) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "80192";
  char str2[50] = "444";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_15) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "ALLOHA";
  char str2[50] = "alloha";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

START_TEST(test_16) {
  int my_result = 0;
  int orig_result = 0;
  char str1[50] = "\0";
  char str2[50] = "\0";
  my_result = s21_strcspn(str1, str2);
  orig_result = strcspn(str1, str2);
  ck_assert_int_eq(my_result, orig_result);
}
END_TEST

Suite *s21_test_suite_strcspn(void) {
  Suite *suite = suite_create("s21_strcspn");
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
  tcase_add_test(tcase_core, test_10);
  tcase_add_test(tcase_core, test_11);
  tcase_add_test(tcase_core, test_12);
  tcase_add_test(tcase_core, test_13);
  tcase_add_test(tcase_core, test_14);
  tcase_add_test(tcase_core, test_15);
  tcase_add_test(tcase_core, test_16);
  suite_add_tcase(suite, tcase_core);
  return suite;
}
