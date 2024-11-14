# GCC = gcc
# CFLAGS =  -Wall -Werror -Wextra -std=c11 
# LDFLAGS = -Wall -Werror -Wextra -std=c11
# SOURCE = $(filter-out ./test/test_s21_string.c, $(wildcard s21_*.c))
# HEADER = $(wildcard s21_*.h)
# OBJECTS = $(patsubst %.c,%.o, ${SOURCE})
# TESTS_SOURCE = ./test/test_s21_string.c
# UNAME_S := $(shell uname -s)
# UNAME_O := $(shell uname -o)
# BIN = s21_string_test

# GCOV = gcovr
# GCOV_FLAGS = -fprofile-arcs -ftest-coverage --coverage
# REPORT_FILE = report.html
# OPEN_REPORT = open $(REPORT_FILE)

# ifeq ($(UNAME_S),Linux)
# 	OPEN_CMD = xdg-open
# 	ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread 
# 	BREW = .
# 	OPEN_REPORT = firefox $(REPORT_FILE)
# endif
# ifeq ($(UNAME_S),Darwin)
# 	OPEN_CMD = open
# 	ADD_LIB =
# 	BREW := ${HOME}/homebrew
# endif

# ifeq ($(UNAME_O), Linux)
# 	ADD_LIB += -DALPINE
# endif

# PATH := $(BREW)/bin:$(PATH)

# all: s21_string.a

# s21_string.a: clean ${SOURCE} 
# 	$(CC) -c $(CFLAGS) -lm $(ADD_LIB) $(SOURCE)
# 	ar rc $@ $(OBJECTS)
# 	ranlib $@
# 	cp $@ lib$@
# 	-rm -rf *.o

# test: clean s21_string.a 
# 	rm -f *.o
# 	$(CC) $(CFLAGS) -c tests/*.c  $(ADD_LIB)
# 	mv *.o tests/
# 	$(CC) $(CFLAGS) *.c tests/*.o -o tests/all_tests.o $(ADD_LIB) -fprofile-arcs -ftest-coverage
# 	./tests/all_tests.o


# gcov_report: test
# 	mkdir -p report_gcovr
# 	gcovr --html-details -o report_gcovr/report.html
# 	rm -rf *.gcno *.gcda *.gcov *.info
# 	$(OPEN_CMD) report_gcovr/report.html

# style: clean
# 	clang-format -i -style='{BasedOnStyle: Google}' *.c  *.h */*.c

# clean:
# 	-rm -rf *.o && rm -rf *.gcno
# 	-rm -rf *.a && rm -rf *.gcda
# 	-rm -rf *.info && rm -rf *.gcov
# 	-rm -rf s21_test
# 	-rm -rf $(BIN)
# 	-rm -rf *.css *.html
# 	rm -rf tests/*.o tests/*.gcno tests/*.gcda tests/*.gcov tests/*.info


CC = gcc
CFLAGS =  -Wall -Werror -Wextra -std=c11 
LDFLAGS = -Wall -Werror -Wextra -std=c11
SOURCE = $(filter-out ./test/test_s21_string.c, $(wildcard s21_*.c))
HEADER = $(wildcard s21_*.h)
OBJECTS = $(patsubst %.c,%.o, ${SOURCE})
TESTS_SOURCE = ./test/test_s21_string.c

UNAME:=$(shell uname -s)
ifeq ($(UNAME), Linux)
 ADD_LIB = -lcheck -lsubunit -lm -lrt -lpthread 
 CFLAGS += -lsubunit
 TEST_FLAGS = -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
	OPENER = sensible-browser
	endif
ifeq ($(UNAME), Darwin)
 TEST_FLAGS = $(shell pkg-config --cflags --libs check)
 ADD_LIB =
 OPENER = open
endif

PATH := $(BREW)/bin:$(PATH)

all: s21_string.a

s21_string.a: clean ${SOURCE} 
	$(CC) -c $(CFLAGS) $(ADD_LIB) $(SOURCE)
	ar rc $@ $(OBJECTS)
	ranlib $@
	cp $@ lib$@
	-rm -rf *.o

test: clean s21_string.a 
	rm -f *.o
	$(CC) $(CFLAGS) -c tests/*.c  $(ADD_LIB)
	mv *.o tests/
	$(CC) $(CFLAGS) *.c tests/*.o -o tests/all_tests.o -fprofile-arcs -lcheck -ftest-coverage $(ADD_LIB)
	./tests/all_tests.o


test-coverage: clean s21_string.a
	$(CC) $(CFLAGS) -c tests/*.c $(ADD_LIB)
	mv *.o tests/
	$(CC) $(CFLAGS) *.c tests/*.o -o tests/all_tests.o -fprofile-arcs -lcheck -ftest-coverage $(ADD_LIB)
	./tests/all_tests.o

gcov_report: test-coverage
	mkdir -p gcov_report
	gcovr --html-details -o gcov_report/index.html
	rm -rf *.gcno *.gcda *.gcov *.info

style: clean
	clang-format -i -style='{BasedOnStyle: Google}' *.c  *.h */*.c

clean:
	-rm -rf *.o && rm -rf *.gcno
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf s21_test
	-rm -rf $(BIN)
	-rm -rf *.css *.html
	-rm -rf tests/*.o tests/*.gcno tests/*.gcda tests/*.gcov tests/*.info
	-rm -rf gcov_report
