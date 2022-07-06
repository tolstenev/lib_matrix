/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"

/**
 * @brief Функция выполняет сложение матриц А и В.
 * Результат сложения записывается в матрицу result.
 * @param A - указатель на матрицу (первое слагаемое),
 * @param B - указатель на матрицу (второе слагаемое),
 * @param result - указатель на результат сложения.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 *          2 - Ошибка вычисления.
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    // Объявление переменной для возвращаемого кода ошибки
    int errcode = OK;

    if (s21_check_matrix(A) == INCORRECT_MATRIX ||
        s21_check_matrix(B) == INCORRECT_MATRIX) {
        // Код ошибки 1, если матрица А, матрица В - некорректные.
        errcode = INCORRECT_MATRIX;
    } else if (A->rows != B->rows || A->columns != B->columns) {
        // Код ошибки 2, если размеры матриц не совпадают
        errcode = CALC_ERROR;
    } else {
        // Создание матрицы под результат сложения
        s21_create_matrix(A->rows, A->columns, result);
        // Поэлементное сложение матриц А и В
        for (int i = 0; i < result->rows; ++i)
            for (int j = 0; j < result->columns; ++j)
                result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
    return (errcode);
}
