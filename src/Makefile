#
# Copyright 2023 Gleb Tolstenev
# tolstenev.gleb@mail.ru
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

#
# Makefile for s21_matrix.a
#
# Make targets:
#   - s21_matrix.a:		create the static library
#   - test:				run unit test of library and show results
#   - gcov_report:		run unit test of library and generate gcov report
#   - check:     		check source files by 'cppcheck', 'cpplint', and
#						looking for memory leaks by 'leaks'
#   - check_valgrind:	looking for memory leaks by 'valgrind'
#   - clean:			remove generated files without s21_matrix.a
#   - fclean:			remove all generated files
#   - re:				remove all generated files and recompile library
#

NAME		:= s21_matrix.a
HEADER		:= s21_matrix.h

CC			:= gcc
CFLAGS		:= -std=c11 -pedantic -Wall -Werror -Wextra
SRCS		:= s21_create_matrix.c \
			   s21_remove_matrix.c \
			   s21_eq_matrix.c \
			   s21_sum_matrix.c \
			   s21_sub_matrix.c \
			   s21_mult_number.c \
			   s21_mult_matrix.c \
			   s21_transpose.c \
			   s21_determinant.c \
			   s21_calc_complements.c \
			   s21_inverse_matrix.c \
			   s21_support_function.c
OBJS		:= $(SRCS:.c=.o)

TEST		:= unit_test
SRC_TEST	:= unit_test_s21_matrix.c
REPORT		:= GcovReport
GCOVFLAGS	:= -fprofile-arcs -ftest-coverage
CHECK_FLAGS	:= -lcheck


all: s21_matrix.a

info:
		@echo "Available make targets:"
		@echo "  s21_matrix.a:    create the static library"
		@echo "  test:            run unit test of library and show results"
		@echo "  gcov_report:     run unit test of library and generate gcov report"
		@echo "  check:           check source files by 'cppcheck', 'cpplint', and looking for memory leaks by 'leaks'"
		@echo "  check_valgrind:  looking for memory leaks by 'valgrind'"
		@echo "  open:            open coverage gcov report in browser"
		@echo "  clean:           remove generated files without s21_matrix.a"
		@echo "  fclean:          remove all generated files"
		@echo "  re:              remove all generated files and recompile library"

s21_matrix.a: $(OBJS)
		@clear
		ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME)
		@clear
		$(CC) $< $(SRC_TEST) $(NAME) $(CHECK_FLAGS) -o $(TEST)
		./$(TEST)

gcov_report:
		@clear
		$(CC) $(GCOVFLAGS) $(SRC_TEST) $(SRCS) $(CHECK_FLAGS) -o $(REPORT)
		./$(REPORT)
		lcov -t "$(REPORT)" -o $(REPORT).info -c -d .
		genhtml -o report $(REPORT).info
		rm -rf ./*.gcno ./*.gcda ./$(REPORT).*
		@echo Code coverage report generated. To view the report via web-browser, enter the command \"open ./report/index.html\"

check: $(NAME)
		@clear
		@echo ---------------------CPPCHECK---------------------
		cppcheck --enable=all --suppress=missingIncludeSystem . $(HEADER) $(SRCS)
		@echo ---------------------CPPLINT----------------------
		cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
		python3 ../materials/linters/cpplint.py --extension=c $(SRCS) $(SRC_TEST) $(HEADER)
		rm CPPLINT.cfg
		@echo -------------------MEMORY_LEAKS-------------------
		$(CC) -g $(SRC_TEST) $(NAME) $(CHECK_FLAGS) -o $(TEST)
		CK_FORK=no leaks --atExit -- ./$(TEST)

open: gcov_report
		open ./report/index.html

check_valgrind: $(NAME)
		@clear
		@echo -------------------MEMORY_LEAKS-------------------
		$(CC) -g $(SRC_TEST) $(NAME) $(CHECK_FLAGS) -o $(TEST)
		CK_FORK=no valgrind --leak-check=full -s ./$(TEST)

clean:
		rm -rf $(OBJS) ./GcovReport ./*.gcov ./*.gcno ./*.gcda ./report ./*.info ./*.dSYM ./$(TEST) $(PRINT_TEST) ./a.out
		@clear

fclean: clean
		rm -rf $(NAME)
		@clear

re:
		$(MAKE) fclean
		$(MAKE) $(NAME)

.PHONY: all test check check_valgrind clean fclean re
