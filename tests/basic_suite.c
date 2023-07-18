#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"
#include "tests.h"

// Create correct matrix
START_TEST(create_matrix_1) {
  matrix_t result;
  int status = s21_create_matrix(1, 1, &result);
  int equal = s21_compare_doubles(result.matrix[0][0], 0);
  ck_assert_int_eq(equal, OK);
  ck_assert_int_eq(status, OK);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(create_matrix_2) {
  matrix_t result;
  int status = s21_create_matrix(2, 2, &result);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      int equal = s21_compare_doubles(result.matrix[i][j], 0);
      ck_assert_int_eq(equal, OK);
    }
  }
  ck_assert_int_eq(status, 0);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(create_matrix_3) {
  matrix_t result;
  int status = s21_create_matrix(5, 5, &result);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      int equal = s21_compare_doubles(result.matrix[i][j], 0);
      ck_assert_int_eq(equal, OK);
    }
  }
  ck_assert_int_eq(status, 0);
  s21_remove_matrix(&result);
}
END_TEST

// Create incorrect matrix
START_TEST(create_incorrect_matrix_1) {
  matrix_t result = {0};
  int status = s21_create_matrix(0, 0, &result);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(create_incorrect_matrix_2) {
  matrix_t result;
  int status = s21_create_matrix(-2, 2, &result);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(create_incorrect_matrix_3) {
  matrix_t result;
  int status = s21_create_matrix(6, -1, &result);
  ck_assert_int_eq(status, 1);
}
END_TEST

// Remove matrix
START_TEST(remove_matrix_1) {
  matrix_t result;
  int status = s21_create_matrix(3, 3, &result);
  ck_assert_int_eq(status, 0);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(remove_matrix_2) {
  matrix_t result = {NULL};
  s21_remove_matrix(&result);
}
END_TEST

Suite *basic_suite(void) {
  Suite *s;
  TCase *tc_create, *tc_remove;

  s = suite_create("Matrix create and remove");

  tc_create = tcase_create("Create matrix");
  tc_remove = tcase_create("Remove matrix");

  // ---------- Matrix create ----------
  tcase_add_test(tc_create, create_matrix_1);
  tcase_add_test(tc_create, create_matrix_2);
  tcase_add_test(tc_create, create_matrix_3);
  tcase_add_test(tc_create, create_incorrect_matrix_1);
  tcase_add_test(tc_create, create_incorrect_matrix_2);
  tcase_add_test(tc_create, create_incorrect_matrix_3);
  // ---------- Matrix remove ----------
  tcase_add_test(tc_remove, remove_matrix_1);
  tcase_add_test(tc_remove, remove_matrix_2);

  suite_add_tcase(s, tc_create);
  suite_add_tcase(s, tc_remove);

  return s;
}
