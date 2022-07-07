/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"
#define s21_get_var_name(var)  #var

int main(void) {
    int correct_errcode_1 = OK;
    int buffer_errcode_1 = 42;

    matrix_t src_1_A = {NULL, 0, 0};
    matrix_t src_1_res = {NULL, 0, 0};

    s21_create_matrix(1, 1, &src_1_A);

    src_1_A.matrix[0][0] = 1.0;
//    src_1_A.matrix[0][1] = 2.0;
//    src_1_A.matrix[0][2] = 3.0;
//    src_1_A.matrix[1][0] = 4.0;
//    src_1_A.matrix[1][1] = 5.0;
//    src_1_A.matrix[1][2] = 6.0;
//    src_1_A.matrix[2][0] = 7.0;
//    src_1_A.matrix[2][1] = 8.0;
//    src_1_A.matrix[2][2] = 9.0;

    s21_print_matrix(&src_1_A);

    buffer_errcode_1 = s21_minor_matrix(&src_1_A, 0, 0, &src_1_res);

    s21_print_matrix(&src_1_res);

    printf("correct_errcode_1: %d\n", correct_errcode_1);
    printf("buffer_errcode_1: %d\n", buffer_errcode_1);

    s21_remove_matrix(&src_1_A);
    s21_remove_matrix(&src_1_res);

    return (0);
}
