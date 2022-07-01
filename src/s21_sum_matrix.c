/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"

/**
 * @brief Функция выполняет сложение матриц А и В. Сумма
 * записывается в матрицу result.
 * @param A
 * @param B
 * @param result
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 *          2 - Ошибка вычисления.
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int errcode = 0;

    // Добавить проверку адекватности матриц через отдельную чек-функцию

    /*if (NULL == A || NULL == B || NULL == result) {
        errcode = 1;
    } else */if (A->rows != B->rows || A->columns != B->columns) {
        errcode = 2;
    } else {
        for (int i = 0; i < result->columns; ++i) {
            for (int j = 0; j < result->rows; ++j) {
                result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            }
        }
    }
    return (errcode);
}
