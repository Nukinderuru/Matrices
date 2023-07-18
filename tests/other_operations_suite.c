#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"
#include "tests.h"

// ----------------- Transpose --------------------
START_TEST(transpose_1) {
  int rows = 2;
  int columns = 4;
  matrix_t A;
  matrix_t result;
  int status = s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
    }
  int status_transpose = s21_transpose(&A, &result);
  ck_assert_int_eq(result.columns, rows);
  ck_assert_int_eq(result.rows, columns);
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++) {
      ck_assert_int_eq(result.matrix[i][j], i + j);
    }
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(status_transpose, OK);
  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_2) {
  int rows = 2;
  int columns = 4;
  matrix_t A;
  matrix_t result;
  int status = s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j;
    }
  int status_transpose = s21_transpose(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(status_transpose, OK);
  s21_remove_matrix(&result);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(transpose_3) {
  int rows = 0;
  int columns = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t result;
  int status = s21_create_matrix(rows, columns, &A);
  int status_transpose = s21_transpose(&A, &result);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
  ck_assert_int_eq(status_transpose, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

// ----------------- Complements --------------------

// 1x1 matrix
START_TEST(complements_1x1) {
  matrix_t A, result;
  int status = s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = -16.874356;
  int res = s21_calc_complements(&A, &result);
  s21_compare_doubles(1.0, result.matrix[0][0]);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

// 2x2 matrix
START_TEST(complements_2x2_1) {
  matrix_t A, B, result;
  int status_1 = s21_create_matrix(2, 2, &A);
  int status_2 = s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 4;
  B.matrix[0][1] = -3;
  B.matrix[1][0] = -2;
  B.matrix[1][1] = 1;
  int res = s21_calc_complements(&A, &result);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      int equal = s21_compare_doubles(B.matrix[i][j], result.matrix[i][j]);
      ck_assert_int_eq(equal, OK);
    }
  }
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(complements_2x2_2) {
  matrix_t A, B, result;
  int status_1 = s21_create_matrix(2, 2, &A);
  int status_2 = s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 3;
  A.matrix[1][0] = 9;
  A.matrix[1][1] = -6;
  B.matrix[0][0] = -6;
  B.matrix[0][1] = -9;
  B.matrix[1][0] = -3;
  B.matrix[1][1] = 0;
  int res = s21_calc_complements(&A, &result);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      int equal = s21_compare_doubles(B.matrix[i][j], result.matrix[i][j]);
      ck_assert_int_eq(equal, OK);
    }
  }
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(complements_2x2_3) {
  matrix_t A, B, result;
  int status_1 = s21_create_matrix(2, 2, &A);
  int status_2 = s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 0.3456;
  A.matrix[0][1] = -11.3;
  A.matrix[1][0] = 0.98765;
  A.matrix[1][1] = 6.7382;
  B.matrix[0][0] = 6.7382;
  B.matrix[0][1] = -0.98765;
  B.matrix[1][0] = 11.3;
  B.matrix[1][1] = 0.3456;
  int res = s21_calc_complements(&A, &result);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      int equal = s21_compare_doubles(B.matrix[i][j], result.matrix[i][j]);
      ck_assert_int_eq(equal, OK);
    }
  }
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

// 3x3 matrix
START_TEST(complements_3x3_1) {
  matrix_t A, B, result;
  int status_1 = s21_create_matrix(3, 3, &A);
  int status_2 = s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  B.matrix[0][0] = 0;
  B.matrix[0][1] = 10;
  B.matrix[0][2] = -20;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = -14;
  B.matrix[1][2] = 8;
  B.matrix[2][0] = -8;
  B.matrix[2][1] = -2;
  B.matrix[2][2] = 4;
  int res = s21_calc_complements(&A, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int equal = s21_compare_doubles(B.matrix[i][j], result.matrix[i][j]);
      ck_assert_int_eq(equal, OK);
    }
  }
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(complements_3x3_2) {
  matrix_t A, B, result;
  int status_1 = s21_create_matrix(3, 3, &A);
  int status_2 = s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 1;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = -3;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 1;
  B.matrix[1][1] = 1;
  B.matrix[1][2] = -1;
  B.matrix[2][0] = -4;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = -4;
  int res = s21_calc_complements(&A, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int equal = s21_compare_doubles(B.matrix[i][j], result.matrix[i][j]);
      ck_assert_int_eq(equal, OK);
    }
  }
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(complements_3x3_3) {
  matrix_t A, B, result;
  int status_1 = s21_create_matrix(3, 3, &A);
  int status_2 = s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 1;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 0;
  B.matrix[0][2] = 0;
  B.matrix[1][0] = 0;
  B.matrix[1][1] = 1;
  B.matrix[1][2] = 0;
  B.matrix[2][0] = 0;
  B.matrix[2][1] = 0;
  B.matrix[2][2] = 1;
  int res = s21_calc_complements(&A, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int equal = s21_compare_doubles(B.matrix[i][j], result.matrix[i][j]);
      ck_assert_int_eq(equal, OK);
    }
  }
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(complements_2x3_1) {
  matrix_t A, result;
  int status_1 = s21_create_matrix(2, 3, &A);
  int status_2 = s21_create_matrix(2, 3, &result);
  int res = s21_calc_complements(&A, &result);
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *other_operations_suite(void) {
  Suite *s;
  TCase *tc_transpose, *tc_calc_complements;

  s = suite_create("Other operations");

  tc_transpose = tcase_create("Transpose matrix tests");
  tc_calc_complements = tcase_create("Complements matrix tests");

  // ------------- Transpose tests -----------------
  tcase_add_test(tc_transpose, transpose_1);
  tcase_add_test(tc_transpose, transpose_2);
  tcase_add_test(tc_transpose, transpose_3);
  // ------------- Complements ---------------------
  tcase_add_test(tc_calc_complements, complements_1x1);
  tcase_add_test(tc_calc_complements, complements_2x2_1);
  tcase_add_test(tc_calc_complements, complements_2x2_2);
  tcase_add_test(tc_calc_complements, complements_2x2_3);
  tcase_add_test(tc_calc_complements, complements_3x3_1);
  tcase_add_test(tc_calc_complements, complements_3x3_2);
  tcase_add_test(tc_calc_complements, complements_3x3_3);
  tcase_add_test(tc_calc_complements, complements_2x3_1);

  suite_add_tcase(s, tc_transpose);
  suite_add_tcase(s, tc_calc_complements);

  return s;
}
