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
 * @brief Функция выводит на экран матрицу А.
 * @param A - указатель на матрицу.
 */
void s21_print_matrix(matrix_t *A) {
    putchar('\n');
    for (int i = 0; i < A->columns; ++i) {
        for (int j = 0; j < A->rows; ++j) {
            printf("%4.f", A->matrix[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

///**
// * @brief Функция выводит сообщение об ошибке памяти на экран,
// * и записывает его в поток вывода ошибок, устанавливая соответствующее
// * значение в errno.
// */
// void s21_halt_programm_memory_error(void) {
//    errno = ENOMEM;
//    fprintf(stderr, "Error: %s", strerror(errno));
//    exit(0);
//}

/**
 * @brief Заполняет матрицу А значение value
 * @param A - указатель на матрицу,
 * @param value - заполняемое значение.
 */
void s21_fill_matrix(matrix_t *A, double value) {
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
void s21_fill_matrix_rand(matrix_t *A) {
    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
            A->matrix[i][j] = s21_get_number();
        }
    }
}

/**
 * @brief Проверяет корректность матрицы (указатель и размеры)
 * @param m - указатель на матрицу.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 */
int s21_check_matrix(matrix_t *m) {
    int errcode = 0;
    if (NULL == m || m->rows < 1 || m->columns < 1) {
        errcode = 1;
    }
    return errcode;
}
