#include "s21_matrix.h"

#include <math.h>

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  operation_result status = OK;
  if (rows < 1 || columns < 1)
    status = INCORRECT_MATRIX;
  else {
    *result = (matrix_t){NULL, 0, 0};
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
    if (result->matrix == NULL) status = INCORRECT_MATRIX;
  }
  return status;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
    free(A->matrix);
    A->rows = 0;
    A->columns = 0;
    A->matrix = NULL;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  operation_result status = SUCCESS;
  int error = s21_matrices_mismatch(A, B);
  if (error)
    status = FAILURE;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (s21_compare_doubles(A->matrix[i][j], B->matrix[i][j])) {
          status = FAILURE;
        }
      }
    }
  }
  return status;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  operation_result status = OK;
  int error = s21_matrices_mismatch(A, B);
  if (error)
    status = error;
  else if (s21_create_matrix(A->rows, A->columns, result))
    status = INCORRECT_MATRIX;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return status;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  operation_result status = OK;
  int error = s21_matrices_mismatch(A, B);
  if (error)
    status = error;
  else if (s21_create_matrix(A->rows, A->columns, result))
    status = INCORRECT_MATRIX;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return status;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  operation_result status = OK;
  if (s21_wrong_matrix(A))
    status = INCORRECT_MATRIX;
  else if (s21_create_matrix(A->rows, A->columns, result))
    status = INCORRECT_MATRIX;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return status;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  operation_result status = OK;
  if (s21_wrong_matrix(A) || s21_wrong_matrix(B))
    status = INCORRECT_MATRIX;
  else if (A->columns != B->rows)
    status = CALCULATION_ERROR;
  else if (!(status = s21_create_matrix(A->rows, B->columns, result)))
    s21_multiply_elements(*A, *B, result);
  return status;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  operation_result status = OK;
  if (s21_wrong_matrix(A))
    status = INCORRECT_MATRIX;
  else if (s21_create_matrix(A->columns, A->rows, result))
    status = INCORRECT_MATRIX;
  else {
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) result->matrix[i][j] = A->matrix[j][i];
    }
  }
  return status;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  operation_result status = OK;
  if (s21_wrong_matrix(A))
    status = INCORRECT_MATRIX;
  else if (s21_matrix_not_square(A))
    status = CALCULATION_ERROR;
  else if (!(status = s21_create_matrix(A->rows, A->columns, result))) {
    matrix_t minor_matrix = {0};
    if (A->rows == 1)
      result->matrix[0][0] = 1.0;
    else if (!(status = s21_create_matrix(A->rows - 1, A->columns - 1,
                                          &minor_matrix))) {
      status = s21_create_complements_matrix(A, &minor_matrix, result);
    }
    s21_remove_matrix(&minor_matrix);
  }
  return status;
}

int s21_determinant(matrix_t *A, double *result) {
  operation_result status = OK;
  if (A == NULL || A->columns < 1 || A->rows < 1)
    status = INCORRECT_MATRIX;
  else if (A->columns != A->rows)
    status = CALCULATION_ERROR;
  else {
    double det = 0.0;
    if (A->rows == 1)
      det = A->matrix[0][0];
    else if (A->rows == 2) {
      det =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
    } else {
      int k = 1;
      matrix_t minor_matrix = {NULL, 0, 0};
      if (s21_create_matrix(A->rows - 1, A->columns - 1, &minor_matrix))
        status = INCORRECT_MATRIX;
      else {
        for (int i = 0; i < A->rows; i++) {
          double minor_det = 0.0;
          s21_find_minor_matrix_for_element(A, 0, i, &minor_matrix);
          if (s21_determinant(&minor_matrix, &minor_det))
            status = CALCULATION_ERROR;
          else {
            det += A->matrix[0][i] * k * minor_det;
            k = -k;
          }
        }
      }
      s21_remove_matrix(&minor_matrix);
    }
    *result = det;
  }
  return status;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  operation_result status = OK;
  double det = 0.0;
  if (s21_wrong_matrix(A))
    status = INCORRECT_MATRIX;
  else if (s21_matrix_not_square(A) || s21_determinant(A, &det) || !det)
    status = CALCULATION_ERROR;
  else if (!(status = s21_create_matrix(A->rows, A->columns, result))) {
    if (A->rows == 1)
      result->matrix[0][0] = 1 / A->matrix[0][0];
    else {
      matrix_t complements;
      if (!(status = s21_calc_complements(A, &complements))) {
        matrix_t transposed;
        if (!(status = s21_transpose(&complements, &transposed))) {
          s21_calc_inverse(*A, transposed, det, result);
          s21_remove_matrix(&transposed);
        }
        s21_remove_matrix(&complements);
      }
    }
  }
  return status;
}
