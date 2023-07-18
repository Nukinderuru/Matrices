#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"
#include "tests.h"

// Sum two matrix
START_TEST(sum_1) {
  int rows = 2;
  int columns = 2;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int status_1 = s21_create_matrix(rows, columns, &A);
  int status_2 = s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i + j;
    }
  int status_sum = s21_sum_matrix(&A, &B, &result);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], A.matrix[i][j] + B.matrix[i][j]);
    }
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(status_sum, OK);
  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_2) {
  int rows = 5;
  int columns = 3;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int status_1 = s21_create_matrix(rows, columns, &A);
  int status_2 = s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i + j;
    }
  int status_sum = s21_sum_matrix(&A, &B, &result);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], A.matrix[i][j] + B.matrix[i][j]);
    }
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(status_sum, OK);
  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_3) {
  int rows = 5;
  int columns = 3;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int status_1 = s21_create_matrix(rows, columns, &A);
  int status_2 = s21_create_matrix(columns, rows, &B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
    }
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++) {
      B.matrix[i][j] = i + j;
    }
  int status_sum = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(status_sum, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// Sub two equal matrix
START_TEST(sub_1) {
  int rows = 2;
  int columns = 2;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int status_1 = s21_create_matrix(rows, columns, &A);
  int status_2 = s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i + j;
    }
  int status_sub = s21_sub_matrix(&A, &B, &result);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], 0);
    }
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(status_sub, OK);
  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_2) {
  int rows = 3;
  int columns = 5;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int status_1 = s21_create_matrix(rows, columns, &A);
  int status_2 = s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i + j;
    }
  int status_sub = s21_sub_matrix(&A, &B, &result);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      ck_assert_int_eq(result.matrix[i][j], 0);
    }
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(status_sub, OK);
  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sub_3) {
  int rows = 5;
  int columns = 3;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int status_1 = s21_create_matrix(rows, columns, &A);
  int status_2 = s21_create_matrix(columns, rows, &B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
    }
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++) {
      B.matrix[i][j] = i + j;
    }
  int status_sum = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(status_sum, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// Mul matrix number matrix
START_TEST(mult_number_1) {
  int rows = 4;
  int columns = 4;
  double number = 3.78;
  matrix_t A;
  matrix_t result;
  int status = s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
    }
  int status_mult = s21_mult_number(&A, number, &result);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      int equal =
          s21_compare_doubles(result.matrix[i][j], A.matrix[i][j] * number);
      ck_assert_int_eq(equal, OK);
    }
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(status_mult, OK);
  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
}
END_TEST

// Square matrices
START_TEST(mult_matrix_1) {
  int rows = 2;
  int columns = 2;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int status_1 = s21_create_matrix(rows, columns, &A);
  int status_2 = s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i + j;
    }
  int status_mult = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(result.matrix[0][0], 1);
  ck_assert_int_eq(result.matrix[0][1], 2);
  ck_assert_int_eq(result.matrix[1][0], 2);
  ck_assert_int_eq(result.matrix[1][1], 5);
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(status_mult, OK);
  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// 2x3 and 3x2 matrices
START_TEST(mult_matrix_2) {
  int rows = 2;
  int columns = 3;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int status_1 = s21_create_matrix(rows, columns, &A);
  int status_2 = s21_create_matrix(columns, rows, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 7;
  B.matrix[0][0] = 8;
  B.matrix[0][1] = 7;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = 5;
  B.matrix[2][0] = 4;
  B.matrix[2][1] = 3;
  int status_mult = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(status_mult, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

// Mismatched matrices
START_TEST(mult_matrix_3) {
  int rows = 2;
  int columns = 3;
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int status_1 = s21_create_matrix(rows, columns, &A);
  int status_2 = s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
      B.matrix[i][j] = i + j;
    }
  int status_mult = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(status_mult, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *arithmetic_suite(void) {
  Suite *s;
  TCase *tc_sum, *tc_sub, *tc_mult_num, *tc_mult;

  s = suite_create("Matrix arithmetic");

  tc_sum = tcase_create("Sum matrix tests");
  tc_sub = tcase_create("Sub matrix tests");
  tc_mult_num = tcase_create("Sub matrix tests");
  tc_mult = tcase_create("Sub matrix tests");

  // ---------- Matrix sum tests ----------
  tcase_add_test(tc_sum, sum_1);
  tcase_add_test(tc_sum, sum_2);
  tcase_add_test(tc_sum, sum_3);
  // ---------- Matrix sub tests ----------
  tcase_add_test(tc_sub, sub_1);
  tcase_add_test(tc_sub, sub_2);
  tcase_add_test(tc_sub, sub_3);
  // ---------- Matrix mult tests ----------
  tcase_add_test(tc_mult_num, mult_number_1);
  // ---------- Matrix mult tests ----------
  tcase_add_test(tc_mult, mult_matrix_1);
  tcase_add_test(tc_mult, mult_matrix_2);
  tcase_add_test(tc_mult, mult_matrix_3);

  suite_add_tcase(s, tc_sum);
  suite_add_tcase(s, tc_sub);
  suite_add_tcase(s, tc_mult_num);
  suite_add_tcase(s, tc_mult);

  return s;
}
