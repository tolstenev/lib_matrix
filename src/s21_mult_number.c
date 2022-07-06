/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"

/**
 * @brief Функция выполняет умножение матрицы А на число number.
 * Результат умножения записывается в матрицу result.
 * @param A - указатель на матрицу,
 * @param number - число, на которое будет умножена матрица,
 * @param result - указатель на результат умножения.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 *          2 - Ошибка вычисления.
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    // Объявление переменной для возвращаемого кода ошибки
    int errcode = OK;

    if (s21_check_matrix(A) == INCORRECT_MATRIX) {
        // Код ошибки 1, если матрица А, матрица некорректная.
        errcode = INCORRECT_MATRIX;
    } else {
        // Создание матрицы под результат сложения
        s21_create_matrix(A->rows, A->columns, result);
        // Поэлементное умножение матрицы А на число number
        for (int i = 0; i < result->rows; ++i)
            for (int j = 0; j < result->columns; ++j)
                result->matrix[i][j] = A->matrix[i][j] * number;
    }
    return (errcode);
}
