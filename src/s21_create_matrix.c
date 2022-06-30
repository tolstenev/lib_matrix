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
    /* Объявление переменной для возвращаемого кода ошибки */
    int errcode = 0;
    if (NULL == result) {
        /* Код ошибки 2, если указатель result - некорректный */
        errcode = 2;
    } else if (rows < 1 || columns < 1) {
        /* Код ошибки 1, если rows или columns - некорректные */
        errcode = 1;
    } else {
        /* Инициализация переменной, содержащий размер
         * массива указателей на ряды создаваемой матрицы */
        size_t arr_pointers = rows * sizeof(double *);
        /* Инициализация rows и columns в создаваемой матрице */
        result->rows = rows;
        result->columns = columns;
        /* Выделение памяти для содержимого матрицы осуществляется
         * одним вызовом calloc одновременно для массива указателей на ряды
         * и всех элементов матрицы */
        result->matrix = (double **)calloc(arr_pointers + \
                                           rows * columns * sizeof(double));
        if (NULL == result->matrix) {
            /* Код ошибки 2, если память для содержимого матрицы не была выделена */
            errcode = 2;
        } else {
            /* Инициализация переменной, содержащий указатель
             * на начало массива элементов матрицы */
            double *start = (double *)((char *)result->matrix + arr_pointers);
            /* Инициализируем указатели на ряды от начала массива элементов */
            for (int i = 0; i < rows; ++i) {
                result->matrix[i] = start + columns * i;
            }
        }
    }
    /* Возврат кода ошибки */
    return (errcode);
}