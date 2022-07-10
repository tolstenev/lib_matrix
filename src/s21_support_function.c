/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"

/**
 * @brief Проверяет корректность матрицы А (указатель на неё и размеры матрицы)
 * @param A - указатель проверяемую на матрицу.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 */
int s21_check_matrix(matrix_t *A) {
    return (NULL == A || A->rows < 1 || A->columns < 1) ? INCORRECT_MATRIX
                                                        : OK;
}

/**
 * @brief Проверяет является ли матрица A квадратной
 * @param A - указатель проверяемую на матрицу.
 * @return  0 - Матрица не квадратная;
 *          1 - Матрица квадратная;
 */
int s21_is_square_matrix(matrix_t *A) {
    return (A->rows == A->columns) ? SUCCESS
                                   : FAILURE;
}
