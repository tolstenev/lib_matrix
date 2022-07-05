#
# Copyright (с) 2022 Student of School 21:
# Yonn Argelia
#
# yonnarge@student.21-school.ru
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
SRCS		:= s21_support_function.c \
			   s21_create_matrix.c \
			   s21_remove_matrix.c \
			   s21_eq_matrix.c \
			   s21_sum_matrix.c \
			   s21_sub_matrix.c \
			   s21_mult_number.c \
			   s21_mult_matrix.c
OBJS		:= $(SRCS:.c=.o)

PRINT_TEST	:= print_matrix

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
		@echo "  clean:           remove generated files without s21_matrix.a"
		@echo "  fclean:          remove all generated files"
		@echo "  re:              remove all generated files and recompile library"

s21_matrix.a: $(OBJS)
		@clear
		ar rcs $(NAME) $(OBJS)

%.o: %.c
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

t: $(NAME)
		@clear
		@$(CC) $< $(PRINT_TEST).c $(NAME) -o $(PRINT_TEST)
		@./$(PRINT_TEST)