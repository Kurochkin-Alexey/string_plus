#include "s21_string.h"

// Компиляция gcc s21_sprintf.c ../s21_string.a -o my_sprintf -lm

// int main() {
//     int count_sym_my;
//     int count_sym_or;
//     char buffer[1000];
//     char buffer2[1000];
//     unsigned int value = 148;
//     int p_value = 0x123ABC;
//     int precision = 3;
//     double value_2 = 3.14159;
//     unsigned int number1 = 123123;
//     unsigned long number2 = 124349593;
//     float G_num = 3273298329832321134;
//     float g_num = 0.0000000000000000000003443677879705;
//     long double value_1 = 3.1415926535897932384626433832795028841971693; //
//     %.30Lf count_sym_or = sprintf(buffer, "%+-10d %-5c %-6c %10.10f %-8.3s
//     %-5.hu %% %5.3d %4.ld %.30Lf %5.2f %.5e %.5E %07d %015u %7u %-3u %-4f %-f
//     %-#10x %#015lX %18p %-+f %+-15.10d %+2.5d %8.5d %-7.7d %6.1d %15.5u
//     %-14.7u %e %20e %-20e %2.10e %30.2e %E %20E %-20E %+2.10E %+10.4E %+g
//     %+5g %+-11g %5.10g %-5o %10o %11.10o %-*d %*d %15.*f %#10o %-#5X %#5X
//     %-#6x %#6x %-#5E %#5E %-#6e %#6e %-e", 123, 'a', 'b', 8.548, "aboba",
//     253, 12345, (unsigned long)value, value_1, 8.946, 123.456, 123.456, 123,
//     -456, 3225, 0, 1.2, 0.00058, number1, number2, &p_value, 3.434, 12, 34,
//     55, 456, 555, 67, 23, 123.456, 123.123, 34.32, 4.343, 4.534, 123.456,
//     123.123, 34.32, 4.343, 34.34, 1.234, 3.22, 43.334, 1.32, 245, 31, 2424,
//     15, 32, 5, 1, 10, 2.33, 11, 23, 24, 25,
//     26, 8.98, 5.446, 5.3, 7.666, 1.2); count_sym_my = s21_sprintf(buffer2,
//     "%+-10d %-5c %-6c %10.10f %-8.3s %-5.hu %% %5.3d %4.ld %.30Lf %5.2f %.5e
//     %.5E %07d %015u %7u %-3u %-4f %-f %-#10x %#015lX %18p %-+f %+-15.10d
//     %+2.5d %8.5d %-7.7d %6.1d %15.5u %-14.7u %e %20e %-20e %2.10e %30.2e %E
//     %20E %-20E %+2.10E %+10.4E %+g %+5g %+-11g %5.10g %-5o %10o %11.10o %-*d
//     %*d %15.*f %#10o %-#5X %#5X %-#6x %#6x %-#5E %#5E %-#6e %#6e %-e", 123,
//     'a', 'b', 8.548, "aboba", 253, 12345, (unsigned long)value,
//     value_1, 8.946, 123.456, 123.456, 123, -456, 3225, 0, 1.2, 0.00058,
//     number1, number2, &p_value, 3.434, 12, 34, 55, 456, 555, 67, 23, 123.456,
//     123.123, 34.32, 4.343, 4.534, 123.456,
//     123.123, 34.32, 4.343, 34.34, 1.234, 3.22, 43.334, 1.32, 245, 31, 2424,
//     15, 32, 5, 1, 10, 2.33, 11, 23, 24, 25,
//     26, 8.98, 5.466, 5.3, 7.666, 1.2); printf("Orig:\n"); printf("%s\n",
//     buffer); printf("%d\n", count_sym_or); printf("Our:\n"); printf("%s\n",
//     buffer2); printf("%d\n", count_sym_my); return 0;
// }

int s21_sprintf(char *str, const char *format, ...) {
  s21_memset(str, 0, 1000);
  va_list args;
  va_start(args, format);
  int count = 0;
  for (int x = 0; format[x] != '\0'; x++) {
    if (format[x] == '%') {
      options opt = {'0', {0, 0, 0, 0, 0}, 0, -1, '0'};
      x = s21_parse_specifiers(x, format, &opt, &args);
      count += s21_processing_specifiers(str + count, format[x], &opt, &args);
    } else {
      str[count] = format[x];
      count++;
    }
  }
  va_end(args);
  return count;
}

int s21_parse_specifiers(int x, const char *format, options *opt,
                         va_list *args) {
  int width = 0;
  int accuracy = 0;
  // Обработка флагов
  for (x++; s21_strchr("-+#0 ", format[x]); x++) {
    s21_parse_flags(format[x], opt);
  }
  // Считывание ширины поля
  for (; (format[x] >= '0' && format[x] <= '9') || (format[x] == '*'); x++) {
    if (format[x] == '*') {
      width = va_arg(*args, int);
    } else {
      width = width * 10 + (format[x] - '0');
    }
  }
  opt->width = width;
  // Считывание точности
  if (format[x] == '.') {
    x++;
    for (; (format[x] >= '0' && format[x] <= '9') || (format[x] == '*'); x++) {
      if (format[x] == '*') {
        accuracy = va_arg(*args, int);
      } else {
        accuracy = accuracy * 10 + (format[x] - '0');
      }
    }
    opt->accuracy = accuracy;
  }
  // Обработка длины
  for (; s21_strchr("hlL", format[x]); x++) {
    opt->length = format[x];
  }
  return x;
}

void s21_parse_flags(char format, options *opt) {
  if (format == '-') opt->flag.minus = 1;
  if (format == '+') opt->flag.plus = 1;
  if (format == '0') opt->flag.zero = 1;
  if (format == ' ') opt->flag.space = 1;
  if (format == '#') opt->flag.diez = 1;
}

int s21_processing_specifiers(char *str, char symbol, options *opt,
                              va_list *args) {
  int i_val;
  char c_val;
  double f_val, e_val;
  if (symbol == 'd') {
    switch (opt->length) {
      case 'h':
        i_val = (short)va_arg(*args, int);
        break;
      case 'l':
        i_val = va_arg(*args, long);
        break;
      default:
        i_val = va_arg(*args, int);
        break;
    }
    s21_specifier_d(str, opt, i_val);
  }
  if (symbol == 'c') {
    c_val = va_arg(*args, int);
    s21_specifier_c(str, opt, c_val);
  }
  if (symbol == 'f') {
    switch (opt->length) {
      case 'L':
        f_val = va_arg(*args, long double);
        break;
      default:
        f_val = va_arg(*args, double);
        break;
    }
    s21_specifier_f(str, opt, f_val);
  }
  if (symbol == 's') {
    s21_specifier_s(str, args, opt);
  }
  if (symbol == 'u') {
    s21_specifier_u(str, args, opt);
  }
  if (symbol == '%') {
    s21_strcat(str, "%");
  }
  if (symbol == 'e') {
    switch (opt->length) {
      case 'L':
        e_val = va_arg(*args, long double);
        break;
      default:
        e_val = va_arg(*args, double);
        break;
    }
    s21_specifier_e(str, e_val, opt, 1);
  }
  if (symbol == 'E') {
    switch (opt->length) {
      case 'L':
        e_val = va_arg(*args, long double);
        break;
      default:
        e_val = va_arg(*args, double);
        break;
    }
    s21_specifier_e(str, e_val, opt, 2);
  }
  if (symbol == 'x') {
    s21_specifier_x(str, args, opt);
  }
  if (symbol == 'X') {
    s21_specifier_X(str, args, opt);
  };
  if (symbol == 'p') {
    s21_specifier_p(str, args, opt);
  }
  if (symbol == 'g' || symbol == 'G') {
    s21_specifier_g(str, opt, args);
  }
  if (symbol == 'o') {
    s21_specifier_o(str, args, opt);
  }
  return s21_strlen(str);
}

void s21_specifier_X(char *str, va_list *args, options *opt) {
  unsigned int X_val;
  char hex_digit[MAX_UINTPTR_T_HEX_LENGTH] = "\0";
  switch (opt->length) {
    case 'h':
      X_val = (unsigned int)(unsigned short)va_arg(*args, int);
      break;
    case 'l':
      X_val = va_arg(*args, unsigned long);
      break;
    default:
      X_val = va_arg(*args, unsigned int);
      break;
  }

  s21_specifier_hex(hex_digit, X_val, S21_FALSE);

  int value_len = s21_strlen(hex_digit);
  int prefix_len = 0;
  if (X_val != 0 && opt->flag.diez == 1) {
    if (!opt->flag.zero && !opt->flag.minus) {
      s21_process_width(str, opt, value_len + 2);
    }
    s21_strcat(str, "0X");
    prefix_len = 2;  // Длина префикса "0X"
  }
  int total_len = value_len + prefix_len;
  if (opt->flag.minus == 1) {
    s21_strcat(str, hex_digit);
    s21_process_width(str + total_len, opt,
                      total_len);  // Учитываем общую длину вывода
  } else {
    if (opt->flag.diez == 1) {
      s21_process_null(str + prefix_len, opt, value_len + 2);
    } else {
      s21_process_width(str, opt, total_len);
      s21_process_null(str + prefix_len, opt, value_len);
    }
    s21_strcat(str, hex_digit);
  }
}

void s21_specifier_x(char *str, va_list *args, options *opt) {
  unsigned int x_val;
  char hex_digit[MAX_UINTPTR_T_HEX_LENGTH] = "\0";
  switch (opt->length) {
    case 'h':
      x_val = (unsigned int)(unsigned short)va_arg(*args, int);
      break;
    case 'l':
      x_val = va_arg(*args, unsigned long);
      break;
    default:
      x_val = va_arg(*args, unsigned int);
      break;
  }

  s21_specifier_hex(hex_digit, x_val, S21_TRUE);

  int value_len = s21_strlen(hex_digit);
  int prefix_len = 0;
  if (x_val != 0 && opt->flag.diez == 1) {
    if (!opt->flag.zero && !opt->flag.minus) {
      s21_process_width(str, opt, value_len + 2);
    }
    s21_strcat(str, "0x");
    prefix_len = 2;  // Длина префикса "0X"
  }
  int total_len = value_len + prefix_len;
  if (opt->flag.minus == 1) {
    s21_strcat(str, hex_digit);
    s21_process_width(str + total_len, opt,
                      total_len);  // Учитываем общую длину вывода
  } else {
    if (opt->flag.diez == 1) {
      s21_process_null(str + prefix_len, opt, value_len + 2);
    } else {
      s21_process_width(str, opt, total_len);
      s21_process_null(str + prefix_len, opt, value_len);
    }
    s21_strcat(str, hex_digit);
  }
}

void s21_specifier_p(char *str, va_list *args, options *opt) {
  char hex_digit[MAX_UINTPTR_T_HEX_LENGTH] = "\0";
  ;
  char pointer_str[MAX_UINTPTR_T_HEX_LENGTH + 2] = "0x";

  uintptr_t val_ptr = va_arg(*args, uintptr_t);
  s21_specifier_hex(hex_digit, val_ptr, S21_TRUE);
  s21_strcat(pointer_str, hex_digit);

  int value_len = s21_strlen(pointer_str);
  if (opt->flag.minus == 1) {
    s21_strcat(str, pointer_str);
    s21_process_width(str + value_len, opt,
                      value_len);  // Учитываем количество выведенных цифр
  }
  if (opt->flag.minus == 0) {
    s21_process_width(str, opt, value_len);
    s21_strcat(str, pointer_str);
  }
}

void s21_specifier_hex(char *str, uintptr_t val, int is_lower) {
  char tmp[2];
  const char *base;
  if (is_lower) {
    base = "0123456789abcdef";
  } else {
    base = "0123456789ABCDEF";
  }
  if (val > 15) {
    s21_specifier_hex(str, val / 16,
                      is_lower);  // Только один вызов для старшего разряда
    val %= 16;  // Получаем младший разряд
  }
  tmp[0] = base[val];
  tmp[1] = '\0';
  s21_strcat(str, tmp);
}

void s21_specifier_e(char *str, double number, options *opt, int rz) {
  int num_digits = 12;
  if (opt->accuracy > -1) {
    opt->width += num_digits - 6 - opt->accuracy;
    if (opt->accuracy == 0) {
      opt->width++;
    }
    if (opt->flag.minus == 1) {
      s21_process_plus(str, opt, (int)number);
      s21_processing_exp(str, number, opt, rz);
      if (opt->width > opt->accuracy)
        s21_process_width(str + (opt->accuracy + 6), opt, num_digits);
    } else {
      if (opt->width > num_digits) {
        s21_process_width(str, opt, num_digits);
      }
      s21_process_plus(str, opt, (int)number);
      s21_processing_exp(str + (opt->width - num_digits), number, opt, rz);
    }
  } else {
    if (opt->flag.minus == 1) {
      s21_process_plus(str, opt, (int)number);
      s21_processing_exp(str, number, opt, rz);
      s21_process_width(str + num_digits, opt, num_digits);
    } else {
      if (opt->width > num_digits) {
        s21_process_width(str, opt, num_digits);
      }
      s21_process_plus(str, opt, (int)number);
      s21_processing_exp(str, number, opt, rz);
    }
  }
}

int s21_double_to_str(char *str, double a) {
  char tmp[2];
  int count_position = 0;
  int flag = 1;
  while (flag == 1) {
    int digit;
    if (a >= 10) {
      digit = fmodl(a, 10);
      a = (a - digit) / 10;
    } else {
      digit = a;
      flag = 0;
    }
    tmp[0] = digit + '0';
    tmp[1] = '\0';
    s21_strncat(str, tmp, 1);

    count_position++;
  }
  return count_position;
}

void s21_exp_to_str(char *str, double right_size, int accuracy, int rz,
                    int nt) {
  char temp_char[2];
  right_size = s21_round_to_precision(right_size, accuracy);
  while (*str != '\0') str++;
  for (int i = 0; i < accuracy; i++) {
    right_size *= 10;
    int digit = (int)(right_size);
    temp_char[0] = digit + '0';  // Преобразуем цифру в символ
    temp_char[1] = '\0';
    s21_strncat(str, temp_char, 1);  // Добавляем символ к строке
    right_size -= digit;
  }
  if (rz == 1)
    s21_strcat(str, "e");
  else
    s21_strcat(str, "E");
  if (nt >= 0)
    s21_strcat(str, "+");
  else {
    s21_strcat(str, "-");
    nt = nt * -1;
  }
  s21_strcat(str, "0");
  char temp_char2 = nt + '0';
  s21_strncat(str, &temp_char2, 1);
}

void s21_processing_exp(char *str, double number, options *opt, int rz) {
  int accuracy = 6;
  if (opt->accuracy > -1) {
    accuracy = opt->accuracy;
  }
  int count_position = 0;
  int nt = 0;
  if (number < 0) {
    number = number * -1;
    s21_strcat(str, "-");
    count_position++;
  }
  if (number != 0) {
    if (number < 1) {
      while (number < 1) {
        number *= 10;
        nt--;
      }
    } else {
      while (number > 10) {
        number /= 10;
        nt++;
      }
    }
  }

  long double right_size = 0;
  long double left_size = 0;
  right_size = modfl(number, &left_size);
  left_size = roundl(left_size);
  count_position = s21_double_to_str(str + count_position, left_size);
  if (opt->accuracy != 0 || opt->flag.diez == 1) s21_strcat(str, ".");
  s21_exp_to_str(str + count_position, right_size, accuracy, rz, nt);
}

void s21_specifier_u(char *str, va_list *args, options *opt) {
  unsigned int num;
  switch (opt->length) {
    case 'h':
      num = (unsigned int)(unsigned short)va_arg(*args, int);
      break;
    case 'l':
      num = va_arg(*args, unsigned long);
      break;
    default:
      num = va_arg(*args, unsigned int);
      break;
  }
  if (opt->flag.minus == 1) {
    s21_process_u(str, num, opt);
  }
  if (opt->flag.minus == 0) {
    s21_process_u(str, num, opt);
  }
}

void s21_process_u(char *str, unsigned int num, options *opt) {
  int num_digits = s21_id_count_number(num);
  if (num == 0) {
    *str++ = '0';  // Если число ноль, просто добавляем символ '0' в строку
    *str = '\0';   // Завершаем строку
  }
  char temp_str[100];  // Временный буфер для хранения символов числа
  int index = 0;
  // Преобразуем число в строку, начиная с конца
  while (num > 0) {
    temp_str[index++] = num % 10 + '0';
    num /= 10;
  }
  int diff = 0;
  if (opt->flag.zero) {
    diff = opt->width - index;
    for (int i = 0; i < diff; i++) {
      *str++ = '0';
    }
  } else if (!opt->flag.minus) {
    // Добавляем пробелы перед числом, если флаг минус не установлен
    if (opt->accuracy > num_digits) {
      opt->width -= (opt->accuracy - num_digits);
    }
    diff = opt->width - index;
    for (int i = 0; i < diff; i++) {
      *str++ = ' ';
    }
  }
  if (opt->accuracy > num_digits) {
    for (int i = 0; i < (opt->accuracy - num_digits); i++) {
      *str++ = '0';
    }
  }
  // Копируем символы из временного буфера в строку str в правильном порядке
  while (index > 0) {
    *str++ = temp_str[--index];
  }
  if (opt->flag.minus) {
    if (opt->accuracy > num_digits) {
      num_digits += (opt->accuracy - num_digits);
    }
    diff = opt->width - index -
           num_digits;  // Теперь diff содержит количество пробелов после числа
    for (int i = 0; i < diff; i++) {
      *str++ = ' ';
    }
  }
  *str = '\0';
}

void s21_specifier_s(char *str, va_list *args, options *opt) {
  char *s = va_arg(*args, char *);
  int len = s21_strlen(s);
  if (opt->accuracy > -1) {
    len = opt->accuracy;
  }
  int padding = opt->width - len;
  if (padding < 0) {
    padding = 0;
  }

  if (!opt->flag.minus) {
    for (int i = 0; i < padding; i++) {
      *str++ = ' ';
    }
  }

  s21_strcpy(str, s);
  str += len;  // Переместить указатель на конец скопированной строки

  if (opt->flag.minus) {
    for (int i = 0; i < padding; i++) {
      *str++ = ' ';
    }
  }
}

char *s21_strcpy(char *dest, const char *source) {
  char *ptr = dest;

  while (*source != '\0') {
    *ptr = *source;
    ptr++;
    source++;
  }
  *ptr = '\0';

  return dest;
}

char *s21_strcat(char *dest, const char *source) {
  char *ptr = dest;

  while (*ptr != '\0') {
    ptr++;
  }
  while (*source != '\0') {
    *ptr = *source;
    ptr++;
    source++;
  }
  *ptr = '\0';

  return dest;
}

void s21_specifier_f(char *str, options *opt, double f_val) {
  int num_digits = 8;
  // Если установлен флаг минус, то сначала выводим число, потом пробелы
  if (opt->width < opt->accuracy) opt->width = opt->accuracy;
  if (opt->accuracy > -1) {
    opt->width += num_digits - 2 - opt->accuracy;
    if (opt->accuracy == 0) {
      opt->width++;
    }
    if (opt->flag.minus == 1) {
      s21_process_plus(str, opt, (int)f_val);
      s21_process_float(str, opt, f_val);
      if (opt->flag.plus) {
        num_digits += 1;
        s21_process_width(str + num_digits, opt, num_digits);
      }
    } else {
      if (opt->width > num_digits) {
        if (opt->flag.plus) {
          s21_process_width(str, opt,
                            num_digits + 1);  // Учитываем количество пробелов
        } else {
          s21_process_width(str, opt, num_digits);
        }
      }
      s21_process_plus(str, opt, (int)f_val);
      s21_process_float(str + (opt->width - num_digits), opt, f_val);
    }
  } else {
    if (opt->flag.minus == 1) {
      s21_process_plus(str, opt, (int)f_val);
      s21_process_float(str, opt, f_val);
      if (opt->flag.plus) {
        num_digits += 1;
        s21_process_width(str + num_digits, opt, num_digits);
      }
    } else {
      if (opt->width > num_digits) {
        if (opt->flag.plus) {
          s21_process_width(str, opt,
                            num_digits + 1);  // Учитываем количество пробелов
        } else {
          s21_process_width(str, opt, num_digits);
        }
      }
      s21_process_plus(str, opt, (int)f_val);
      s21_process_float(str, opt, f_val);
    }
  }
}

void s21_process_float(char *str, options *opt, double f_val) {
  int accuracy = 6;
  double fraction_part;
  if (opt->accuracy > -1) {
    accuracy = opt->accuracy;
  }
  int int_part = (int)f_val;
  fraction_part = f_val - int_part;
  fraction_part = s21_round_to_precision(fraction_part, opt->accuracy);
  if (int_part != 0) {
    s21_process_int(str, int_part);
    while (*str != '\0') str++;
  } else {
    s21_strcat(str, "0");
  }
  if (opt->accuracy > 0 || opt->accuracy == -1) {
    s21_strcat(str, ".");
  }
  while (*str != '\0') str++;
  for (int i = 0; i < accuracy; i++) {
    fraction_part *= 10;
    int digit = (int)(fraction_part + 0.00000003);
    char temp_char = digit + '0';  // Преобразуем цифру в символ
    s21_strncat(str, &temp_char, 1);  // Добавляем символ к строке
    fraction_part -= digit;
  }
}

void s21_process_int(char *str, int i_val) {
  int tmp = i_val;
  int digits[100];
  int index = 0;
  char temp_str[2];  // Буфер для временного хранения символов
  if (i_val < 0) {
    tmp = -tmp;
    s21_strcat(str, "-");
  }
  while (tmp > 0) {
    digits[index++] = tmp % 10;
    tmp /= 10;
  }
  while (index > 0) {
    temp_str[0] = digits[--index] + '0';  // Преобразуем цифру в символ
    temp_str[1] = '\0';  // Устанавливаем завершающий нуль
    s21_strncat(str, temp_str, 1);  // Добавляем один символ к строке
  }
}

void s21_specifier_d(char *str, options *opt, long double i_val) {
  int num_digits = s21_id_count_number(i_val);
  if (opt->flag.minus == 1) {
    s21_process_plus(str, opt, i_val);
    if (opt->accuracy > num_digits) {
      for (int i = 0; i < (opt->accuracy - num_digits); i++) {
        s21_strcat(str, "0");
      }
      s21_process_int(str + (opt->accuracy - num_digits), i_val);
      if (opt->flag.plus) {
        s21_process_width(str + opt->accuracy + 1, opt, opt->accuracy + 1);
      } else {
        s21_process_width(str + opt->accuracy, opt, opt->accuracy);
      }
    } else {
      s21_process_int(str, i_val);
      if (opt->flag.plus) {
        num_digits += 1;
      }
      s21_process_width(str + num_digits, opt, num_digits);
    }
  } else {
    if (opt->flag.plus) {
      if (opt->accuracy > num_digits) {
        s21_process_width(str, opt,
                          num_digits + (opt->accuracy - num_digits) + 1);
      } else {
        s21_process_width(str, opt, num_digits + 1);
      }
    } else {
      if (opt->accuracy > num_digits) {
        s21_process_width(str, opt, num_digits + (opt->accuracy - num_digits));
      } else {
        s21_process_width(str, opt, num_digits);
      }
    }
    s21_process_plus(str, opt, i_val);
    if (opt->accuracy > num_digits) {
      for (int i = 0; i < (opt->accuracy - num_digits); i++) {
        s21_strcat(str, "0");
      }
    }
    s21_process_int(str, i_val);
  }
}

void s21_process_plus(char *str, options *opt, int i_val) {
  if (opt->flag.plus == 1 && i_val >= 0) {
    s21_strcat(str, "+");
  }
}

void s21_process_null(char *str, options *opt, int num_digits) {
  if (opt->flag.zero) {
    int diff = opt->width - num_digits;
    if (diff < 0) diff = 0;
    for (int i = 0; i < diff; i++) {
      *str++ = '0';
    }
  }
}

void s21_specifier_c(char *str, options *opt, char c_val) {
  if (opt->flag.minus == 0) {
    s21_process_width(str, opt, 1);
    s21_strncat(str, &c_val, 1);
  }
  if (opt->flag.minus == 1) {
    s21_strncat(str, &c_val, 1);
    s21_process_width(str + 1, opt, 1);
  }
}

void s21_process_width(char *str, options *opt, int num_digits) {
  int diff = opt->width - num_digits;
  if (opt->flag.zero && opt->accuracy == -1) {
    for (int i = 0; i < diff; i++) {
      *str++ = '0';
    }
  } else {
    for (int i = 0; i < diff; i++) {
      *str++ = ' ';
    }
  }
  *str = '\0';  // Завершаем строку
}

int s21_id_count_number(long double val) {
  if (val < 0) {
    val = -val;  // Изменяем знак, если число отрицательное
  }
  if (val == 0) {
    return 1;  // Отдельно обрабатываем случай с нулем
  }
  int count = 0;
  while (val >= 1) {
    val /= 10;  // Делим число на 10, пока не достигнем нуля
    count++;  // Увеличиваем счётчик цифр
  }
  return count;
}

int s21_reverse_int(int val) {
  if (val < 0) {
    val = -val;  // Изменяем знак, если число отрицательное
  }
  if (val == 0) {
    return 0;  // Отдельно обрабатываем случай с нулем
  }
  int reversed = 0;
  while (val >= 1) {
    int digit = (int)fmodl(val, 10);  // Оставляем только последнюю цифру числа
    reversed =
        reversed * 10 +
        digit;  // Добавляем её к нашему числу, сдвигая предыдущие цифры влево
    val /= 10;  // Делим число на 10, убирая последнюю цифру
  }
  return reversed;
}

double s21_round_to_precision(double num, int precision) {
  if (fabs(num) < 1.0 / pow(10, precision)) {
    // Число близко к нулю, возвращаем его без изменений
    return num;
  } else {
    double scale = pow(10, precision);
    return round(num * scale) / scale;
  }
}

void s21_specifier_g(char *str, options *opt, va_list *args) {
  double g_val;
  if (opt->length == 'L')
    g_val = va_arg(*args, long double);
  else
    g_val = va_arg(*args, double);
  char str_e[1000];
  char str_f[1000];
  s21_memset(str_e, 0, 1000);
  s21_memset(str_f, 0, 1000);
  s21_process_float(str_f, opt, g_val);
  s21_processing_exp(str_e, g_val, opt, 1);
  if (opt->flag.diez == 0) {
    s21_delete_zero_f(str_f);
    s21_delete_zero_e(str_e + s21_strlen(str_e) - 1);
    if (s21_strlen(str_f) >= s21_strlen(str_e)) {
      if (opt->flag.minus == 0) {
        if (opt->flag.plus) {
          s21_process_width(str, opt, s21_strlen(str_e) + 2);
        } else {
          s21_process_width(str, opt, s21_strlen(str_e));
        }
      }
      s21_process_plus(str, opt, g_val);
      s21_strncat(str, str_e, s21_strlen(str_e));
      if (opt->flag.minus == 1)
        s21_process_width(str + s21_strlen(str_e), opt, s21_strlen(str_e));
    } else {
      opt->accuracy = 1;
      if (opt->flag.minus == 0) s21_process_width(str, opt, s21_strlen(str_f));
      s21_process_plus(str, opt, g_val);
      s21_strncat(str, str_f, s21_strlen(str_f));
      if (opt->flag.minus == 1) {
        if (opt->flag.plus) {
          s21_process_width(str + s21_strlen(str_f) + 1, opt,
                            s21_strlen(str_f) + 1);
        } else {
          s21_process_width(str + s21_strlen(str_f), opt, s21_strlen(str_f));
        }
      }
    }
  } else if (s21_strlen(str_f) > s21_strlen(str_e)) {
    s21_specifier_e(str, g_val, opt, 1);
  } else
    s21_specifier_f(str, opt, g_val);
}

void s21_delete_zero_f(char *str) {  //удаление лишних нулей - для g - Коля
  int len = s21_strlen(str) - 1;
  while (str[len] == '0') {
    len--;
  }
  len++;
  str[len] = '\0';
}

void s21_delete_zero_e(char *str) {
  char write[4];
  s21_memset(write, 0, 4);
  int len = s21_strlen(str) - 1;
  int count = 0;
  while (str[len] != 'e') {
    write[count] = str[len];
    count++;
    len--;
  }
  write[count] = str[len];
  count++;
  len--;
  while (str[len] == '0') {
    str[len] = '\0';
    len--;
  }
  len++;
  for (int i = count; i >= 0; i--) {
    str[len] = write[i];
    len++;
  }
  str[len] = '\0';
}

void s21_specifier_o(char *str, va_list *args, options *opt) {
  unsigned int o_val;
  switch (opt->length) {
    case 'h':
      o_val = va_arg(*args, unsigned int);
      break;
    case 'l':
      o_val = va_arg(*args, unsigned long);
      break;
    default:
      o_val = va_arg(*args, unsigned int);
      break;
  }
  int num_digits = s21_id_count_number(o_val);
  if (opt->width < opt->accuracy) opt->width = opt->accuracy;
  int accuracy = opt->accuracy;
  if (opt->accuracy == -1) {
    opt->accuracy = 0;
    accuracy = num_digits;
  }

  int width = opt->width;
  if (opt->flag.minus == 1) {
    while (accuracy > num_digits) {
      *str++ = '0';
      accuracy--;
    }
    s21_process_o(str, o_val);
    s21_process_width(str + num_digits, opt, opt->accuracy + num_digits);
  } else {
    while (width > accuracy + ((opt->flag.diez) && (o_val != 0))) {
      *str++ = ' ';
      width--;
    }
    while (accuracy > num_digits) {
      *str++ = '0';
      accuracy--;
    }
    if ((opt->flag.diez) && (o_val != 0) && (accuracy == num_digits)) {
      *str++ = '0';
    }
    s21_process_o(str, o_val);
  }
}

void s21_process_o(char *str, unsigned int o_val) {
  if (o_val == 0) {
    *str++ = '0';
    *str = '\0';
  }
  char temp_str[100];
  int index = 0;
  while (o_val > 0) {
    temp_str[index++] = o_val % 8 + '0';
    o_val /= 8;
  }
  while (index > 0) {
    *str++ = temp_str[--index];
  }
  *str = '\0';
}

void s21_revers_str(char *str) {
  char *start = str;
  char *end = str;
  char temp;
  while (*end != '\0') {
    end++;
  }
  end--;
  while (start < end) {
    temp = *start;
    *start = *end;
    *end = temp;

    start++;
    end--;
  }
}