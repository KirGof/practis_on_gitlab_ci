
FLAGS = -g -Wall -Wextra -Werror -std=c11

all: s21_grep

s21_grep: s21_grep.c
	gcc $(FLAGS) s21_grep.c some_foo.c -o s21_grep
		

rebuild:
	make clean
	make all

clean:
	rm -f *.o



