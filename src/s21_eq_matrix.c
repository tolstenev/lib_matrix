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
 * @brief Проверяет равенство матриц А и В.
 * @param A - указатель на матрицу,
 * @param B - указатель на матрицу.
 * @return  1 - ОК, матрицы равны;
 *          2 - Матрицы не равны.
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int rescode = SUCCESS;

    if (s21_check_matrix(A) == INCORRECT_MATRIX ||
        s21_check_matrix(B) == INCORRECT_MATRIX) {
        // Сравнение невозможно, если матрица А, матрица В - некорректные
        rescode = FAILURE;
    } else if (A->rows != B->rows || A->columns != B->columns) {
        // Сравнение невозможно, если размеры матриц не совпадают
        rescode = FAILURE;
    } else {
        // Поэлементное сравнение матриц А и В
        for (int i = 0; i < A->rows; ++i)
            for (int j = 0; j < A->columns; ++j)
                if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS)
                    // Матрицы не равны, если разница элементов превышает
                    // проверяемую точность вычислений
                    rescode = FAILURE;
    }
    return (rescode);
}
