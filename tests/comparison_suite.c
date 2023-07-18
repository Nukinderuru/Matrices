#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"
#include "tests.h"

// Compare equal matrices
START_TEST(compare_1) {
  int rows = 2;
  int columns = 2;
  matrix_t A;
  matrix_t B;
  int status_1 = s21_create_matrix(rows, columns, &A);
  int status_2 = s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i + j;
    }
  int is_equal = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status_1, 0);
  ck_assert_int_eq(status_2, 0);
  ck_assert_int_eq(is_equal, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// Compare matrices equal in size, but with different elements
START_TEST(compare_2) {
  int rows = 3;
  int columns = 3;
  matrix_t A;
  matrix_t B;
  int status_1 = s21_create_matrix(rows, columns, &A);
  int status_2 = s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i + j + 1;
    }
  int is_equal = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status_1, 0);
  ck_assert_int_eq(status_2, 0);
  ck_assert_int_eq(is_equal, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(compare_3) {
  int rows = 4;
  int columns = 4;
  matrix_t A;
  matrix_t B;
  int status_1 = s21_create_matrix(rows, columns, &A);
  int status_2 = s21_create_matrix(rows, columns, &B);
  A.matrix[0][0] = 1.1234567;
  A.matrix[0][1] = 1.1234567;
  A.matrix[0][2] = 1.1234567;
  A.matrix[0][3] = 1.1234567;
  A.matrix[1][0] = 1.1234567;
  A.matrix[1][1] = 1.12345678;
  A.matrix[1][2] = 1.12345678;
  A.matrix[1][3] = 1.12345678;
  A.matrix[2][0] = 1.1234567;
  A.matrix[2][1] = 1.12345678;
  A.matrix[2][2] = 1.12345678;
  A.matrix[2][3] = 1.12345678;
  A.matrix[3][0] = 1.1234567;
  A.matrix[3][1] = 1.12345678;
  A.matrix[3][2] = 1.12345678;
  A.matrix[3][3] = 1.12345678;

  B.matrix[0][0] = 1.1234567;
  B.matrix[0][1] = 1.1234567;
  B.matrix[0][2] = 1.12345678;
  B.matrix[0][3] = 1.1234567;
  B.matrix[1][0] = 1.12345674;
  B.matrix[1][1] = 1.1234567;
  B.matrix[1][2] = 1.12345678;
  B.matrix[1][3] = 1.12345678;
  B.matrix[2][0] = 1.1234567;
  B.matrix[2][1] = 1.12345678;
  B.matrix[2][2] = 1.12345678;
  B.matrix[2][3] = 1.1234567;
  B.matrix[3][0] = 1.12345671;
  B.matrix[3][1] = 1.12345678;
  B.matrix[3][2] = 1.1234567;
  B.matrix[3][3] = 1.12345678;

  int is_equal = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status_1, 0);
  ck_assert_int_eq(status_2, 0);
  ck_assert_int_eq(is_equal, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// Not equal matrices
START_TEST(compare_4) {
  int rows = 3;
  int columns = 3;
  matrix_t A;
  matrix_t B;
  int status_1 = s21_create_matrix(rows, columns, &A);
  int status_2 = s21_create_matrix(rows + 1, columns - 1, &B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
    }
  for (int i = 0; i < rows + 1; i++) {
    for (int j = 0; j < columns - 1; j++) {
      B.matrix[i][j] = i - j;
    }
  }
  int is_equal = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(status_1, 0);
  ck_assert_int_eq(status_2, 0);
  ck_assert_int_eq(is_equal, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *comparison_suite(void) {
  Suite *s;
  TCase *tc_compare;

  s = suite_create("Matrices compare");

  tc_compare = tcase_create("Compare matrices");

  tcase_add_test(tc_compare, compare_1);
  tcase_add_test(tc_compare, compare_2);
  tcase_add_test(tc_compare, compare_3);
  tcase_add_test(tc_compare, compare_4);

  suite_add_tcase(s, tc_compare);

  return s;
}