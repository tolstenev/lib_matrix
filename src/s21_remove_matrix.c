/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"
#include <errno.h>
/**
 * @brief Функция удаляет матрицу по указателю А.
 * @param A - указатель на матрицу
 */
void s21_remove_matrix(matrix_t *A) {
    if (NULL != A) {
        /* Вызов освобождения памяти, при условии что указатель на матрицу корректный */
        free(A->matrix);
    }
}
