#include "s21_tests.h"

START_TEST(strtok_test_1) {
  char a[100] = "qwertyqwe";
  char b[100] = "qw";
  char c[100] = "qwertyqwe";
  char *expected = strtok(a, b);
  char *real = s21_strtok(c, b);
  ck_assert_str_eq(expected, real);
}
END_TEST

START_TEST(strtok_test_2) {
  char a[100] = "qwertyqwm";
  char c[100] = "qwertyqwm";
  char b[100] = "wert";
  char *expected = strtok(a, b);
  char *real = s21_strtok(c, b);
  ck_assert_str_eq(expected, real);
}
END_TEST

START_TEST(strtok_test_3) {
  char a[100] = "qwertyqwm";
  char b[100] = "";
  char c[100] = "qwertyqwm";
  char *expected = strtok(a, b);
  char *real = s21_strtok(c, b);
  ck_assert_str_eq(expected, real);
}
END_TEST

START_TEST(strtok_test_4) {
  char a[100] = "qwer\0tyqwed";
  char b[100] = "qwert";
  char c[100] = "qwer\0tyqwed";
  char *expected = strtok(a, b);
  char *real = s21_strtok(c, b);
  ck_assert_ptr_eq(expected, real);
}
END_TEST

START_TEST(strtok_test_5) {
  char a[100] = "str1/str2/str3/str4/str5/finish";
  char b[100] = "/";
  char c[100] = "str1/str2/str3/str4/str5/finish";
  char *expected = strtok(a, b);
  char *real = s21_strtok(c, b);
  ck_assert_str_eq(expected, real);
  while (expected != NULL && real != NULL) {
    expected = strtok(NULL, b);
    real = s21_strtok(NULL, b);
    if (expected == NULL)
      ck_assert_ptr_eq(expected, real);
    else
      ck_assert_str_eq(expected, real);
  }
  ck_assert_ptr_eq(expected, real);
}
END_TEST

START_TEST(strtok_test_6) {
  char a[100] = "str1/str2/str3/str4/str5/finish";
  char b[100] = "/t";
  char c[100] = "str1/str2/str3/str4/str5/finish";
  char *expected = strtok(a, b);
  char *real = s21_strtok(c, b);
  ck_assert_str_eq(expected, real);
  while (expected != NULL && real != NULL) {
    expected = strtok(NULL, b);
    real = s21_strtok(NULL, b);
    if (expected == NULL)
      ck_assert_ptr_eq(expected, real);
    else
      ck_assert_str_eq(expected, real);
  }
  ck_assert_ptr_eq(expected, real);
}
END_TEST

START_TEST(strtok_test_7) {
  char a[100] = "qwer\0tyqwed";
  char c[100] = "qwer\0tyqwed";
  char b[100] = "tyq";
  char *expected = strtok(a, b);
  char *real = s21_strtok(c, b);
  ck_assert_str_eq(expected, real);
  while (expected != NULL && real != NULL) {
    expected = strtok(NULL, b);
    real = s21_strtok(NULL, b);
    if (expected == NULL)
      ck_assert_ptr_eq(expected, real);
    else
      ck_assert_str_eq(expected, real);
  }
  ck_assert_ptr_eq(expected, real);
}
END_TEST

START_TEST(strtok_test_8) {
  char a[100] = "qwer\0tyqwed";
  char c[100] = "qwer\0tyqwed";
  char b[100] = "wed";
  char *expected = strtok(a, b);
  char *real = s21_strtok(c, b);
  ck_assert_str_eq(expected, real);
  while (expected != NULL && real != NULL) {
    expected = strtok(NULL, b);
    real = s21_strtok(NULL, b);
    if (expected == NULL)
      ck_assert_ptr_eq(expected, real);
    else
      ck_assert_str_eq(expected, real);
  }
  ck_assert_ptr_eq(expected, real);
}
END_TEST

START_TEST(strtok_test_9) {
  char a[100] = "qwer\0tyqwed";
  char c[100] = "qwer\0tyqwed";
  char b[100] = "yq";
  char *expected = strtok(a, b);
  char *real = s21_strtok(c, b);
  ck_assert_str_eq(expected, real);
}
END_TEST

START_TEST(strtok_test_10) {
  char a[100] = "qweryqwed";
  char c[100] = "qweryqwed";
  char b[100] = "\0";
  char *expected = strtok(a, b);
  char *real = s21_strtok(c, b);
  ck_assert_str_eq(expected, real);
}
END_TEST
START_TEST(strtok_test_11) {
  char a[100] = "str1/str2/str3/str4/str5/finish";
  char c[100] = "str1/str2/str3/str4/str5/finish";
  char b[100] = "/str";
  char *expected = strtok(a, b);
  char *real = s21_strtok(c, b);
  ck_assert_str_eq(expected, real);
  while (expected != NULL && real != NULL) {
    expected = strtok(NULL, b);
    real = s21_strtok(NULL, b);
    if (expected == NULL)
      ck_assert_ptr_eq(expected, real);
    else
      ck_assert_str_eq(expected, real);
  }
  ck_assert_ptr_eq(expected, real);
}
END_TEST

START_TEST(strtok_test_12) {
  char a[100] = "str1/str2/str3/str4/str5/finish";
  char c[100] = "str1/str2/str3/str4/str5/finish";
  char b[100] = "/q";
  char *expected = strtok(a, b);
  char *real = s21_strtok(c, b);
  ck_assert_str_eq(expected, real);
  while (expected != NULL && real != NULL) {
    expected = strtok(NULL, b);
    real = s21_strtok(NULL, b);
    if (expected == NULL)
      ck_assert_ptr_eq(expected, real);
    else
      ck_assert_str_eq(expected, real);
  }
  ck_assert_ptr_eq(expected, real);
}
END_TEST

START_TEST(strtok_test_13) {
  char a[100] = "str1/str2|tr3/str4|str5";
  char c[100] = "str1/str2|tr3/str4|str5";
  char b[100] = "/|";
  char *expected = strtok(a, b);
  char *real = s21_strtok(c, b);
  ck_assert_str_eq(expected, real);
}
END_TEST

START_TEST(strtok_test_14) {
  char a[100] = "str1/str2/str3/str4/str5/finish";
  char c[100] = "str1/str2/str3/str4/str5/finish";
  char b[100] = "";
  char *expected = strtok(a, b);
  char *real = s21_strtok(c, b);
  ck_assert_str_eq(expected, real);
  while (expected != NULL && real != NULL) {
    expected = strtok(NULL, b);
    real = s21_strtok(NULL, b);
    if (expected == NULL)
      ck_assert_ptr_eq(expected, real);
    else
      ck_assert_str_eq(expected, real);
  }
  ck_assert_ptr_eq(expected, real);
}
END_TEST

START_TEST(strtok_test_15) {
  char a[100] = "str1/str2/str3/str4/str5/finish";
  char c[100] = "str1/str2/str3/str4/str5/finish";
  char b[100] = "\0";
  char *expected = strtok(a, b);
  char *real = s21_strtok(c, b);
  ck_assert_str_eq(expected, real);
  while (expected != NULL && real != NULL) {
    expected = strtok(NULL, b);
    real = s21_strtok(NULL, b);
    if (expected == NULL)
      ck_assert_ptr_eq(expected, real);
    else
      ck_assert_str_eq(expected, real);
  }
  ck_assert_ptr_eq(expected, real);
}
END_TEST

Suite *s21_test_suite_strtok() {
  Suite *s;
  TCase *tc;
  s = suite_create("strtok");
  tc = tcase_create("strtok_case");

  tcase_add_test(tc, strtok_test_1);
  tcase_add_test(tc, strtok_test_2);
  tcase_add_test(tc, strtok_test_3);
  tcase_add_test(tc, strtok_test_4);
  tcase_add_test(tc, strtok_test_5);
  tcase_add_test(tc, strtok_test_6);
  tcase_add_test(tc, strtok_test_7);
  tcase_add_test(tc, strtok_test_8);
  tcase_add_test(tc, strtok_test_9);
  tcase_add_test(tc, strtok_test_10);
  tcase_add_test(tc, strtok_test_11);
  tcase_add_test(tc, strtok_test_12);
  tcase_add_test(tc, strtok_test_13);
  tcase_add_test(tc, strtok_test_14);
  tcase_add_test(tc, strtok_test_15);

  suite_add_tcase(s, tc);
  return s;
}