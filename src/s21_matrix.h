/*
 * Copyright 2023 Gleb Tolstenev
 * tolstenev.gleb@mail.ru
 *
 * The s21_matrix.h library is intended for processing numerical matrices
 * in the C programming language.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Возвращаемые значения функций, проверяющих свойства матриц
#define SUCCESS 1
#define FAILURE 0

// Проверяемая точность вычислений
#define EPS 1e-07

// Числовые коды ошибок работы функций
enum errcodes {
  OK = 0,
  INCORRECT_MATRIX = 1,
  CALC_ERROR = 2,
};

// Структура матрицы
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// Основные функции библиотеки
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

// Вспомогательные функции бибилиотеки
int s21_check_matrix(matrix_t *A);
int s21_is_square_matrix(matrix_t *A);
int s21_create_matrix_for_minor(matrix_t *A, int row_skip, int col_skip, matrix_t *result);
double s21_calc_minor(matrix_t *A, int row_skip, int col_skip);
double s21_calc_determinant(matrix_t *A);
double s21_calc_one_complement(matrix_t *A, int row_skip, int col_skip);

#endif  // SRC_S21_MATRIX_H_
