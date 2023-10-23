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

#include <check.h>
#include <string.h>
#include "s21_matrix.h"

START_TEST(test_s21_create_matrix) {
    // Создание матрицы
    int correct_errcode_1 = OK;
    int buffer_errcode_1 = 42;
    int src_1_rows = 3;
    int src_1_cols = 3;
    matrix_t src_1 = {NULL, 0, 0 };

    buffer_errcode_1 = s21_create_matrix(src_1_rows, src_1_cols, &src_1);

    ck_assert_int_eq(src_1_rows, src_1.rows);
    ck_assert_int_eq(src_1_cols, src_1.columns);
    ck_assert_ptr_nonnull(src_1.matrix);
    ck_assert_int_eq(correct_errcode_1, buffer_errcode_1);

    s21_remove_matrix(&src_1);

    // ОШИБКИ
    // Проверка на некорректные значения количества рядов и колонок
    int correct_errcode_2 = INCORRECT_MATRIX;
    int buffer_errcode_2 = 42;
    int src_2_rows = -21;
    int src_2_cols = -21;
    matrix_t src_2 = {NULL, 0, 0 };

    buffer_errcode_2 = s21_create_matrix(src_2_rows, src_2_cols, &src_2);

    ck_assert_int_eq(correct_errcode_2, buffer_errcode_2);

    s21_remove_matrix(&src_2);
}
END_TEST

START_TEST(test_s21_eq_matrix) {
    // Cравнение одинаковых матриц
    int correct_rescode_1 = SUCCESS;
    int buffer_rescode_1 = 42;
    int src_1_rows = 2;
    int src_1_cols = 2;
    matrix_t src_1_A = {NULL, 0, 0};
    matrix_t src_1_B = {NULL, 0, 0};

    s21_create_matrix(src_1_rows, src_1_cols, &src_1_A);
    s21_create_matrix(src_1_rows, src_1_cols, &src_1_B);

    src_1_A.matrix[0][0] = 21.0;
    src_1_A.matrix[0][1] = 21.0;
    src_1_A.matrix[1][0] = 21.0;
    src_1_A.matrix[1][1] = 21.0;

    src_1_B.matrix[0][0] = 21.0;
    src_1_B.matrix[0][1] = 21.0;
    src_1_B.matrix[1][0] = 21.0;
    src_1_B.matrix[1][1] = 21.0;

    buffer_rescode_1 = s21_eq_matrix(&src_1_A, &src_1_B);

    ck_assert_int_eq(correct_rescode_1, buffer_rescode_1);

    s21_remove_matrix(&src_1_A);
    s21_remove_matrix(&src_1_B);

    // Сравнение различных матриц: различие больше проверяемой точности
    int correct_rescode_2 = FAILURE;
    int buffer_rescode_2 = 42;
    int src_2_rows = 2;
    int src_2_cols = 2;
    matrix_t src_2_A = {NULL, 0, 0};
    matrix_t src_2_B = {NULL, 0, 0};

    s21_create_matrix(src_2_rows, src_2_cols, &src_2_A);
    s21_create_matrix(src_2_rows, src_2_cols, &src_2_B);

    src_2_A.matrix[0][0] = 21.0;
    src_2_A.matrix[0][1] = 21.0;
    src_2_A.matrix[1][0] = 21.0;
    src_2_A.matrix[1][1] = 21.0;

    src_2_B.matrix[0][0] = 21.0;
    src_2_B.matrix[0][1] = 21.9999;
    src_2_B.matrix[1][0] = 21.0;
    src_2_B.matrix[1][1] = 21.0;

    buffer_rescode_2 = s21_eq_matrix(&src_2_A, &src_2_B);

    ck_assert_int_eq(correct_rescode_2, buffer_rescode_2);

    s21_remove_matrix(&src_2_A);
    s21_remove_matrix(&src_2_B);

    // Сравнение различных матриц: различие меньше проверяемой точности
    int correct_rescode_3 = FAILURE;
    int buffer_rescode_3 = 42;
    int src_3_rows = 2;
    int src_3_cols = 2;
    matrix_t src_3_A = {NULL, 0, 0};
    matrix_t src_3_B = {NULL, 0, 0};

    s21_create_matrix(src_3_rows, src_3_cols, &src_3_A);
    s21_create_matrix(src_3_rows, src_3_cols, &src_3_B);

    src_3_A.matrix[0][0] = 21.0;
    src_3_A.matrix[0][1] = 21.0;
    src_3_A.matrix[1][0] = 21.0;
    src_3_A.matrix[1][1] = 21.0;

    src_3_B.matrix[0][0] = 21.0;
    src_3_B.matrix[0][1] = 21.0;
    src_3_B.matrix[1][0] = 21.0000009;
    src_3_B.matrix[1][1] = 21.0;

    buffer_rescode_3 = s21_eq_matrix(&src_3_A, &src_3_B);

    ck_assert_int_eq(correct_rescode_3, buffer_rescode_3);

    s21_remove_matrix(&src_3_A);
    s21_remove_matrix(&src_3_B);

    // Сравнение матрицы с самой собой
    int correct_rescode_4 = SUCCESS;
    int buffer_rescode_4 = 42;
    int src_4_rows = 2;
    int src_4_cols = 2;
    matrix_t src_4 = {NULL, 0, 0};

    s21_create_matrix(src_4_rows, src_4_cols, &src_4);

    src_4.matrix[0][0] = 21.0;
    src_4.matrix[0][1] = 21.0;
    src_4.matrix[1][0] = 21.0;
    src_4.matrix[1][1] = 21.0;

    buffer_rescode_4 = s21_eq_matrix(&src_4, &src_4);

    ck_assert_int_eq(correct_rescode_4, buffer_rescode_4);

    s21_remove_matrix(&src_4);

    // ОШИБКИ
    // Матрицы не совпадают по размерам
    int correct_rescode_5 = FAILURE;
    int buffer_rescode_5 = 42;
    matrix_t src_5_A = {NULL, 0, 0};
    matrix_t src_5_B = {NULL, 0, 0};

    s21_create_matrix(2, 2, &src_5_A);
    s21_create_matrix(3, 2, &src_5_B);

    src_5_A.matrix[0][0] = 21.0;
    src_5_A.matrix[0][1] = 21.0;
    src_5_A.matrix[1][0] = 21.0;
    src_5_A.matrix[1][1] = 21.0;

    src_5_B.matrix[0][0] = 21.0;
    src_5_B.matrix[0][1] = 21.0;
    src_5_B.matrix[1][0] = 21.0;
    src_5_B.matrix[1][1] = 21.0;
    src_5_B.matrix[2][0] = 21.0;
    src_5_B.matrix[2][1] = 21.0;

    buffer_rescode_5 = s21_eq_matrix(&src_5_A, &src_5_B);

    ck_assert_int_eq(correct_rescode_5, buffer_rescode_5);

    s21_remove_matrix(&src_5_A);
    s21_remove_matrix(&src_5_B);
}
END_TEST

START_TEST(test_s21_sum_matrix) {
    // Сложение двух матриц
    int correct_errcode_1 = OK;
    int buffer_errcode_1 = 42;
    int src_1_rows = 2;
    int src_1_cols = 2;

    matrix_t src_1_A = {NULL, 0, 0};
    matrix_t src_1_B = {NULL, 0, 0};
    matrix_t src_1_res = {NULL, 0, 0};

    s21_create_matrix(src_1_rows, src_1_cols, &src_1_A);
    s21_create_matrix(src_1_rows, src_1_cols, &src_1_B);

    src_1_A.matrix[0][0] = 1.0;
    src_1_A.matrix[0][1] = -1.5;
    src_1_A.matrix[1][0] = -1.0;
    src_1_A.matrix[1][1] = 1.123456;

    src_1_B.matrix[0][0] = 1.0;
    src_1_B.matrix[0][1] = 1.5;
    src_1_B.matrix[1][0] = -1.0;
    src_1_B.matrix[1][1] = 6.654321;

    buffer_errcode_1 = s21_sum_matrix(&src_1_A, &src_1_B, &src_1_res);

    ck_assert_double_eq_tol(src_1_res.matrix[0][0], 2.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[0][1], 0.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][0], -2.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][1], 7.777777, EPS);
    ck_assert_int_eq(correct_errcode_1, buffer_errcode_1);

    s21_remove_matrix(&src_1_A);
    s21_remove_matrix(&src_1_B);
    s21_remove_matrix(&src_1_res);

    // ОШИБКИ
    // Матрицы не совпадают по размерам
    int correct_errcode_2 = CALC_ERROR;
    int buffer_errcode_2 = 42;

    matrix_t src_2_A = {NULL, 0, 0};
    matrix_t src_2_B = {NULL, 0, 0};
    matrix_t src_2_res = {NULL, 0, 0};

    s21_create_matrix(2, 2, &src_2_A);
    s21_create_matrix(3, 3, &src_2_B);

    buffer_errcode_2 = s21_sum_matrix(&src_2_A, &src_2_B, &src_2_res);

    ck_assert_int_eq(correct_errcode_2, buffer_errcode_2);

    s21_remove_matrix(&src_2_A);
    s21_remove_matrix(&src_2_B);
    s21_remove_matrix(&src_2_res);
}
END_TEST

START_TEST(test_s21_sub_matrix) {
    // Разность двух матриц
    int correct_errcode_1 = OK;
    int buffer_errcode_1 = 42;
    int src_1_rows = 2;
    int src_1_cols = 2;

    matrix_t src_1_A = {NULL, 0, 0};
    matrix_t src_1_B = {NULL, 0, 0};
    matrix_t src_1_res = {NULL, 0, 0};

    s21_create_matrix(src_1_rows, src_1_cols, &src_1_A);
    s21_create_matrix(src_1_rows, src_1_cols, &src_1_B);

    src_1_A.matrix[0][0] = 1.0;
    src_1_A.matrix[0][1] = -1.5;
    src_1_A.matrix[1][0] = -1.0;
    src_1_A.matrix[1][1] = 9.999999;

    src_1_B.matrix[0][0] = 1.0;
    src_1_B.matrix[0][1] = 1.5;
    src_1_B.matrix[1][0] = -1.0;
    src_1_B.matrix[1][1] = 2.222222;

    buffer_errcode_1 = s21_sub_matrix(&src_1_A, &src_1_B, &src_1_res);

    ck_assert_double_eq_tol(src_1_res.matrix[0][0], 0.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[0][1], -3.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][0], 0.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][1], 7.777777, EPS);
    ck_assert_int_eq(correct_errcode_1, buffer_errcode_1);

    s21_remove_matrix(&src_1_A);
    s21_remove_matrix(&src_1_B);
    s21_remove_matrix(&src_1_res);

    // ОШИБКИ
    // Матрицы не совпадают по размерам
    int correct_errcode_2 = CALC_ERROR;
    int buffer_errcode_2 = 42;

    matrix_t src_2_A = {NULL, 0, 0};
    matrix_t src_2_B = {NULL, 0, 0};
    matrix_t src_2_res = {NULL, 0, 0};

    s21_create_matrix(2, 2, &src_2_A);
    s21_create_matrix(3, 3, &src_2_B);

    buffer_errcode_2 = s21_sub_matrix(&src_2_A, &src_2_B, &src_2_res);

    ck_assert_int_eq(correct_errcode_2, buffer_errcode_2);

    s21_remove_matrix(&src_2_A);
    s21_remove_matrix(&src_2_B);
    s21_remove_matrix(&src_2_res);
}
END_TEST

START_TEST(test_s21_mult_number) {
    // Умножение матрицы на число
    int correct_errcode_1 = OK;
    int buffer_errcode_1 = 42;
    int src_1_rows = 3;
    int src_1_cols = 3;
    double src_1_num = 3.14159;

    matrix_t src_1_A = {NULL, 0, 0};
    matrix_t src_1_res = {NULL, 0, 0};

    s21_create_matrix(src_1_rows, src_1_cols, &src_1_A);

    src_1_A.matrix[0][0] = 1.0;
    src_1_A.matrix[0][1] = -1.9;
    src_1_A.matrix[0][2] = 0.0;
    src_1_A.matrix[1][0] = 0.0000001;
    src_1_A.matrix[1][1] = 1234567890123456.0;
    src_1_A.matrix[1][2] = -0.0;

    buffer_errcode_1 = s21_mult_number(&src_1_A, src_1_num, &src_1_res);

    ck_assert_double_eq_tol(src_1_res.matrix[0][0], 3.14159, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[0][1], -5.969021, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[0][2], 0.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][0], 0.0000003, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][1], 3878506137932948.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][2], -0.0, EPS);
    ck_assert_int_eq(correct_errcode_1, buffer_errcode_1);

    s21_remove_matrix(&src_1_A);
    s21_remove_matrix(&src_1_res);
}
END_TEST

START_TEST(test_s21_mult_matrix) {
    // Умножение двух матриц
    int correct_errcode_1 = OK;
    int buffer_errcode_1 = 42;

    matrix_t src_1_A = {NULL, 0, 0};
    matrix_t src_1_B = {NULL, 0, 0};
    matrix_t src_1_res = {NULL, 0, 0};

    s21_create_matrix(3, 2, &src_1_A);
    s21_create_matrix(2, 3, &src_1_B);

    src_1_A.matrix[0][0] = 1.0;
    src_1_A.matrix[0][1] = 4.0;
    src_1_A.matrix[1][0] = 2.0;
    src_1_A.matrix[1][1] = 5.0;
    src_1_A.matrix[2][0] = 3.0;
    src_1_A.matrix[2][1] = 6.0;

    src_1_B.matrix[0][0] = 1.0;
    src_1_B.matrix[0][1] = -1.0;
    src_1_B.matrix[0][2] = 1.0;
    src_1_B.matrix[1][0] = 2.0;
    src_1_B.matrix[1][1] = 3.0;
    src_1_B.matrix[1][2] = 4.0;

    buffer_errcode_1 = s21_mult_matrix(&src_1_A, &src_1_B, &src_1_res);

    ck_assert_double_eq_tol(src_1_res.matrix[0][0], 9.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[0][1], 11.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[0][2], 17.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][0], 12.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][1], 13.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][2], 22.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[2][0], 15.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[2][1], 15.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[2][2], 27.0, EPS);
    ck_assert_int_eq(correct_errcode_1, buffer_errcode_1);

    s21_remove_matrix(&src_1_A);
    s21_remove_matrix(&src_1_B);
    s21_remove_matrix(&src_1_res);

    // ОШИБКИ
    // Матрицы не совпадают по размерам
    int correct_errcode_2 = CALC_ERROR;
    int buffer_errcode_2 = 42;

    matrix_t src_2_A = {NULL, 0, 0};
    matrix_t src_2_B = {NULL, 0, 0};
    matrix_t src_2_res = {NULL, 0, 0};

    s21_create_matrix(2, 2, &src_2_A);
    s21_create_matrix(3, 3, &src_2_B);

    buffer_errcode_2 = s21_mult_matrix(&src_2_A, &src_2_B, &src_2_res);

    ck_assert_int_eq(correct_errcode_2, buffer_errcode_2);

    s21_remove_matrix(&src_2_A);
    s21_remove_matrix(&src_2_B);
    s21_remove_matrix(&src_2_res);
}
END_TEST

START_TEST(test_s21_transpose) {
    // Транспонирование матрицы
    int correct_errcode_1 = OK;
    int buffer_errcode_1 = 42;

    matrix_t src_1_A = {NULL, 0, 0};
    matrix_t src_1_res = {NULL, 0, 0};

    s21_create_matrix(3, 2, &src_1_A);

    src_1_A.matrix[0][0] = 1.0;
    src_1_A.matrix[0][1] = 4.0;
    src_1_A.matrix[1][0] = 2.0;
    src_1_A.matrix[1][1] = 5.0;
    src_1_A.matrix[2][0] = 3.0;
    src_1_A.matrix[2][1] = 6.0;

    buffer_errcode_1 = s21_transpose(&src_1_A, &src_1_res);

    ck_assert_double_eq_tol(src_1_res.matrix[0][0], 1.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[0][1], 2.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[0][2], 3.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][0], 4.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][1], 5.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][2], 6.0, EPS);
    ck_assert_int_eq(correct_errcode_1, buffer_errcode_1);

    s21_remove_matrix(&src_1_A);
    s21_remove_matrix(&src_1_res);
}
END_TEST

START_TEST(test_s21_calc_complements) {
    // Вычисление матрицы алгебраических дополнений для матрицы 3-го порядка
    int correct_errcode_1 = OK;
    int buffer_errcode_1 = 42;

    matrix_t src_1_A = {NULL, 0, 0};
    matrix_t src_1_res = {NULL, 0, 0};

    s21_create_matrix(3, 3, &src_1_A);

    src_1_A.matrix[0][0] = 1.0;
    src_1_A.matrix[0][1] = 2.0;
    src_1_A.matrix[0][2] = 3.0;
    src_1_A.matrix[1][0] = 0.0;
    src_1_A.matrix[1][1] = 4.0;
    src_1_A.matrix[1][2] = 2.0;
    src_1_A.matrix[2][0] = 5.0;
    src_1_A.matrix[2][1] = 2.0;
    src_1_A.matrix[2][2] = 1.0;

    buffer_errcode_1 = s21_calc_complements(&src_1_A, &src_1_res);

    ck_assert_double_eq_tol(src_1_res.matrix[0][0], 0.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[0][1], 10.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[0][2], -20.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][0], 4.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][1], -14.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][2], 8.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[2][0], -8.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[2][1], -2.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[2][2], 4.0, EPS);
    ck_assert_int_eq(correct_errcode_1, buffer_errcode_1);

    s21_remove_matrix(&src_1_A);
    s21_remove_matrix(&src_1_res);
}
END_TEST

START_TEST(test_s21_determinant) {
    // Детерминат матрицы 1-го порядка
    int correct_errcode_1 = OK;
    int buffer_errcode_1 = 42;
    matrix_t src_1_A = {NULL, 0, 0};
    double src_1_res = 0.0;

    s21_create_matrix(1, 1, &src_1_A);

    src_1_A.matrix[0][0] = 23.42;

    buffer_errcode_1 = s21_determinant(&src_1_A, &src_1_res);

    ck_assert_double_eq_tol(src_1_res, 23.42, EPS);
    ck_assert_int_eq(correct_errcode_1, buffer_errcode_1);

    s21_remove_matrix(&src_1_A);

    // Детерминат матрицы 2-го порядка
    int correct_errcode_2 = OK;
    int buffer_errcode_2 = 42;
    matrix_t src_2_A = {NULL, 0, 0};
    double src_2_res = 0.0;

    s21_create_matrix(2, 2, &src_2_A);

    src_2_A.matrix[0][0] = 4.0;
    src_2_A.matrix[0][1] = 8.0;
    src_2_A.matrix[1][0] = 15.0;
    src_2_A.matrix[1][1] = 16.0;

    buffer_errcode_2 = s21_determinant(&src_2_A, &src_2_res);

    ck_assert_double_eq_tol(src_2_res, -56, EPS);
    ck_assert_int_eq(correct_errcode_2, buffer_errcode_2);

    s21_remove_matrix(&src_2_A);

    // Детерминат матрицы 3-го порядка
    int correct_errcode_3 = OK;
    int buffer_errcode_3 = 42;
    matrix_t src_3_A = {NULL, 0, 0};
    double src_3_res = 0.0;

    s21_create_matrix(3, 3, &src_3_A);

    src_3_A.matrix[0][0] = 0.123;
    src_3_A.matrix[0][1] = 5.21;
    src_3_A.matrix[0][2] = 9.515;
    src_3_A.matrix[1][0] = 4.815;
    src_3_A.matrix[1][1] = 42.0;
    src_3_A.matrix[1][2] = 23.42;
    src_3_A.matrix[2][0] = 0.99;
    src_3_A.matrix[2][1] = 710;
    src_3_A.matrix[2][2] = 21.0;

    buffer_errcode_3 = s21_determinant(&src_3_A, &src_3_res);

    ck_assert_double_eq_tol(src_3_res, 29790.027318, EPS);
    ck_assert_int_eq(correct_errcode_3, buffer_errcode_3);

    s21_remove_matrix(&src_3_A);

    // ОШИБКИ
    // Детерминат неквадратной матрицы
    int correct_errcode_4 = CALC_ERROR;
    int buffer_errcode_4 = 21;
    matrix_t src_4_A = {NULL, 0, 0};
    double src_4_res = 0.0;

    s21_create_matrix(1, 2, &src_4_A);

    src_4_A.matrix[0][0] = 23;
    src_4_A.matrix[0][1] = 42;

    buffer_errcode_4 = s21_determinant(&src_4_A, &src_4_res);

    ck_assert_int_eq(correct_errcode_4, buffer_errcode_4);

    s21_remove_matrix(&src_4_A);
}
END_TEST

START_TEST(test_s21_inverse_matrix) {
    // Вычисление обратной матрицы для матрицы 3-го порядка
    int correct_errcode_1 = OK;
    int buffer_errcode_1 = 42;

    matrix_t src_1_A = {NULL, 0, 0};
    matrix_t src_1_res = {NULL, 0, 0};

    s21_create_matrix(3, 3, &src_1_A);

    src_1_A.matrix[0][0] = 2.0;
    src_1_A.matrix[0][1] = 5.0;
    src_1_A.matrix[0][2] = 7.0;
    src_1_A.matrix[1][0] = 6.0;
    src_1_A.matrix[1][1] = 3.0;
    src_1_A.matrix[1][2] = 4.0;
    src_1_A.matrix[2][0] = 5.0;
    src_1_A.matrix[2][1] = -2.0;
    src_1_A.matrix[2][2] = -3.0;

    buffer_errcode_1 = s21_inverse_matrix(&src_1_A, &src_1_res);

    ck_assert_double_eq_tol(src_1_res.matrix[0][0], 1.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[0][1], -1.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[0][2], 1.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][0], -38.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][1], 41.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][2], -34.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[2][0], 27.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[2][1], -29.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[2][2], 24.0, EPS);
    ck_assert_int_eq(correct_errcode_1, buffer_errcode_1);

    s21_remove_matrix(&src_1_A);
    s21_remove_matrix(&src_1_res);
}
END_TEST

START_TEST(test_s21_calc_minor) {
    // Построение матрицы миноров для матрицы 3-го порядка
    matrix_t src_1_A = {NULL, 0, 0};
    matrix_t src_1_res = {NULL, 0, 0};

    s21_create_matrix(3, 3, &src_1_A);
    s21_create_matrix(3, 3, &src_1_res);

    src_1_A.matrix[0][0] = 1.0;
    src_1_A.matrix[0][1] = 2.0;
    src_1_A.matrix[0][2] = 3.0;
    src_1_A.matrix[1][0] = 0.0;
    src_1_A.matrix[1][1] = 4.0;
    src_1_A.matrix[1][2] = 2.0;
    src_1_A.matrix[2][0] = 5.0;
    src_1_A.matrix[2][1] = 2.0;
    src_1_A.matrix[2][2] = 1.0;

    src_1_res.matrix[0][0] = s21_calc_minor(&src_1_A, 0, 0);
    src_1_res.matrix[0][1] = s21_calc_minor(&src_1_A, 0, 1);
    src_1_res.matrix[0][2] = s21_calc_minor(&src_1_A, 0, 2);
    src_1_res.matrix[1][0] = s21_calc_minor(&src_1_A, 1, 0);
    src_1_res.matrix[1][1] = s21_calc_minor(&src_1_A, 1, 1);
    src_1_res.matrix[1][2] = s21_calc_minor(&src_1_A, 1, 2);
    src_1_res.matrix[2][0] = s21_calc_minor(&src_1_A, 2, 0);
    src_1_res.matrix[2][1] = s21_calc_minor(&src_1_A, 2, 1);
    src_1_res.matrix[2][2] = s21_calc_minor(&src_1_A, 2, 2);

    ck_assert_double_eq_tol(src_1_res.matrix[0][0], 0.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[0][1], -10.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[0][2], -20.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][0], -4.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][1], -14.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][2], -8.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[2][0], -8.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[2][1], 2.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[2][2], 4.0, EPS);

    s21_remove_matrix(&src_1_A);
    s21_remove_matrix(&src_1_res);
}
END_TEST

START_TEST(test_s21_matrix_for_minor) {
    // Получение матрицы с вычеркнутым рядом и столбцом (0,0) матрицы 3 х 3
    int correct_errcode_1 = OK;
    int buffer_errcode_1 = 42;

    matrix_t src_1_A = {NULL, 0, 0};
    matrix_t src_1_res = {NULL, 0, 0};

    s21_create_matrix(3, 3, &src_1_A);

    src_1_A.matrix[0][0] = 1.0;
    src_1_A.matrix[0][1] = 2.0;
    src_1_A.matrix[0][2] = 3.0;
    src_1_A.matrix[1][0] = 4.0;
    src_1_A.matrix[1][1] = 5.0;
    src_1_A.matrix[1][2] = 6.0;
    src_1_A.matrix[2][0] = 7.0;
    src_1_A.matrix[2][1] = 8.0;
    src_1_A.matrix[2][2] = 9.0;

    buffer_errcode_1 = s21_create_matrix_for_minor(&src_1_A, 0, 0, &src_1_res);

    ck_assert_double_eq_tol(src_1_res.matrix[0][0], 5.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[0][1], 6.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][0], 8.0, EPS);
    ck_assert_double_eq_tol(src_1_res.matrix[1][1], 9.0, EPS);
    ck_assert_int_eq(correct_errcode_1, buffer_errcode_1);

    s21_remove_matrix(&src_1_A);
    s21_remove_matrix(&src_1_res);

    // Получение матрицы с вычеркнутым рядом и столбцом (1,1) матрицы 3 х 3
    int correct_errcode_2 = OK;
    int buffer_errcode_2 = 42;

    matrix_t src_2_A = {NULL, 0, 0};
    matrix_t src_2_res = {NULL, 0, 0};

    s21_create_matrix(3, 3, &src_2_A);

    src_2_A.matrix[0][0] = 1.0;
    src_2_A.matrix[0][1] = 2.0;
    src_2_A.matrix[0][2] = 3.0;
    src_2_A.matrix[1][0] = 4.0;
    src_2_A.matrix[1][1] = 5.0;
    src_2_A.matrix[1][2] = 6.0;
    src_2_A.matrix[2][0] = 7.0;
    src_2_A.matrix[2][1] = 8.0;
    src_2_A.matrix[2][2] = 9.0;

    buffer_errcode_2 = s21_create_matrix_for_minor(&src_2_A, 1, 1, &src_2_res);

    ck_assert_double_eq_tol(src_2_res.matrix[0][0], 1.0, EPS);
    ck_assert_double_eq_tol(src_2_res.matrix[0][1], 3.0, EPS);
    ck_assert_double_eq_tol(src_2_res.matrix[1][0], 7.0, EPS);
    ck_assert_double_eq_tol(src_2_res.matrix[1][1], 9.0, EPS);
    ck_assert_int_eq(correct_errcode_2, buffer_errcode_2);

    s21_remove_matrix(&src_2_A);
    s21_remove_matrix(&src_2_res);

    // Получение матрицы с вычеркнутым рядом и столбцом (2,1) матрицы 3 х 3
    int correct_errcode_3 = OK;
    int buffer_errcode_3 = 42;

    matrix_t src_3_A = {NULL, 0, 0};
    matrix_t src_3_res = {NULL, 0, 0};

    s21_create_matrix(3, 3, &src_3_A);

    src_3_A.matrix[0][0] = 1.0;
    src_3_A.matrix[0][1] = 2.0;
    src_3_A.matrix[0][2] = 3.0;
    src_3_A.matrix[1][0] = 4.0;
    src_3_A.matrix[1][1] = 5.0;
    src_3_A.matrix[1][2] = 6.0;
    src_3_A.matrix[2][0] = 7.0;
    src_3_A.matrix[2][1] = 8.0;
    src_3_A.matrix[2][2] = 9.0;

    buffer_errcode_3 = s21_create_matrix_for_minor(&src_3_A, 2, 1, &src_3_res);

    ck_assert_double_eq_tol(src_3_res.matrix[0][0], 1.0, EPS);
    ck_assert_double_eq_tol(src_3_res.matrix[0][1], 3.0, EPS);
    ck_assert_double_eq_tol(src_3_res.matrix[1][0], 4.0, EPS);
    ck_assert_double_eq_tol(src_3_res.matrix[1][1], 6.0, EPS);
    ck_assert_int_eq(correct_errcode_3, buffer_errcode_3);

    s21_remove_matrix(&src_3_A);
    s21_remove_matrix(&src_3_res);

    // Получение матрицы с вычеркнутым рядом и столбцом (2,2) матрицы 3 х 3
    int correct_errcode_4 = OK;
    int buffer_errcode_4 = 42;

    matrix_t src_4_A = {NULL, 0, 0};
    matrix_t src_4_res = {NULL, 0, 0};

    s21_create_matrix(3, 3, &src_4_A);

    src_4_A.matrix[0][0] = 1.0;
    src_4_A.matrix[0][1] = 2.0;
    src_4_A.matrix[0][2] = 3.0;
    src_4_A.matrix[1][0] = 4.0;
    src_4_A.matrix[1][1] = 5.0;
    src_4_A.matrix[1][2] = 6.0;
    src_4_A.matrix[2][0] = 7.0;
    src_4_A.matrix[2][1] = 8.0;
    src_4_A.matrix[2][2] = 9.0;

    buffer_errcode_4 = s21_create_matrix_for_minor(&src_4_A, 2, 2, &src_4_res);

    ck_assert_double_eq_tol(src_4_res.matrix[0][0], 1.0, EPS);
    ck_assert_double_eq_tol(src_4_res.matrix[0][1], 2.0, EPS);
    ck_assert_double_eq_tol(src_4_res.matrix[1][0], 4.0, EPS);
    ck_assert_double_eq_tol(src_4_res.matrix[1][1], 5.0, EPS);
    ck_assert_int_eq(correct_errcode_4, buffer_errcode_4);

    s21_remove_matrix(&src_4_A);
    s21_remove_matrix(&src_4_res);

    // Получение матрицы с вычеркнутым рядом и столбцом (1,1) матрицы 2 х 2
    int correct_errcode_5 = OK;
    int buffer_errcode_5 = 42;

    matrix_t src_5_A = {NULL, 0, 0};
    matrix_t src_5_res = {NULL, 0, 0};

    s21_create_matrix(2, 2, &src_5_A);

    src_5_A.matrix[0][0] = 1.0;
    src_5_A.matrix[0][1] = 2.0;
    src_5_A.matrix[1][0] = 3.0;
    src_5_A.matrix[1][1] = 4.0;

    buffer_errcode_5 = s21_create_matrix_for_minor(&src_5_A, 1, 1, &src_5_res);

    ck_assert_double_eq_tol(src_5_res.matrix[0][0], 1.0, EPS);
    ck_assert_int_eq(correct_errcode_5, buffer_errcode_5);

    s21_remove_matrix(&src_5_A);
    s21_remove_matrix(&src_5_res);

    // ОШИБКИ
    // Получение матрицы с вычеркнутым рядом и столбцом матрицы 1 х 1
    int correct_errcode_6 = CALC_ERROR;
    int buffer_errcode_6 = 42;

    matrix_t src_6_A = {NULL, 0, 0};
    matrix_t src_6_res = {NULL, 0, 0};

    s21_create_matrix(1, 1, &src_6_A);

    buffer_errcode_6 = s21_create_matrix_for_minor(&src_6_A, 0, 0, &src_6_res);

    ck_assert_int_eq(correct_errcode_6, buffer_errcode_6);

    s21_remove_matrix(&src_6_A);
    s21_remove_matrix(&src_6_res);
}
END_TEST

Suite *lib_suite_create(void) {
    Suite * suite_s21_matrix = suite_create("Suite_of_test_s21_matrix");
    TCase *tc_core_s21_matrix = tcase_create("Core_of_test_s21_matrix");

    tcase_add_test(tc_core_s21_matrix, test_s21_create_matrix);
    tcase_add_test(tc_core_s21_matrix, test_s21_sum_matrix);
    tcase_add_test(tc_core_s21_matrix, test_s21_sub_matrix);
    tcase_add_test(tc_core_s21_matrix, test_s21_eq_matrix);
    tcase_add_test(tc_core_s21_matrix, test_s21_mult_number);
    tcase_add_test(tc_core_s21_matrix, test_s21_mult_matrix);
    tcase_add_test(tc_core_s21_matrix, test_s21_transpose);
    tcase_add_test(tc_core_s21_matrix, test_s21_calc_complements);
    tcase_add_test(tc_core_s21_matrix, test_s21_inverse_matrix);
    tcase_add_test(tc_core_s21_matrix, test_s21_determinant);

    tcase_add_test(tc_core_s21_matrix, test_s21_matrix_for_minor);
    tcase_add_test(tc_core_s21_matrix, test_s21_calc_minor);

    suite_add_tcase(suite_s21_matrix, tc_core_s21_matrix);

    return suite_s21_matrix;
}

int main(void) {
    int failed_counter;
    Suite * suite = lib_suite_create();
    SRunner *suite_runner = srunner_create(suite);

    srunner_run_all(suite_runner, CK_NORMAL);
    failed_counter = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (failed_counter == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
