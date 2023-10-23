/*
 * Copyright 2023 Gleb Tolstenev
 * tolstenev.gleb@mail.ru
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "s21_matrix.h"

/**
 * @brief Выполняет умножение матрицы А на матрицу В.
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
