/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"
#define s21_get_var_name(var)  #var

int main(void) {
    matrix_t src_1_A = {NULL, 0, 0};
    matrix_t src_1_res = {NULL, 0, 0};

    s21_create_matrix(3, 2, &src_1_A);

    src_1_A.matrix[0][0] = 1.0;
    src_1_A.matrix[0][1] = 4.0;
    src_1_A.matrix[1][0] = 2.0;
    src_1_A.matrix[1][1] = 5.0;
    src_1_A.matrix[2][0] = 3.0;
    src_1_A.matrix[2][1] = 6.0;

    s21_print_matrix(&src_1_A);

    s21_transpose(&src_1_A, &src_1_res);

    s21_print_matrix(&src_1_res);

    s21_remove_matrix(&src_1_A);

    return (0);
}
