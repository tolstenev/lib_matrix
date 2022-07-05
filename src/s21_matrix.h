/**
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 * yonnarge@student.21-school.ru
 *
 * The s21_matrix.h library is intended for processing numerical matrices
 * in the C programming language.
 *
 * Библиотека s21_matrix.h предназначена для обработки числовых матриц
 * на языке программирования C.
 */

#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>

// Возвращаемые значения функции s21_eq_matrix
#define SUCCESS 1
#define FAILURE 0

// Проверяемая точность вычислений
#define EPS 1e-07

// Числовые коды ошибок работы функций
enum {
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
// int s21_transpose(matrix_t *A, matrix_t *result);
// int s21_calc_complements(matrix_t *A, matrix_t *result);
// int s21_determinant(matrix_t *A, double *result);
// int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Вспомогательные функции бибилиотеки
void s21_print_matrix(matrix_t *A);
void s21_halt_programm_memory_error(void);
void s21_fill_matrix(matrix_t *A, double value);
void s21_fill_matrix_rand(matrix_t *A);
int s21_get_number(void);
int s21_check_matrix(matrix_t *m);

#endif  // SRC_S21_MATRIX_H_
