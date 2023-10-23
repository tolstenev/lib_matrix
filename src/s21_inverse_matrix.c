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
 * @brief Находит обратную матрицу для матрицы А.
 * Найденная матрица записывается в result.
 * @param A - указатель на матрицу,
 * @param result - указатель на результат вычисления.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 *          2 - Ошибка вычисления.
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    // Объявление переменной для определителя матрицы А
    double det = 0.0;
    // Вычисление определителя матрицы А с сохранением кода ошибки
    int errcode = s21_determinant(A, &det);

    if (errcode == OK && det != 0.0) {
        // Если определитель успешно вычислен и не равен нулю,
        // объявляем две матрицы, для хранения промежуточных
        // результатов расчётов
        matrix_t tmp1 = {NULL, 0, 0};
        matrix_t tmp2 = {NULL, 0, 0};

        // Обратная матрица вычисляется как транспонированная
        // матрица алгебраических дополнений матрицы А, делённая на
        // определитель матрицы А
        s21_calc_complements(A, &tmp1);
        s21_transpose(&tmp1, &tmp2);
        s21_mult_number(&tmp2, 1.0 / det, result);

        // Удаление вспомогательных матриц
        s21_remove_matrix(&tmp1);
        s21_remove_matrix(&tmp2);
    }
    return (errcode);
}
