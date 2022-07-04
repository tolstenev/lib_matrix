/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"

/**
 * @brief Функция удаляет матрицу по указателю А.
 * @param A - указатель на матрицу
 */
void s21_remove_matrix(matrix_t *A) {
    if (NULL != A) {
        // Если указатель на матрицу А - ненулевой,
        // освобождаем память, выделенную под каждую строку матрицы
        for (int i = 0; i < rows; i++) {
            free(A->matrix[i]);
        }
        // Освобождаем память выделенную под массив указателей на строки
        free(A->matrix);
    }
}
