/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"

/**
 * @brief Функция вычисляет определитель матрицы.
 * Результат вычисления записывается в result.
 * @param A - указатель на матрицу,
 * @param result - указатель на результат вычисления.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 *          2 - Ошибка вычисления.
 */
// TODO: написать везде комментарии
int s21_determinant(matrix_t *A, double *result) {
    int errcode = OK;

    if (s21_check_matrix(A) == INCORRECT_MATRIX) {
        errcode = INCORRECT_MATRIX;
    } else if (!s21_is_square_matrix(A)) {
        errcode = CALC_ERROR;
    } else {
        *result = s21_calc_determinant(A);
    }
    return (errcode);
}

double s21_calc_determinant(matrix_t *A) {
    double result = 0.0;

    if (A->rows == 1) {
        result = A->matrix[0][0];
    } else if (A->rows == 2) {
        result = A->matrix[0][0] * A->matrix[1][1] -
            A->matrix[0][1] * A->matrix[1][0];
    } else {
        for (int j = 0; j < A->rows; ++j) {
            int errcode = OK;
            int sign = ((0 + j) % 2) ? -1 : 1;
            matrix_t minor = {NULL, 0, 0};

            errcode = s21_minor_matrix(A, 0, j, &minor);
            if (errcode == OK) {
                result += sign * s21_calc_determinant(&minor) * A->matrix[0][j];
                s21_remove_matrix(&minor);
            }
        }
    }
    return (result);
}
