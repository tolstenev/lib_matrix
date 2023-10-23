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
 * @brief Проверяет корректность матрицы А (указатель на неё и размеры матрицы)
 * @param A - указатель проверяемую на матрицу.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 */
int s21_check_matrix(matrix_t *A) {
    return (NULL == A || A->rows < 1 || A->columns < 1) ? INCORRECT_MATRIX
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
