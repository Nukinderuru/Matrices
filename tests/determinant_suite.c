#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"
#include "tests.h"

// 1x1 matrix
START_TEST(determinant_1x1_1) {
  matrix_t A;
  int status = s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 9;
  double det = 0.0;
  int res = s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, 9);
  ck_assert_int_eq(equal, OK);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_1x1_2) {
  matrix_t A;
  int status = s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1356;
  double det = 0.0;
  int res = s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, 1356);
  ck_assert_int_eq(equal, OK);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_1x1_3) {
  matrix_t A;
  int status = s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = -16.874356;
  double det = 0.0;
  int res = s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, -16.874356);
  ck_assert_int_eq(equal, OK);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

// 2x2 matrix determinant
START_TEST(determinant_2x2_1) {
  matrix_t A;
  int status = s21_create_matrix(2, 2, &A);
  int n = 1;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      A.matrix[i][j] = n++;
    }
  double det = 0.0;
  int res = s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, -2);
  ck_assert_int_eq(equal, OK);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2x2_2) {
  matrix_t A;
  int status = s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = -3;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 12;
  A.matrix[1][1] = 4;
  double det = 0.0;
  int res = s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, -36);
  ck_assert_int_eq(equal, OK);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2x2_3) {
  matrix_t A;
  int status = s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = -1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = -8;
  double det = 0.0;
  int res = s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, -2);
  ck_assert_int_eq(equal, OK);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

// 3x3 matrix determinant
START_TEST(determinant_3x3_1) {
  matrix_t A;
  int status = s21_create_matrix(3, 3, &A);
  int n = 1;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      A.matrix[i][j] = n++;
    }
  double det = 0.0;
  int res = s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, 0);
  ck_assert_int_eq(equal, OK);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3x3_2) {
  matrix_t A;
  int status = s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = -3;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = -5;
  A.matrix[1][0] = 10;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 7;
  A.matrix[2][0] = 6;
  A.matrix[2][1] = -8;
  A.matrix[2][2] = -9;
  double det = 0.0;
  int res = s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, 724);
  ck_assert_int_eq(equal, OK);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3x3_3) {
  matrix_t A;
  int status = s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = -4;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = -1;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 4;
  double det = 0.0;
  int res = s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, 134);
  ck_assert_int_eq(equal, OK);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

// 4x4 matrix determinant
START_TEST(determinant_4x4_1) {
  matrix_t A;
  int status = s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = -1;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 7;
  A.matrix[1][3] = 0;
  A.matrix[2][0] = -4;
  A.matrix[2][1] = -1;
  A.matrix[2][2] = 2;
  A.matrix[2][3] = 1;
  A.matrix[3][0] = -6;
  A.matrix[3][1] = 7;
  A.matrix[3][2] = 1;
  A.matrix[3][3] = -1;
  double det = 0;
  int res = s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, 497);
  ck_assert_int_eq(equal, OK);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4x4_2) {
  matrix_t A;
  int status = s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1;
  A.matrix[0][1] = 3;
  A.matrix[0][2] = 2;
  A.matrix[0][3] = -3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = -2;
  A.matrix[1][2] = 5;
  A.matrix[1][3] = 1;
  A.matrix[2][0] = -5;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = -4;
  A.matrix[2][3] = 0;
  A.matrix[3][0] = 9;
  A.matrix[3][1] = 7;
  A.matrix[3][2] = 8;
  A.matrix[3][3] = -7;
  double det = 0;
  int res = s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, 86);
  ck_assert_int_eq(equal, OK);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(res, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4x4_3) {
  matrix_t A = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 4;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 6;
  A.matrix[0][3] = 7;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 12;
  A.matrix[1][2] = 11;
  A.matrix[1][3] = 9;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 7;
  A.matrix[2][2] = 4;
  A.matrix[2][3] = 5;
  A.matrix[3][0] = 6;
  A.matrix[3][1] = 9;
  A.matrix[3][2] = 10;
  A.matrix[3][3] = 4;
  double det = 0.0;
  s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, -135);
  ck_assert_int_eq(equal, OK);
  s21_remove_matrix(&A);
}
END_TEST

// 5x5 matrix
START_TEST(determinant_5x5_1) {
  matrix_t A = {0};
  s21_create_matrix(5, 5, &A);
  int n = 1;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) A.matrix[i][j] = n++;
  }
  double det = 0.0;
  s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, 0);
  ck_assert_int_eq(equal, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_5x5_2) {
  matrix_t A = {0};
  s21_create_matrix(5, 5, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[0][3] = 1;
  A.matrix[0][4] = 1;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 1;
  A.matrix[1][3] = 1;
  A.matrix[1][4] = 1;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 1;
  A.matrix[2][4] = 1;
  A.matrix[3][0] = 9;
  A.matrix[3][1] = 10;
  A.matrix[3][2] = 11;
  A.matrix[3][3] = 1;
  A.matrix[3][4] = 1;
  A.matrix[4][0] = 12;
  A.matrix[4][1] = 13;
  A.matrix[4][2] = 14;
  A.matrix[4][3] = 15;
  A.matrix[4][4] = 1;
  double det = 0.0;
  s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, 4900);
  ck_assert_int_eq(equal, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_5x5_3) {
  matrix_t A = {0};
  s21_create_matrix(5, 5, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[0][4] = 5;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 2;
  A.matrix[1][3] = 3;
  A.matrix[1][4] = 4;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 2;
  A.matrix[2][4] = 3;
  A.matrix[3][0] = 0;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 1;
  A.matrix[3][4] = 2;
  A.matrix[4][0] = 0;
  A.matrix[4][1] = 0;
  A.matrix[4][2] = 0;
  A.matrix[4][3] = 0;
  A.matrix[4][4] = 1;
  double det = 0.0;
  s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, 1);
  ck_assert_int_eq(equal, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_5x5_4) {
  matrix_t A = {0};
  s21_create_matrix(5, 5, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[0][4] = 5;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 0;
  A.matrix[1][4] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 2;
  A.matrix[2][4] = 3;
  A.matrix[3][0] = 0;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 1;
  A.matrix[3][4] = 2;
  A.matrix[4][0] = 0;
  A.matrix[4][1] = 0;
  A.matrix[4][2] = 0;
  A.matrix[4][3] = 0;
  A.matrix[4][4] = 1;
  double det = 0.0;
  s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, 0);
  ck_assert_int_eq(equal, OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_5x5_5) {
  matrix_t A = {0};
  s21_create_matrix(5, 5, &A);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) A.matrix[i][j] = 1;
  }
  double det = 0.0;
  s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, 0);
  ck_assert_int_eq(equal, OK);
  s21_remove_matrix(&A);
}
END_TEST

// Incorrect matrix
START_TEST(incorect_determinant_1) {
  matrix_t A;
  int status = s21_create_matrix(1, 2, &A);
  A.matrix[0][0] = 9;
  A.matrix[0][1] = 9;
  double det = 0.0;
  int res = s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, 0);
  ck_assert_int_eq(equal, OK);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(incorect_determinant_2) {
  matrix_t A;
  int status = s21_create_matrix(4, 2, &A);
  int n = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) A.matrix[i][j] = n++;
  }
  double det = 0.0;
  int res = s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, 0);
  ck_assert_int_eq(equal, OK);
  ck_assert_int_eq(status, OK);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(incorect_determinant_3) {
  matrix_t A = {NULL, 0, 0};
  int status = s21_create_matrix(0, 0, &A);
  double det = 0.0;
  int res = s21_determinant(&A, &det);
  int equal = s21_compare_doubles(det, 0);
  ck_assert_int_eq(equal, OK);
  ck_assert_int_eq(status, INCORRECT_MATRIX);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

Suite *determinant_suite(void) {
  Suite *s;
  TCase *tc_determinant;

  s = suite_create("Determinant");
  tc_determinant = tcase_create("Determinant matrix tests");

  tcase_add_test(tc_determinant, incorect_determinant_1);
  tcase_add_test(tc_determinant, incorect_determinant_2);
  tcase_add_test(tc_determinant, incorect_determinant_3);
  tcase_add_test(tc_determinant, determinant_1x1_1);
  tcase_add_test(tc_determinant, determinant_1x1_2);
  tcase_add_test(tc_determinant, determinant_1x1_3);
  tcase_add_test(tc_determinant, determinant_2x2_1);
  tcase_add_test(tc_determinant, determinant_2x2_2);
  tcase_add_test(tc_determinant, determinant_2x2_3);
  tcase_add_test(tc_determinant, determinant_3x3_1);
  tcase_add_test(tc_determinant, determinant_3x3_2);
  tcase_add_test(tc_determinant, determinant_3x3_3);
  tcase_add_test(tc_determinant, determinant_4x4_1);
  tcase_add_test(tc_determinant, determinant_4x4_2);
  tcase_add_test(tc_determinant, determinant_4x4_3);
  tcase_add_test(tc_determinant, determinant_5x5_1);
  tcase_add_test(tc_determinant, determinant_5x5_2);
  tcase_add_test(tc_determinant, determinant_5x5_3);
  tcase_add_test(tc_determinant, determinant_5x5_4);
  tcase_add_test(tc_determinant, determinant_5x5_5);

  suite_add_tcase(s, tc_determinant);

  return s;
}