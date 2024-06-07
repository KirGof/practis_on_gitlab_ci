#ifndef S21_CAT_
#define S21_CAT_

#include <stdio.h>
#include <string.h>
#define error_flag \
  "cat: invalid option -- '%c'\nTry 'cat --help' for more information.\n"
#define error_file "cat: %s: No such file or directory\n"

int what_flag(int argc, char *argv[], int *where_file, int *b_flag, int *e_flag,
              int *n_flag, int *s_flag, int *t_flag, int *v_flag);
int make_cat(int argc, char *argv[], int where_file, int *b_flag, int e_flag,
             int *n_flag, int s_flag, int t_flag, int v_flag);
void def_n(int **n_flag, char temp);
void def_b(int **b_flag, char ch, char temp);
void def_e();
void def_s(char ch, char temp, int *empty_line);
void def_t(char *ch);
void def_v(char *ch);

int parse(char *argv[], int i, int j, int **b_flag, int **e_flag, int **n_flag,
          int **s_flag, int **t_flag, int **v_flag);

#endif  // S21_CAT_
