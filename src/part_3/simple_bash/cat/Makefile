
FLAGS = -g -Wall -Wextra -Werror -std=c11

all: s21_cat

s21_cat: s21_cat.h s21_cat.c
	gcc $(FLAGS) s21_cat.c -o s21_cat


rebuild:
	make clean
	make all

clean:
	rm -f *.o
	
