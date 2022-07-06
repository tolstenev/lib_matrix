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
    // Объявление переменной для возвращаемого кода ошибки
    int errcode = OK;

    if (s21_check_matrix(A) == INCORRECT_MATRIX) {
        // Код ошибки 1, если матрица А, матрица некорректная.
        errcode = INCORRECT_MATRIX;
    } else {
        // Создание матрицы под результат транспонирования
        s21_create_matrix(A->rows, A->columns, result);


        return (errcode);
    }
