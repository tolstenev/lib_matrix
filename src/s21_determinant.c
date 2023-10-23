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
 * @brief Вычисляет определитель матрицы А
 * и записывает результат в result.
 * @param A - указатель на матрицу,
 * @param result - указатель на вычисленный определитель.
 * @return  0 - OK;
 *          1 - Ошибка, некорректная матрица;
 *          2 - Ошибка вычисления.
 */
int s21_determinant(matrix_t *A, double *result) {
    // Объявление переменной для возвращаемого кода ошибки
    int errcode = OK;

    if (s21_check_matrix(A) == INCORRECT_MATRIX) {
        // Код ошибки 1, если матрица А, матрица некорректная
        errcode = INCORRECT_MATRIX;
    } else if (!s21_is_square_matrix(A)) {
        // Код ошибки 2, если матрица не является квадратной
        errcode = CALC_ERROR;
    } else {
        // Вычисление детерминанта вспомогательной функцией
        *result = s21_calc_determinant(A);
    }
    return (errcode);
}

/**
 * @brief Вычисляет опеределитель матрицы без проверки
 * на корректность.
 * @param A - указатель на матрицу.
 * @return Определитель матрицы.
 */
double s21_calc_determinant(matrix_t *A) {
    // Объявление переменной для результата вычисления определителя
    double result = 0.0;

    if (A->rows == 1) {
        // Определитель матрицы 1-го порядка равен единственному
        // элементу этой матрицы
        result = A->matrix[0][0];
    } else if (A->rows == 2) {
        // Определитель матрицы 2-го порядка равен разнице
        // произведений главной и побочной диагоналей матрицы
        result = A->matrix[0][0] * A->matrix[1][1] -
                 A->matrix[0][1] * A->matrix[1][0];
    } else {
        // Определитель матрицы n-го порядка вычисляется
        // по рекурентной формуле: сумма от 0 до j
        // (-1)^(0 + j) * a(0, j) * M(0, j)
        // (ноль в произведении означает индекс первой строки i = 0)
        for (int j = 0; j < A->columns; ++j) {
            matrix_t matrix_for_minor = {NULL, 0, 0};

            if (s21_create_matrix_for_minor(A, 0, j, &matrix_for_minor) == OK) {
                int sign = ((0 + j) % 2) ? -1 : 1;
                result += sign * A->matrix[0][j] * s21_calc_determinant(&matrix_for_minor);
                s21_remove_matrix(&matrix_for_minor);
            }
        }
    }
    return (result);
}
