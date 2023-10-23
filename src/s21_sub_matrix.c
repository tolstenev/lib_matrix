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
 * @brief Выполняет вычитание матрицы А из матрицы В.
 * Результат вычитания записывается в матрицу result.
 * @param A - указатель на матрицу (уменьшаемое),
 * @param B - указатель на матрицу (вычитаемое),
 * @param result - указатель на результат вычитания.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 *          2 - Ошибка вычисления.
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    // Объявление переменной для возвращаемого кода ошибки
    int errcode = OK;

    if (s21_check_matrix(A) == INCORRECT_MATRIX ||
        s21_check_matrix(B) == INCORRECT_MATRIX) {
        // Код ошибки 1, если матрица А, матрица В - некорректные
        errcode = INCORRECT_MATRIX;
    } else if (A->rows != B->rows || A->columns != B->columns) {
        // Код ошибки 2, если размеры матриц не совпадают
        errcode = CALC_ERROR;
    } else {
        // Создание матрицы под результат вычитания
        errcode = s21_create_matrix(A->rows, A->columns, result);

        if (errcode == OK) {
            // Поэлементное вычитание матрицы В из А
            for (int i = 0; i < result->rows; ++i)
                for (int j = 0; j < result->columns; ++j)
                    result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
    }
    return (errcode);
}

