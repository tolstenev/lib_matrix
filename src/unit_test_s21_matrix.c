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

START_TEST(test_s21_create_matrix) {

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