#!/bin/bash

	echo test_GNU_number-nonblank
	./s21_cat --number-nonblank 1.txt > my_file.txt
	cat --number-nonblank 1.txt > cat_file.txt
	diff -s my_file.txt cat_file.txt
	rm -r  my_file.txt cat_file.txt

	echo test_GNU_number
	./s21_cat --number 1.txt > my_file.txt
	cat --number 1.txt > cat_file.txt
	diff -s my_file.txt cat_file.txt
	rm -r  my_file.txt cat_file.txt

	echo test_GNU_squeeze-blank
	./s21_cat --squeeze-blank 1.txt > my_file.txt
	cat --squeeze-blank 1.txt > cat_file.txt
	diff -s my_file.txt cat_file.txt
	rm -r  my_file.txt cat_file.txt


	echo test_n
	./s21_cat -n 1.txt > my_file.txt
	cat -n 1.txt > cat_file.txt
	diff -s my_file.txt cat_file.txt
	rm -r  my_file.txt cat_file.txt

	echo test_b
	./s21_cat -b 1.txt > my_file.txt
	cat -b 1.txt > cat_file.txt
	diff -s my_file.txt cat_file.txt
	rm -r  my_file.txt cat_file.txt

	echo test_t
	./s21_cat -t 1.txt > my_file.txt
	cat -t 1.txt > cat_file.txt
	diff -s my_file.txt cat_file.txt
	rm -r  my_file.txt cat_file.txt

	echo test_te
	./s21_cat -te 1.txt > my_file.txt
	cat -te 1.txt > cat_file.txt
	diff -s my_file.txt cat_file.txt
	rm -r  my_file.txt cat_file.txt

	echo test_e
	./s21_cat -e 1.txt > my_file.txt
	cat -e 1.txt > cat_file.txt
	diff -s my_file.txt cat_file.txt
	rm -r  my_file.txt cat_file.txt

	echo test_es
	./s21_cat -e -s 1.txt > my_file.txt
	cat -e -s 1.txt > cat_file.txt
	diff -s my_file.txt cat_file.txt
	rm -r  my_file.txt cat_file.txt

		echo test_ns
	./s21_cat -n -s 1.txt > my_file.txt
	cat -n -s 1.txt > cat_file.txt
	diff -s my_file.txt cat_file.txt
	rm -r  my_file.txt cat_file.txt

	echo test_bs	
	./s21_cat -b -s 1.txt > my_file.txt
	cat -b -s 1.txt > cat_file.txt
	diff -s my_file.txt cat_file.txt
	rm -r  my_file.txt cat_file.txt

	echo test_bsv
	./s21_cat -b -sv 1.txt > my_file.txt
	cat -b -sv 1.txt > cat_file.txt
	diff -s my_file.txt cat_file.txt
	rm -r  my_file.txt cat_file.txt

	echo test_nb
	./s21_cat -b -n 1.txt > my_file.txt
	cat -b -n 1.txt > cat_file.txt
	diff -s my_file.txt cat_file.txt
	rm -r  my_file.txt cat_file.txt

	echo test_v
	./s21_cat -v 1.txt > my_file.txt
	cat -v 1.txt > cat_file.txt
	diff -s my_file.txt cat_file.txt
	rm -r  my_file.txt cat_file.txt

	echo test_nvesb
	./s21_cat -nvesb  1.txt > my_file.txt
	cat -nvesb 1.txt > cat_file.txt
	diff -s my_file.txt cat_file.txt
	rm -r  my_file.txt cat_file.txt


