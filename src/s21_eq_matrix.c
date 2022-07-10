/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"

/**
 * @brief Проверяет равенство матриц А и В.
 * @param A - указатель на матрицу,
 * @param B - указатель на матрицу.
 * @return  1 - ОК, матрицы равны;
 *          2 - Матрицы не равны.
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int rescode = SUCCESS;

    if (s21_check_matrix(A) == INCORRECT_MATRIX ||
        s21_check_matrix(B) == INCORRECT_MATRIX) {
        // Сравнение невозможно, если матрица А, матрица В - некорректные
        rescode = FAILURE;
    } else if (A->rows != B->rows || A->columns != B->columns) {
        // Сравнение невозможно, если размеры матриц не совпадают
        rescode = FAILURE;
    } else {
        // Поэлементное сравнение матриц А и В
        for (int i = 0; i < A->rows; ++i)
            for (int j = 0; j < A->columns; ++j)
                if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS)
                    // Матрицы не равны, если разница элементов превышает
                    // проверяемую точность вычислений
                    rescode = FAILURE;
    }
    return (rescode);
}
