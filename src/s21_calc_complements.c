/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"

/**
 * @brief Вычисляет алгебраические дополнения для матрицы А.
 * Результат вычисления записывается в матрицу result.
 * @param A - указатель на матрицу,
 * @param result - указатель на матрицу алгебраических дополнений.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 *          2 - Ошибка вычисления.
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
    // Объявление переменной для возвращаемого кода ошибки
    int errcode = OK;

    if (s21_check_matrix(A) == INCORRECT_MATRIX) {
        // Код ошибки 1, если матрица А, матрица некорректная
        errcode = INCORRECT_MATRIX;
    } else if (!s21_is_square_matrix(A) || A->rows < 2) {
        // Код ошибки 2, если А - матрица первого порядка,
        // или А не является квадратной матрицей
        errcode = CALC_ERROR;
    } else {
        // Создание матрицы под результат вычисления
        errcode = s21_create_matrix(A->rows, A->columns, result);

        if (errcode == OK) {
            // Перебор элементов матрицы А
            for (int i = 0; i < A->rows; ++i)
                for (int j = 0; j < A->columns; ++j)
                    // Инициализация элементов матрицы алгебраических дополнений
                    result->matrix[i][j] = s21_calc_one_complement(A, i, j);
        }
    }
    return (errcode);
}

/**
 * @brief Записывает в матрицу result матрицу А с вычеркнутыми
 * рядом row_skip и столбцом col_skip, для последующего вычисления
 * минора элемента а(row_skip, col_skip) матрицы А.
 * @param A - указатель на матрицу,
 * @param row_skip - индекс строки элемента, которая будет вычеркнута,
 * @param col_skip - индекс столбца элемента, который будет вычернут,
 * @param result - указатель на матрицу.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 *          2 - Ошибка вычисления.
 */
int s21_matrix_for_minor(matrix_t *A, int row_skip, int col_skip, matrix_t *result) {
    // Объявление переменной для возвращаемого кода ошибки
    int errcode = OK;

    if (s21_check_matrix(A) == INCORRECT_MATRIX) {
        // Код ошибки 1, если матрица А, матрица некорректная
        errcode = INCORRECT_MATRIX;
    } else if (!s21_is_square_matrix(A) || A->rows < 2) {
        // Код ошибки 2, если А - матрица первого порядка,
        // или А не является квадратной матрицей
        errcode = CALC_ERROR;
    } else {
        // Создание матрицы под результат вычеркивания (порядок матрицы на 1 меньше)
        errcode = s21_create_matrix(A->rows - 1, A->columns - 1, result);

        if (errcode == OK) {
            // Объявление переменных для обращения к строкам и столбцам минора матрицы
            int i_minor = 0;
            int j_minor = 0;
            // Перебор строк входящей матрицы А
            for (int i_matrix = 0; i_matrix < A->rows; ++i_matrix) {
                // Если рассматриваемый индекс строки и индекс элемента, относительно которого
                // строится матрица совпадают, переход к следующей строке (потому что она нам
                // не нужна, она должна быть вычеркнута)
                if (i_matrix == row_skip)
                    continue;
                // Обнуление индекса строки матрицы миноров (для последующих итераций, когда
                // будет осуществляться переход к очередной строке)
                j_minor = 0;
                // Перебор элементов строки матрицы А
                for (int j_matrix = 0; j_matrix < A->columns; ++j_matrix) {
                    // Если рассматриваемый индекс столбца и индекс элемента, относительно которого
                    // строится матрица совпадают, переход к следующему элементу строки (элемент
                    // не учитывается)
                    if (j_matrix == col_skip)
                        continue;
                    // Инициализация создаваемой матрицы соответствующим элементом исходной матрицы
                    // с учётом вычеркнутых строк и элементов
                    result->matrix[i_minor][j_minor] = A->matrix[i_matrix][j_matrix];
                    // Переход к следующему элементу строки создаваемой матрицы
                    ++j_minor;
                }
                // Переход к следующей строке создаваемой матрицы
                ++i_minor;
            }
        }
    }
    return (errcode);
}

/**
 * @brief Вычисляет минор элемента а(row_skip, col_skip) матрицы А.
 * @param row_skip - индекс строки элемента, для которого будет вычислен минор,
 * @param col_skip - индекс столбца элемента, для которого будет вычислен минор.
 * @return Значение минора типа double
 */
double s21_calc_minor(matrix_t *A, int row_skip, int col_skip) {
    // Объявление переменной для результата вычисления минора и
    // матрицы с вычеркнутыми рядом row_skip и столбцом col_skip
    double result = 0.0;
    matrix_t matrix_for_minor = {NULL, 0, 0};

    if (s21_matrix_for_minor(A, row_skip, col_skip, &matrix_for_minor) == OK)
        // Если матрица была успешно создана, вычисляем определитель для
        // матрицы с вычеркнутыми рядом row_skip и столбцом col_skip
        result = s21_calc_determinant(&matrix_for_minor);

    s21_remove_matrix(&matrix_for_minor);
    return (result);
}

/**
 * @brief Вычисляет алгебраическое дополнение элемента а(row_skip, col_skip)
 * матрицы А.
 * @param A - указатель на матрицу,
 * @param row_skip - индекс строки элемента,для которого производится вычисление,
 * @param col_skip - индекс столбца элемента, для которого производится вычисление.
 * @return Значение минора типа double
 */
double s21_calc_one_complement(matrix_t *A, int row_skip, int col_skip) {
    // Алгебраическим дополнением элемента a(i, j) матрицы является значение минора,
    // умноженное на (-1)^(i + j)
    int sign = ((row_skip + col_skip) % 2) ? -1 : 1;
    return (sign * s21_calc_minor(A, row_skip, col_skip));
}
