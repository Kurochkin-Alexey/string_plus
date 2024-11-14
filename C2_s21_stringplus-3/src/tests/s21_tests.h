#ifndef s21_tests
#define s21_tests

#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

Suite *s21_test_suite_memchr(void);
Suite *s21_test_suite_memcmp(void);
Suite *s21_test_suite_memcpy(void);
Suite *s21_test_suite_memset(void);
Suite *s21_test_suite_strchr(void);
Suite *s21_test_suite_strerror(void);
Suite *s21_test_suite_strncat(void);
Suite *s21_test_suite_strpbrk(void);
Suite *s21_test_suite_strlen(void);
Suite *s21_test_suite_strrchr(void);
Suite *s21_test_suite_strtok(void);
Suite *s21_test_suite_strstr(void);
Suite *s21_test_suite_strncpy(void);
Suite *s21_test_suite_strncmp(void);
Suite *s21_test_suite_strcspn(void);
Suite *s21_test_suite_sprintf(void);

Suite *test_insert(void);
Suite *test_to_lower(void);
Suite *test_to_upper(void);
Suite *test_trim(void);

#endif