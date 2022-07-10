/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"

/**
 * @brief Возвращает число из заданного массива
 */
int s21_get_number(void) {
    // Инициализируем карту значений
    const int array[16] = {21,  4,   8, 15,
                           16, 23,  42, 0,
                           97,  10,  7, 24,
                           81, 1, 73, 68 };
    // Инициализируем переменную для отслеживания количества вызовов функции
    static int i = 0;
    // Инкрементируем значение с каждым вызовом функции
    i += 1;
    // Присваеваем индексу значение остатка от деления на количество элементов массива
    i %= 16;
    return array[i];
}

/**
 * @brief Выводит матрицу на экран
 * @param A - указатель на матрицу.
 */
void s21_print_matrix(matrix_t *A) {
    putchar('\n');
    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
            printf("%4.f", A->matrix[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

/**
 * @brief Заполняет матрицу А значением value
 * @param A - указатель на матрицу,
 * @param value - заполняемое значение.
 */
void s21_fill_matrix_with_value(matrix_t *A, double value) {
    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
            A->matrix[i][j] = value;
        }
    }
}

/**
 * @brief Заполняет матрицу А псевдослучайными значениями
 * @param A - указатель на матрицу.
 */
void s21_fill_matrix(matrix_t *A) {
    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
            A->matrix[i][j] = s21_get_number();
        }
    }
}

/**
 * @brief Проверяет корректность матрицы А (указатель на неё и размеры матрицы)
 * @param A - указатель проверяемую на матрицу.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 */
int s21_check_matrix(matrix_t *A) {
    return (NULL == A/* || A->rows < 1 || A->columns < 1*/) ? INCORRECT_MATRIX
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


