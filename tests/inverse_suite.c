#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"
#include "tests.h"

START_TEST(inverse_1) {
  matrix_t A;
  matrix_t B;
  matrix_t result;
  int status_1 = s21_create_matrix(3, 3, &A);
  int status_2 = s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = -1;
  B.matrix[0][2] = 1;
  B.matrix[1][0] = -38;
  B.matrix[1][1] = 41;
  B.matrix[1][2] = -34;
  B.matrix[2][0] = 27;
  B.matrix[2][1] = -29;
  B.matrix[2][2] = 24;
  int res = s21_inverse_matrix(&A, &result);
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

// Determinant = 0
START_TEST(inverse_2) {
  matrix_t A, result;
  int status = s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_3) {
  matrix_t A, B, result;
  int status_1 = s21_create_matrix(3, 3, &A);
  int status_2 = s21_create_matrix(3, 3, &B);
  A.matrix[0][0] = 8;
  A.matrix[0][1] = -7;
  A.matrix[0][2] = 5;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = -4;
  A.matrix[2][0] = 11.5;
  A.matrix[2][1] = 18;
  A.matrix[2][2] = -0.6;
  B.matrix[0][0] = 0.0987202;
  B.matrix[0][1] = 0.1206581;
  B.matrix[0][2] = 0.0182815;
  B.matrix[1][0] = -0.0646885;
  B.matrix[1][1] = -0.0876107;
  B.matrix[1][2] = 0.0450007;
  B.matrix[2][0] = -0.0485163;
  B.matrix[2][1] = -0.3157080;
  B.matrix[2][2] = 0.0337505;
  int res = s21_inverse_matrix(&A, &result);
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

START_TEST(inverse_4) {
  matrix_t A, B, result;
  int status_1 = s21_create_matrix(3, 3, &A);
  int status_2 = s21_create_matrix(3, 3, &B);
  int res = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status_1, OK);
  ck_assert_int_eq(status_2, OK);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *inverse_suite(void) {
  Suite *s;
  TCase *tc_inverse_matrix;

  s = suite_create("Inverse");
  tc_inverse_matrix = tcase_create("Inverse matrix tests");
  tcase_add_test(tc_inverse_matrix, inverse_1);
  tcase_add_test(tc_inverse_matrix, inverse_2);
  tcase_add_test(tc_inverse_matrix, inverse_3);
  tcase_add_test(tc_inverse_matrix, inverse_4);

  suite_add_tcase(s, tc_inverse_matrix);

  return s;
}
