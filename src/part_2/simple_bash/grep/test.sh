#!/bin/bash

echo test_empty_flag
./s21_grep e ./s21_grep.c > s21_grep.txt
grep e ./s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_-efiv
./s21_grep -e \) -e \| -f 1.txt 2.txt -i s21_grep.c s21_grep.h Makefile > s21_grep.txt
grep -e \) -e \| -f 1.txt 2.txt -i s21_grep.c s21_grep.h Makefile > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_eo
./s21_grep -e for -o ./s21_grep.c > s21_grep.txt
grep -e for -o ./s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_iv
./s21_grep -i e -v ./s21_grep.c > s21_grep.txt
grep -i e -v ./s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_vc
./s21_grep -vc flag ./s21_grep.c > s21_grep.txt
grep -vc flag ./s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_c
./s21_grep -c e ./s21_grep.c > s21_grep.txt
grep -c e ./s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_l
./s21_grep -l e ./s21_grep.c ./s21_grep.h ./s21_grep.c > s21_grep.txt
grep -l e ./s21_grep.c ./s21_grep.h ./s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_n
./s21_grep -n e ./s21_grep.c > s21_grep.txt
grep -n e ./s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_h
./s21_grep -h e ./s21_grep.c > s21_grep.txt
grep -h e ./s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_s
./s21_grep -s e ./s21_grep.c > s21_grep.txt
grep -s e ./s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_f
./s21_grep -f 1.txt ./s21_grep.c > s21_grep.txt
grep -f 1.txt ./s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_o
./s21_grep -o pri ./s21_grep.c > s21_grep.txt
grep -o pri ./s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_in
./s21_grep -in log ./s21_grep.c > s21_grep.txt
grep -in log ./s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_lc
./s21_grep -lc int ./s21_grep.c > s21_grep.txt
grep -lc int ./s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_iv
./s21_grep -iv log ./s21_grep.c > s21_grep.txt
grep -iv log ./s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_iv
./s21_grep -iv int s21_grep.c > s21_grep.txt
grep -iv int s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_evo
./s21_grep -e for -e ^int -ov s21_grep.c s21_grep.h Makefile > s21_grep.txt
grep -e for -e ^int -ov s21_grep.c s21_grep.h Makefile > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

echo test_oe
./s21_grep -oe \\[a-c] s21_grep.c  > s21_grep.txt
grep -oe \\[a-c] s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
