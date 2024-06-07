#ifndef MAIN
#define MAIN

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define error_file "grep: %s: No such file or directory\n"

typedef struct {
  int e_flag;
  int i_flag;
  int v_flag;
  int c_flag;
  int l_flag;
  int n_flag;
  int h_flag;
  int s_flag;
  int f_flag;
  int o_flag;
  int count_pattern;
  int count_file;
  int count_line;
  int count_match;
  int check_buff_on_o;
  char data_name[256];
  int type_pattern;
  int size_pattern;
  int check;

} options;

void alloc(char **data, int size);
void re_alloc(char **data, int size);
int open_file(char *path, FILE **fp, options *opt);
void read_pattern(FILE *fp, char **data_file, options *opt);
void parser(int argc, char *argv[], options *opt, char **pattern, FILE *fp);
void loading_patten(char **pattern, char *data, options *opt);
void read_data_file(FILE *fp, char **data_file, options *opt);
void regexik(char **pattern, options *opt, FILE *fp);
void def_c_or_l(options *opt);
void printing_flag(options *opt, char *data_file);
void regoksik(regmatch_t pmatch[100], options *opt, char *buff);
void n_flag_for_o_flag(char *buff, options *opt, int i, int z);

char *my_strcpy(char *str1, char *str2);
char *my_strcat(char *str1, char *str2);
int my_strlen(char *str);

#endif  // MAIN