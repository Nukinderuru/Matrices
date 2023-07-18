#include <math.h>

#include "s21_matrix.h"

int s21_compare_doubles(double a, double b) {
  double eps = 0.0000001;
  operation_result status = (fabs(a - b) < eps) ? 0 : 1;
  return status;
}

int s21_wrong_matrix(matrix_t *A) {
  operation_result status =
      (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1)
          ? INCORRECT_MATRIX
          : OK;
  return status;
}

int s21_matrices_mismatch(matrix_t *A, matrix_t *B) {
  operation_result status =
      (A->columns != B->columns || A->rows != B->rows) ? CALCULATION_ERROR : OK;
  return status;
}

int s21_matrix_not_square(matrix_t *A) {
  operation_result status = (A->rows != A->columns) ? CALCULATION_ERROR : OK;
  return status;
}

int s21_matrices_mismatch_for_transpose(matrix_t *A, matrix_t *B) {
  operation_result status =
      (A->columns != B->rows || A->rows != B->columns) ? CALCULATION_ERROR : OK;
  return status;
}

void s21_multiply_elements(matrix_t A, matrix_t B, matrix_t *result) {
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < B.columns; j++) {
      for (int k = 0; k < A.columns; k++) {
        result->matrix[i][j] += (A.matrix[i][k] * B.matrix[k][j]);
      }
    }
  }
}

int s21_create_complements_matrix(matrix_t *A, matrix_t *minor_matrix,
                                  matrix_t *result) {
  operation_result status = OK;
  int k = -1;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      double det = 0.0;
      s21_find_minor_matrix_for_element(A, i, j, minor_matrix);
      if (!(status = s21_determinant(minor_matrix, &det))) {
        result->matrix[i][j] = pow(k, (i + j)) * det;
      }
    }
  }
  return status;
}

void s21_find_minor_matrix_for_element(matrix_t *A, int row, int column,
                                       matrix_t *minor_matrix) {
  int offset_row = 0, offset_column = 0;
  for (int i = 0; i < minor_matrix->rows; i++) {
    if (i == row) offset_row = 1;
    offset_column = 0;
    for (int j = 0; j < minor_matrix->columns; j++) {
      if (j == column) offset_column = 1;
      minor_matrix->matrix[i][j] = A->matrix[i + offset_row][j + offset_column];
    }
  }
}

void s21_calc_inverse(matrix_t A, matrix_t transposed, double det,
                      matrix_t *result) {
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      result->matrix[i][j] = transposed.matrix[i][j] / det;
    }
  }
}
