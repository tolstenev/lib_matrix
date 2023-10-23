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
 * @brief Cоздаёт матрицу размером rows на columns
 * по указателю result.
 * @param rows - количество рядов,
 * @param columns - количество колонок,
 * @param result - указатель на созданную матрицу.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица.
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
    // Объявление переменной для возвращаемого кода ошибки
    int errcode = OK;
    if (rows < 1 || columns < 1) {
        // Код ошибки 1, если rows или columns - некорректные
        errcode = INCORRECT_MATRIX;
    } else {
        // Инициализация количества рядов и колонок в структуру матрицы
        result->rows = rows;
        result->columns = columns;
        // Выделение памяти под массив указателей на строки
        result->matrix = calloc(rows, sizeof(double *));

        if (NULL == result->matrix) {
            // Код ошибки 1, если память для матрицы не была выделена
            errcode = INCORRECT_MATRIX;
        } else {
            // Инициализация указателей на строки матрицы
            for (int i = 0; i < rows; i++) {
                result->matrix[i] = calloc(columns, sizeof(double));
            }
        }
    }
    return (errcode);
}
