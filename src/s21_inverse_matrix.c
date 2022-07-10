/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
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
