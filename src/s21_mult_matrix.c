/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"

/**
 * @brief Функция выполняет умножение матрицы А на матрицу В.
 * Результат умножения записывается в матрицу result.
 * @param A - указатель на матрицу (первый множитель),
 * @param B - указатель на матрицу (второй множитель),
 * @param result - указатель на результат умножения.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 *          2 - Ошибка вычисления.
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    // Объявление переменной для возвращаемого кода ошибки
    int errcode = OK;

    if (s21_check_matrix(A) == INCORRECT_MATRIX ||
        s21_check_matrix(B) == INCORRECT_MATRIX) {
        // Код ошибки 1, если матрица А, матрица В - некорректные
        errcode = INCORRECT_MATRIX;
    } else if (A->rows != B->columns || A->columns != B->rows) {
        // Код ошибки 2, если не выполняются условия умножения матриц
        errcode = CALC_ERROR;
    } else {
        // Создание матрицы под результат сложения
        errcode = s21_create_matrix(A->rows, B->columns, result);

        if (errcode == OK) {
            // Суммирование результатов поэлементного умножения строк матрицы А
            // на соответствующие столбцы матрицы В
            for (int i = 0; i < result->rows; ++i)
                for (int j = 0; j < result->columns; ++j)
                    for (int k = 0; k < A->columns; ++k)
                        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
    }
    return (errcode);
}
