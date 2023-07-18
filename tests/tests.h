#ifndef S21_TESTS_H_
#define S21_TESTS_H_

#include <check.h>

Suite *basic_suite(void);
Suite *comparison_suite(void);
Suite *arithmetic_suite(void);
Suite *determinant_suite(void);
Suite *inverse_suite(void);
Suite *other_operations_suite(void);

#endif  // S21_TESTS_H_