/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"

/**
 * @brief Функция создаёт матрицу размером rows на columns
 * по указателю result.
 * @param rows - количество рядов,
 * @param columns - количество колонок,
 * @param result - указатель на созданную матрицу.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 *          2 - Ошибка вычисления.
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
    // Объявление переменной для возвращаемого кода ошибки
    int errcode = OK;
    if (rows < 1 || columns < 1) {
        // Код ошибки 1, если rows или columns - некорректные
        errcode = INCORRECT_MATRIX;
    } else {
        // Инициализация количества рядов и колонок в структуру матрицы
        result->rows = rows;
        result->columns = columns;
        // Выделение памяти под массив указателей на строки
        result->matrix = calloc(rows, sizeof(double *));

        if (NULL == result->matrix) {
            // Код ошибки 1, если память матрицы не была выделена
            errcode = INCORRECT_MATRIX;
        } else {
            // Инициализация указателей на строки матрицы
            for (int i = 0; i < rows; i++) {
                result->matrix[i] = calloc(columns, sizeof(double));
            }
        }
    }
    return (errcode);
}
