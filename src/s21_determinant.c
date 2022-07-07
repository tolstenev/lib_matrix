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
int s21_determinant(matrix_t *A, double *result) {
    // Объявление переменной для возвращаемого кода ошибки
    static int errcode = OK;

    if (errcode == OK) {
        if (s21_check_matrix(A) == INCORRECT_MATRIX) {
            // Код ошибки 1, если матрица А, матрица некорректная.
            errcode = INCORRECT_MATRIX;
        } else if (!s21_is_square_matrix(A)) {
            errcode = CALC_ERROR;
        } else {
            if (A->rows == 1) {
                *result = A->matrix[0][0];
            } else if (A->rows == 2) {
                *result = A->matrix[0][0] * A->matrix[1][1] -
                         A->matrix[0][1] * A->matrix[1][0];
            } else {
                for (int j = 0; j < A->rows; ++j) {
                    matrix_t minor = {NULL, 0, 0};
                    int sign = (((A->rows + A->columns) % 2) ?  1
                                                             : -1);
                    errcode = s21_minor_matrix(A, 0, j, &minor);

                    *result += sign * s21_determinant(&minor, result) * (*result);
                    s21_remove_matrix(&minor);
                }
            }
        }
    }
    return (errcode);
}
