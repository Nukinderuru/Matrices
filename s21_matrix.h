#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum { OK, INCORRECT_MATRIX, CALCULATION_ERROR } operation_result;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Helpers
int s21_compare_doubles(double a, double b);
int s21_wrong_matrix(matrix_t *A);
int s21_matrices_mismatch(matrix_t *A, matrix_t *B);
int s21_matrix_not_square(matrix_t *A);
int s21_matrices_mismatch_for_transpose(matrix_t *A, matrix_t *B);
void s21_multiply_elements(matrix_t A, matrix_t B, matrix_t *result);
int s21_create_complements_matrix(matrix_t *A, matrix_t *minor_matrix,
                                  matrix_t *result);
void s21_find_minor_matrix_for_element(matrix_t *A, int row, int column,
                                       matrix_t *minor_matrix);
void s21_calc_inverse(matrix_t A, matrix_t transposed, double det,
                      matrix_t *result);

#endif  // S21_MATRIX_H