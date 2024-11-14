#ifndef S21_STRING_H
#define S21_STRING_H

#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_NULL ((void *)0)
#define S21_TRUE 1
#define S21_FALSE 0
typedef unsigned long s21_size_t;
#define MAX_UINTPTR_T_HEX_LENGTH 19

typedef struct {
  int minus;
  int plus;
  int space;
  int zero;
  int diez;
} flags;

typedef struct {
  char specifier;
  flags flag;
  int width;
  int accuracy;
  char length;
} options;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
s21_size_t s21_strlen(const char *str);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strerror(int errnum);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strncpy(char *dest, const char *src, size_t n);
char *s21_strcpy(char *dest, const char *source);
int s21_strncmp(const char *str1, const char *str2, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strcat(char *dest, const char *source);
void *s21_memset(void *str, int c, s21_size_t n);

int s21_sprintf(char *str, const char *format, ...);
int s21_parse_specifiers(int x, const char *format, options *opt,
                         va_list *args);
void s21_parse_flags(char format, options *opt);
int s21_processing_specifiers(char *str, char symbol, options *opt,
                              va_list *args);

void s21_specifier_X(char *str, va_list *args, options *opt);
void s21_specifier_x(char *str, va_list *args, options *opt);
void s21_specifier_p(char *str, va_list *args, options *opt);
void s21_specifier_hex(char *str, uintptr_t val, int is_lower);
void s21_specifier_u(char *str, va_list *args, options *opt);
void s21_specifier_s(char *str, va_list *args, options *opt);
void s21_specifier_d(char *str, options *opt, long double i_val);
void s21_specifier_c(char *str, options *opt, char c_val);
void s21_specifier_o(char *str, va_list *args, options *opt);
void s21_specifier_g(char *str, options *opt, va_list *args);
void s21_specifier_e(char *str, double number, options *opt, int rz);
void s21_specifier_f(char *str, options *opt, double f_val);

void s21_process_width(char *str, options *opt, int num_digits);
void s21_process_plus(char *str, options *opt, int i_val);
void s21_process_null(char *str, options *opt, int num_digits);

void s21_process_u(char *str, unsigned int num, options *opt);
void s21_process_float(char *str, options *opt, double f_val);
void s21_process_int(char *str, int i_val);
void s21_process_o(char *str, unsigned int o_val);

int s21_id_count_number(long double count);
int s21_reverse_int(int val);
double s21_round_to_precision(double num, int precision);
void s21_revers_str(char *str);
int number_to_str_with_accuracy(char *buffer, unsigned long long value,
                                int accuracy);

int s21_double_to_str(char *str, double a);
void s21_exp_to_str(char *str, double right_size, int accuracy, int rz, int nt);
void s21_processing_exp(char *str, double number, options *opt, int rz);
void s21_delete_zero_e(char *str);
void s21_delete_zero_f(char *str);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
char *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif