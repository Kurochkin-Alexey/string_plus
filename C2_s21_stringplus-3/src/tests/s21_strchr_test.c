#include "s21_tests.h"

//базовый тест на нахождение символа
START_TEST(test_1) {
  char str1[] = "cucumber";
  char c = 'c';
  ck_assert_msg(strcmp(s21_strchr(str1, c), strchr(str1, c)) == 0,
                "Expected: %s\nActual: %s", s21_strchr(str1, c),
                strchr(str1, c));
}
END_TEST

//тест на нахлждение несуществующего в строке символа
START_TEST(test_2) {
  char str1[] = "cucumber";
  char c = 'd';
  char *s21_result = s21_strchr(str1, c);
  char *result = strchr(str1, c);

  ck_assert_msg((s21_result == NULL && result == NULL) ||
                    (strcmp(s21_result, result) == 0),
                "Expected: %s\nActual: %s", s21_result, result);
}
END_TEST

START_TEST(test_3) {
  char str1[] = "";
  char c = 'c';
  ck_assert_msg(s21_strchr(str1, c) == NULL && strchr(str1, c) == NULL,
                "Expected: %s\nActual: %s", s21_strchr(str1, c),
                strchr(str1, c));
}
END_TEST

Suite *s21_test_suite_strchr(void) {
  Suite *suite = suite_create("s21_strchr");
  TCase *tcase_core = tcase_create("s21_strchr_case");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);

  suite_add_tcase(suite, tcase_core);

  return suite;
}