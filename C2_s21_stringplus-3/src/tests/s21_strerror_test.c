#include <stdlib.h>

#include "s21_tests.h"

START_TEST(strerror_1) {
  for (int i = 0; i < 150; i++) {
    ck_assert_str_eq(s21_strerror(i), s21_strerror(i));
  }
}
END_TEST

START_TEST(strerror_2) {
  int n = -1;
  ck_assert_str_eq(s21_strerror(n), s21_strerror(n));
}
END_TEST

Suite *s21_test_suite_strerror(void) {
  Suite *s = suite_create("s21_strerror");
  TCase *tc = tcase_create("strerror_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);

  return s;
}