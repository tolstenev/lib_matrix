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
 * @brief Проверяет корректность матрицы (указатель и размеры)
 * @param m - указатель проверяемую на матрицу.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 */
int s21_check_matrix(matrix_t *m) {
    return (NULL == m || m->rows < 1 || m->columns < 1) ? INCORRECT_MATRIX
                                                        : OK;
}

/**
 * @brief Проверяет квадратная ли матрица
 * @param m - указатель проверяемую на матрицу.
 * @return  0 - Матрица не квадратная;
 *          1 - Матрица квадратная;
 */
int s21_is_square_matrix(matrix_t *m) {
    return (m->rows == m->columns) ? SUCCESS
                                   : FAILURE;
}

/**
 * @brief Функция записывает минор матрицы А в матрицу result.
 * @param A - указатель на матрицу,
 * @param row_skip - индекс строки элемента, для которого находится минор матрицы,
 * @param col_skip - индекс столбца элемента, для которого находится минор матрицы,
 * @param result - указатель на матрицу, в которую будет записан минор.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 *          2 - Ошибка вычисления.
 */
int s21_minor_matrix(matrix_t *A, int row_skip, int col_skip, matrix_t *result) {
    // Объявление переменной для возвращаемого кода ошибки
    int errcode = OK;

    if (s21_check_matrix(A) == INCORRECT_MATRIX) {
        // Код ошибки 1, если матрица А, матрица некорректная
        errcode = INCORRECT_MATRIX;
    } else if (!s21_is_square_matrix(A) || A->rows < 2) {
        // Код ошибки 2, если размеры матриц не совпадают
        errcode = CALC_ERROR;
    } else {
        // Объявление переменных для обращения к строкам и столбцам минора матрицы
        int i_minor = 0;
        int j_minor = 0;
        // Создание матрицы под результат вычисления
        s21_create_matrix(A->rows - 1, A->columns - 1, result);

        // Перебор строк матрицы А
        for (int i_matrix = 0; i_matrix < A->rows; ++i_matrix) {
            // Если рассматриваемый индекс строки и индекс минора совпадают,
            // переход к следующей строке
            if (i_matrix == row_skip)
                continue;
            // Обнуление индекса строки матрицы миноров (для последующих итераций)
            j_minor = 0;
            // Перебор элементов строки матрицы А
            for (int j_matrix = 0; j_matrix < A->columns; ++j_matrix) {
                // Если рассматриваемый индекс столбца и индекс минора совпадают,
                // переход к следующей строке
                if (j_matrix == col_skip)
                    continue;
                // Инициализация элемента минора соответствующим элементом матрицы
                result->matrix[i_minor][j_minor] = A->matrix[i_matrix][j_matrix];
                // Переход к следующему элементу строки минора
                ++j_minor;
            }
            // Переход к следующей строке минора
            ++i_minor;
        }
    }
    return (errcode);
}
