CC = gcc -g
TEST_DIR = ./tests
TEST = ./tests/test_main.c
BUILD_DIR = obj
BUILD_TEST_DIR = obj_test

ifeq ($(shell uname -s), Linux)
	SRC := $(shell find ./ -name "s21_*.c" | sed -e 's/\.\///')
else
	SRC := $(wildcard s21_*.c | sed -e 's/\.\///')
endif
OBJS := $(SRC:%.c=$(BUILD_DIR)/%.o)

ifeq ($(shell uname -s), Linux)
	TEST_SRC := $(shell find $(TEST_DIR) -name "*.c" | sed -e 's/\.\///')
else
	TEST_SRC := $(wildcard ./tests/*.c | sed -e 's/\.\///')
endif
TEST_OBJS := $(TEST_SRC:%.c=$(BUILD_TEST_DIR)/%.o)

FLAGS = -std=c11 -Wall -Werror -Wextra
TEST_FLAGS = -lcheck -lpthread -pthread -lm

ifeq ($(shell uname -s),Linux)
	TEST_FLAGS += -lsubunit -lgcov -lrt
endif

all: clean s21_matrix.a

s21_matrix.a: $(OBJS) s21_matrix.h
	@mkdir -p $(BUILD_DIR)
	ar rc s21_matrix.a $(OBJS)
	ranlib s21_matrix.a

test: s21_matrix.a $(TEST_OBJS)
	$(CC) $(TEST_OBJS) s21_matrix.a -o ./tests/test.out $(TEST_FLAGS)
	./tests/test.out

gcov_report: clean
	$(CC) $(FLAGS) $(TEST_SRC) $(SRC) --coverage -o test $(TEST_FLAGS)
	./test
	gcovr -r . -s --html --html-details -f s21_matrix.c -o ./coverage_report.html

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

$(BUILD_TEST_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $^ -o $@

$(GCOV_OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

leaks:
ifeq ($(shell uname -s), Linux)
	valgrind --leak-check=yes  ./tests/test.out
else
	leaks --atExit -- ./test.out
endif

style_check: 
	clang-format -style=Google -n *.c *.h
	clang-format -style=Google -n ./tests/*.c ./tests/*.h

style_fix: 
	clang-format -style=Google -i *.c *.h
	clang-format -style=Google -i ./tests/*.c ./tests/*.h

rebuild: clean all

clean:
	rm -f *.gcda *.gcov *.o *.a *.gcno test.out test s21_matrix.info
	rm -rf $(BUILD_DIR)
	rm -rf $(BUILD_TEST_DIR)
	rm -rf $(GCOV_OBJ_DIR)
	rm -f ./tests/test.out
	rm -f ./coverage_report.*
	rm -rf ./gcov_report