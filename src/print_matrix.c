/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"
#define s21_get_var_name(var)  #var

int main(void) {
    matrix_t A = {NULL, 0, 0};
    int i = 3;
    s21_create_matrix(i, i, &A);

    s21_print_matrix(&A);
    s21_fill_matrix_rand(&A);
    s21_print_matrix(&A);

    s21_remove_matrix(&A);

    return (0);
}
