/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"

/**
 * @brief Функция выполняет транспонирование матрицы А.
 * Транспонированная матрица записывается в матрицу result.
 * @param A - указатель на матрицу,
 * @param result - указатель на транспонированную матрицу.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 *          2 - Ошибка вычисления.
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
    // Объявление переменной для возвращаемого кода ошибки
    int errcode = OK;

    if (s21_check_matrix(A) == INCORRECT_MATRIX) {
        // Код ошибки 1, если матрица А, матрица некорректная.
        errcode = INCORRECT_MATRIX;
    } else {
        // Создание матрицы под результат транспонирования
        errcode = s21_create_matrix(A->columns, A->rows, result);

        if (errcode == OK) {
            // Поэлементное умножение матрицы А на число number
            for (int i = 0; i < result->rows; ++i)
                for (int j = 0; j < result->columns; ++j)
                    result->matrix[i][j] = A->matrix[j][i];
        }
    }
    return (errcode);
}
