/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include "s21_matrix.h"
#define s21_get_var_name(var)  #var

void s21_print_matrix(matrix_t *A) {
    putchar('\n');
    for (int i = 0; i < A->columns; ++i) {
        for (int j = 0; j < A->rows; ++j) {
            printf("%4.f", **(A->matrix));
        }
        putchar('\n');
    }
    putchar('\n');
}

int main(void) {
    matrix_t A;

    s21_create_matrix(25, 25, &A);


    s21_print_matrix(&A);

    s21_remove_matrix(&A);
    return (0);
}
