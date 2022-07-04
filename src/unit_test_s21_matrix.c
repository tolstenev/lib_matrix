/*
 * Copyright (с) 2022 Student of School 21:
 * Yonn Argelia
 *
 * yonnarge@student.21-school.ru
 */

#include <check.h>
#include <string.h>
#include <limits.h>
#include "s21_matrix.h"


START_TEST(test_s21_create_matrix) {
    // Создание адекватной матрицы
    int correct_errcode_1 = OK;
    int buffer_errcode_1 = 42;
    int src_1_rows = 3;
    int src_1_cols = 3;
    matrix_t src_1 = {NULL, 0, 0};

    buffer_errcode_1 = s21_create_matrix(src_1_rows, src_1_cols, &src_1);

    ck_assert_int_eq(src_1_rows, src_1.rows);
    ck_assert_int_eq(src_1_cols, src_1.columns);
    ck_assert_ptr_nonnull(src_1.matrix);
    ck_assert_int_eq(correct_errcode_1, buffer_errcode_1);

    s21_remove_matrix(&src_1);

    // ОШИБКИ
    // Проверка на некорректные значения количства рядов и колонок
    int correct_result_of_error = INCORRECT_MATRIX;
    int buffer_result_for_error = 42;
    int src_2_rows = -21;
    int src_2_cols = -21;
    matrix_t src_2 = {NULL, 0, 0};

    buffer_result_for_error = s21_create_matrix(src_2_rows, src_2_cols, &src_2);

    ck_assert_int_eq(correct_result_of_error, buffer_result_for_error);

    s21_remove_matrix(&src_2);
}
END_TEST

START_TEST(test_s21_remove_matrix) {
}
END_TEST

START_TEST(test_s21_eq_matrix) {
}
END_TEST

START_TEST(test_s21_sum_matrix) {
}
END_TEST

START_TEST(test_s21_sub_matrix) {
}
END_TEST

START_TEST(test_s21_mult_number) {
}
END_TEST

START_TEST(test_s21_mult_matrix) {
}
END_TEST

START_TEST(test_s21_transpose) {
}
END_TEST

START_TEST(test_s21_calc_complements) {
}
END_TEST



Suite *lib_suite_create(void) {
    Suite *suite_s21_matrix = suite_create("Suite_of_test_s21_matrix");
    TCase *tc_core_s21_matrix = tcase_create("Core_of_test_s21_matrix");

    tcase_add_test(tc_core_s21_matrix, test_s21_create_matrix);
    tcase_add_test(tc_core_s21_matrix, test_s21_remove_matrix);
    tcase_add_test(tc_core_s21_matrix, test_s21_eq_matrix);
    tcase_add_test(tc_core_s21_matrix, test_s21_sum_matrix);
    tcase_add_test(tc_core_s21_matrix, test_s21_sub_matrix);
    tcase_add_test(tc_core_s21_matrix, test_s21_mult_number);
    tcase_add_test(tc_core_s21_matrix, test_s21_mult_matrix);
    tcase_add_test(tc_core_s21_matrix, test_s21_transpose);
    tcase_add_test(tc_core_s21_matrix, test_s21_calc_complements);

    suite_add_tcase(suite_s21_matrix, tc_core_s21_matrix);

    return suite_s21_matrix;
}

int main(void) {
    int failed_counter;
    Suite *suite = lib_suite_create();
    SRunner *suite_runner = srunner_create(suite);

    srunner_run_all(suite_runner, CK_NORMAL);
    failed_counter = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (failed_counter == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
