/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"

/**
 * @brief Функция вычисляет обратную матрицу для матрицы А.
 * Результат вычисления записывается в матрицу result.
 * @param A - указатель на матрицу,
 * @param result - указатель на результат вычисления.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 *          2 - Ошибка вычисления.
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    double det = 0.0;
    int errcode = s21_determinant(A, &det);

    if (errcode == OK && det != 0.0) {
        matrix_t tmp1 = {NULL, 0, 0};
        matrix_t tmp2 = {NULL, 0, 0};

        s21_calc_complements(A, &tmp1);
        s21_transpose(&tmp1, &tmp2);
        s21_mult_number(&tmp2, 1.0 / det, result);

        s21_remove_matrix(&tmp1);
        s21_remove_matrix(&tmp2);
    }
    return (errcode);
}
