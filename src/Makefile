CC = gcc
CFFLAG = -Wall -Werror -Wextra -std=c11
CDEBUG = -g -Wall -Werror -std=c11
FLAG = -lcheck -lm -lsubunit
CLEAN_FILES = tpr_*.o test *.a *.out *.gcno *.info *.gcda html
CLANG = clang-format -style=Google -n *.c *.h

SRC = ./tpr_decimal/other/tpr_other.c ./tpr_decimal/arifmetic/tpr_add.c ./tpr_decimal/arifmetic/tpr_div.c ./tpr_decimal/arifmetic/tpr_mul.c ./tpr_decimal/arifmetic/tpr_sub.c ./tpr_decimal/help/tpr_help.c ./tpr_decimal/comparison/tpr_comparison.c ./tpr_decimal/convertor/tpr_convertor.c 
SRCTEST = ./tpr_test/tpr_test.c
OBJ = $(SRC:.c=.o)
LIB = tpr_decimal.a

ALL_C_H_FILES = $(shell find . -type f | grep "\.(c|h)$$" -E)

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $^

test: ./tpr_test/tpr_test.o $(LIB)
	$(CC) $(CFFLAG)  ./tpr_test/tpr_test.o $(LIB) -o test $(FLAG)
	./test

testVerter: ./tpr_test/tpr_test_verter.o $(LIB)
	$(CC) $(CFFLAG)  ./tpr_test/tpr_test_verter.o $(LIB) -o test $(FLAG) -g
	./test

%.o: %.c
	$(CC) $(CFFLAG) -c $< -o $@

rebuild: clean all

gcov_report: $(LIB)
	$(CC) $(CFFLAG) --coverage $(SRC) $(SRCTEST) $(LIB) -o gcov.out $(FLAG)
	./gcov.out
	lcov -t "tpr_TEST" -o test.info -c -d . #--exclude /media/sf_21/Main21/C5_tpr_decimal-1/src/tpr_test
	genhtml test.info -o html
	open html/index.html

clean:
	rm -rf $(CLEAN_FILES)
	find . -type f -name "*.o" -exec rm -f {} +

clang_check:
	find . -name "*.h" -exec clang-format -style=Google -n {} +
	find . -name "*.c" -exec clang-format -style=Google -n {} +

clangi:
	find . -name "*.h" -exec clang-format -style=Google -i {} +
	find . -name "*.c" -exec clang-format -style=Google -i {} +		

valgrind:
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test

valgrind_min_output:
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test 2>&1 | grep "ERROR SUMMARY"

tpr_valgrind:
	valgrind --tool=memcheck --leak-check=yes ./test 2>&1 | grep "ERROR SUMMARY"

