#include "s21_tests.h"

START_TEST(strpbrk_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char *expected = strpbrk(s1, s2);
  char *result = s21_strpbrk(s1, s2);
  ck_assert((expected == NULL && result == NULL) ||
            strcmp(expected, result) == 0);
}
END_TEST

START_TEST(strpbrk_2) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  char *expected = strpbrk(s1, s2);
  char *result = s21_strpbrk(s1, s2);
  ck_assert((expected == NULL && result == NULL) ||
            strcmp(expected, result) == 0);
}
END_TEST

START_TEST(strpbrk_3) {
  char s1[] = "";
  char s2[] = "He";
  char *expected = strpbrk(s1, s2);
  char *result = s21_strpbrk(s1, s2);
  ck_assert((expected == NULL && result == NULL) ||
            strcmp(expected, result) == 0);
}
END_TEST

START_TEST(strpbrk_4) {
  char s1[] = "\0";
  char s2[] = "";
  char *expected = strpbrk(s1, s2);
  char *result = s21_strpbrk(s1, s2);
  ck_assert((expected == NULL && result == NULL) ||
            strcmp(expected, result) == 0);
}
END_TEST

START_TEST(strpbrk_5) {
  char s1[] = "";
  char s2[] = "";
  char *expected = strpbrk(s1, s2);
  char *result = s21_strpbrk(s1, s2);
  ck_assert((expected == NULL && result == NULL) ||
            strcmp(expected, result) == 0);
}
END_TEST

START_TEST(strpbrk_6) {
  char s1[] = "1242434246364377659";
  char s2[] = "364377659";
  char *expected = strpbrk(s1, s2);
  char *result = s21_strpbrk(s1, s2);
  ck_assert((expected == NULL && result == NULL) ||
            strcmp(expected, result) == 0);
}
END_TEST

Suite *s21_test_suite_strpbrk(void) {
  Suite *s = suite_create("s21_strpbrk");

  // Создание первого набора тестов
  TCase *tc1 = tcase_create("strpbrk_tc_1");
  tcase_add_test(tc1, strpbrk_1);
  tcase_add_test(tc1, strpbrk_2);
  tcase_add_test(tc1, strpbrk_3);
  tcase_add_test(tc1, strpbrk_4);
  tcase_add_test(tc1, strpbrk_5);
  tcase_add_test(tc1, strpbrk_6);

  // Добавление первого набора тестов в suite
  suite_add_tcase(s, tc1);

  return s;
}