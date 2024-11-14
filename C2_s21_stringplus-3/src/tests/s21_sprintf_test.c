// #include "s21_tests.h"

// START_TEST(s21_sprintf_test_1) {
//   char buffer[1000];
//   char buffer2[1000];
//   unsigned int value = 148;
//   int p_value = 0x123ABC;
//   unsigned int number1 = 123123;
//   unsigned long number2 = 124349593;
//   long double value_1 = 3.1415926535897932384626433832795028841971693;
//   int count_sym_or = sprintf(
//       buffer,
//       "%+-10d %-5c %-6c %10.10f %-8.3s %-5.hu %% %5.3d %4.ld %.30Lf %5.2f %.5e "
//       "%.5E %07d %015u%7u %-3u %-4f %-f %-#10x %#015lX %18p %hd %hx %X %hX %#X "
//       "%-X %lx %#x %-13p %lu %s %2s %10s %.f %-+15f %-+.1f %+12f %+10.3f %12f "
//       "%+6d %10c %+-10d %-5c %-6c %10.10f %-8.3s %-5.hu %% %5.3d %4.ld %.30Lf "
//       "%5.2f %.5e %.5E %07d %015u %7u %-3u %-4f %-f %-#10x %#015lX %18p %-+f "
//       "%+-15.10d %+2.5d %8.5d %-7.7d %6.1d %15.5u %-14.7u %e %20e %-20e %2.10e "
//       "%30.2e %E %20E %-20E %+2.10E %+10.4E %+g %+5g %+-11g %5.10g %-5o %10o "
//       "%11.10o %-*d %*d %15.*f %#10o %-#5X",
//       123, 'a', 'b', 8.548, "aboba", 253, 12345, (unsigned long)value, value_1,
//       8.946, 123.456, 123.456, 123, -456, 3225, 0, 1.2, 0.00058, number1,
//       number2, &p_value, 789, 3243, 768, 888, 212, 545, (unsigned long)value,
//       920, &p_value, number2, "\0", "aboba", "aboba", 3.323, -4.545, 4.343,
//       5.234, 3.667, 8.438, -76, 'b', 123, 'a', 'b', 8.548, "aboba", 253, 12345,
//       (unsigned long)value, value_1, 8.946, 123.456, 123.456, 123, -456, 3225,
//       0, 1.2, 0.00058, number1, number2, &p_value, 3.434, 12, 34, 55, 456, 555,
//       67, 23, 123.456, 123.123, 34.32, 4.343, 4.534, 123.456, 123.123, 34.32,
//       4.343, 34.34, 1.234, 3.22, 43.334, 1.32, 245, 31, 2424, 15, 32, 5, 1, 10,
//       2.33, 11, 23);
//   int count_sym_my = s21_sprintf(
//       buffer2,
//       "%+-10d %-5c %-6c %10.10f %-8.3s %-5.hu %% %5.3d %4.ld %.30Lf %5.2f %.5e "
//       "%.5E %07d %015u%7u %-3u %-4f %-f %-#10x %#015lX %18p %hd %hx %X %hX %#X "
//       "%-X %lx %#x %-13p %lu %s %2s %10s %.f %-+15f %-+.1f %+12f %+10.3f %12f "
//       "%+6d %10c %+-10d %-5c %-6c %10.10f %-8.3s %-5.hu %% %5.3d %4.ld %.30Lf "
//       "%5.2f %.5e %.5E %07d %015u %7u %-3u %-4f %-f %-#10x %#015lX %18p %-+f "
//       "%+-15.10d %+2.5d %8.5d %-7.7d %6.1d %15.5u %-14.7u %e %20e %-20e %2.10e "
//       "%30.2e %E %20E %-20E %+2.10E %+10.4E %+g %+5g %+-11g %5.10g %-5o %10o "
//       "%11.10o %-*d %*d %15.*f %#10o %-#5X",
//       123, 'a', 'b', 8.548, "aboba", 253, 12345, (unsigned long)value, value_1,
//       8.946, 123.456, 123.456, 123, -456, 3225, 0, 1.2, 0.00058, number1,
//       number2, &p_value, 789, 3243, 768, 888, 212, 545, (unsigned long)value,
//       920, &p_value, number2, "\0", "aboba", "aboba", 3.323, -4.545, 4.343,
//       5.234, 3.667, 8.438, -76, 'b', 123, 'a', 'b', 8.548, "aboba", 253, 12345,
//       (unsigned long)value, value_1, 8.946, 123.456, 123.456, 123, -456, 3225,
//       0, 1.2, 0.00058, number1, number2, &p_value, 3.434, 12, 34, 55, 456, 555,
//       67, 23, 123.456, 123.123, 34.32, 4.343, 4.534, 123.456, 123.123, 34.32,
//       4.343, 34.34, 1.234, 3.22, 43.334, 1.32, 245, 31, 2424, 15, 32, 5, 1, 10,
//       2.33, 11, 23);
//   ck_assert_int_eq(count_sym_my, count_sym_or);
// }
// END_TEST

// Suite *s21_test_suite_sprintf(void) {
//   Suite *s;
//   TCase *tc_core;

//   s = suite_create("s21_sprintf");

//   tc_core = tcase_create("s21_sprintf_case");

//   // Добавление тестов в кейс
//   tcase_add_test(tc_core, s21_sprintf_test_1);
//   // Добавление кейса в набор
//   suite_add_tcase(s, tc_core);

//   return s;
// }


#include "s21_tests.h"

START_TEST(s21_sprintf_test_1) {
  char buffer[1000];
  char buffer2[1000];
  unsigned int value = 148;
  int p_value = 0x123ABC;
  unsigned int number1 = 123123;
  unsigned long number2 = 124349593;
  long double value_1 = 3.1415926535897932384626433832795028841971693;
  int count_sym_or = sprintf(
      buffer,
      "%+-10d %-5c %-6c %10.10f %-8.3s %-5.hu %% %5.3d %4.ld %.30Lf %5.2f %.5e "
      "%.5E %07d %015u%7u %-3u %-4f %-f %-#10x %#015lX %18p %hd %hx %X %hX %#X "
      "%-X %lx %#x %-13p %lu %s %2s %10s %.f %-+15f %-+.1f %+12f %+10.3f %12f "
      "%+6d %10c %+-10d %-5c %-6c %10.10f %-8.3s %-5.hu %% %5.3d %4.ld %.30Lf "
      "%5.2f %.5e %.5E %07d %015u %7u %-3u %-4f %-f %-#10x %#015lX %18p %-+f "
      "%+-15.10d %+2.5d %8.5d %-7.7d %6.1d %15.5u %-14.7u %e %20e %-20e %2.10e "
      "%30.2e %E %20E %-20E %+2.10E %+10.4E %+g %+-11g %5.10g %-5o %10o ",
      123, 'a', 'b', 8.548, "aboba", (unsigned short)253, 12345, (unsigned long)value, value_1,
      8.946, 123.456, 123.456, 123, -456, 3225, 0, 1.2, 0.00058, number1,
      number2, &p_value, (short)789, (unsigned short)3243, 768, (unsigned short)888, 212, 545, (unsigned long)value,
      920, &p_value, number2, "\0", "aboba", "aboba", 3.323, -4.545, 4.343,
      5.234, 3.667, 8.438, -76, 'b', 123, 'a', 'b', 8.548, "aboba", (unsigned short)253, 12345,
      (unsigned long)value, value_1, 8.946, 123.456, 123.456, 123, -456, 3225,
      0, 1.2, 0.00058, number1, number2, &p_value, 3.434, 12, 34, 55, 456, 555,
      67, 23, 123.456, 123.123, 34.32, 4.343, 4.534, 123.456, 123.123, 34.32,
      4.343, 34.34, 3.22, 43.334, 1.32, 245, 31);
  int count_sym_my = s21_sprintf(
      buffer2,
      "%+-10d %-5c %-6c %10.10f %-8.3s %-5.hu %% %5.3d %4.ld %.30Lf %5.2f %.5e "
      "%.5E %07d %015u%7u %-3u %-4f %-f %-#10x %#015lX %18p %hd %hx %X %hX %#X "
      "%-X %lx %#x %-13p %lu %s %2s %10s %.f %-+15f %-+.1f %+12f %+10.3f %12f "
      "%+6d %10c %+-10d %-5c %-6c %10.10f %-8.3s %-5.hu %% %5.3d %4.ld %.30Lf "
      "%5.2f %.5e %.5E %07d %015u %7u %-3u %-4f %-f %-#10x %#015lX %18p %-+f "
      "%+-15.10d %+2.5d %8.5d %-7.7d %6.1d %15.5u %-14.7u %e %20e %-20e %2.10e "
      "%30.2e %E %20E %-20E %+2.10E %+10.4E %+g %+-11g %5.10g %-5o %10o ",
      123, 'a', 'b', 8.548, "aboba", 253, 12345, (unsigned long)value, value_1,
      8.946, 123.456, 123.456, 123, -456, 3225, 0, 1.2, 0.00058, number1,
      number2, &p_value, 789, 3243, 768, 888, 212, 545, (unsigned long)value,
      920, &p_value, number2, "\0", "aboba", "aboba", 3.323, -4.545, 4.343,
      5.234, 3.667, 8.438, -76, 'b', 123, 'a', 'b', 8.548, "aboba", 253, 12345,
      (unsigned long)value, value_1, 8.946, 123.456, 123.456, 123, -456, 3225,
      0, 1.2, 0.00058, number1, number2, &p_value, 3.434, 12, 34, 55, 456, 555,
      67, 23, 123.456, 123.123, 34.32, 4.343, 4.534, 123.456, 123.123, 34.32,
      4.343, 34.34, 3.22, 43.334, 1.32, 245, 31, 2424, 15, 32, 5, 1, 10,
      2.33, 11, 23);
  ck_assert_int_eq(count_sym_my, count_sym_or);
}
END_TEST

Suite *s21_test_suite_sprintf(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_sprintf");

  tc_core = tcase_create("s21_sprintf_case");

  // Добавление тестов в кейс
  tcase_add_test(tc_core, s21_sprintf_test_1);
  // Добавление кейса в набор
  suite_add_tcase(s, tc_core);

  return s;
}