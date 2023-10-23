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
 * @brief Удаляет матрицу по указателю А.
 * @param A - указатель на матрицу.
 */
void s21_remove_matrix(matrix_t *A) {
    if (NULL != A) {
        // Если указатель на матрицу А - ненулевой,
        // освобождаем память, выделенную под каждую строку матрицы
        for (int i = 0; i < A->rows; i++) {
            free(A->matrix[i]);
        }
        // Освобождаем память выделенную под массив указателей на строки
        free(A->matrix);
        // Зануляем переменные, содержащие значения количества колонок и рядов
        A->columns = 0;
        A->rows = 0;
    }
}
