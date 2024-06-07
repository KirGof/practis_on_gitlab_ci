#include "s21_cat.h"

int main(int argc, char *argv[]) {
  int error = 0;
  if (argc > 1) {
    int b_flag = 0, e_flag = 0, n_flag = 0, s_flag = 0, t_flag = 0, v_flag = 0,
        where_file = 1;
    error = what_flag(argc, argv, &where_file, &b_flag, &e_flag, &n_flag,
                      &s_flag, &t_flag, &v_flag);
    if (error == 0) {
      error = make_cat(argc, argv, where_file, &b_flag, e_flag, &n_flag, s_flag,
                       t_flag, v_flag);
    }
  }
  return error;
}

int what_flag(int argc, char *argv[], int *where_file, int *b_flag, int *e_flag,
              int *n_flag, int *s_flag, int *t_flag, int *v_flag) {
  int error = 0, j = 1, i = 1;
  while (i < argc) {
    if (argv[i][0] == '-') {
      while (argv[i][j] != '\0' && error != 1) {
        error = parse(argv, i, j, &b_flag, &e_flag, &n_flag, &s_flag, &t_flag,
                      &v_flag);
        j++;
      }
      j = 1;
      *where_file = *(where_file) + 1;
    }
    i++;
  }
  return error;
}

int make_cat(int argc, char *argv[], int where_file, int *b_flag, int e_flag,
             int *n_flag, int s_flag, int t_flag, int v_flag) {
  int error = 0;
  char temp;

  char ch;
  int empty_line = 0;
  while (where_file < argc) {
    FILE *fp;
    if ((fp = fopen(argv[where_file], "r")) == NULL) {
      printf(error_file, argv[where_file]);
      error = 1;
    } else {
      while ((ch = fgetc(fp)) != EOF) {
        if (s_flag) {
          def_s(ch, temp, &empty_line);
        }
        if (*n_flag && *b_flag == 0 && empty_line < 2) {
          def_n(&n_flag, temp);
        }
        if (*b_flag && empty_line < 2) {
          def_b(&b_flag, ch, temp);
        }
        if (e_flag && ch == '\n' && empty_line < 2) {
          def_e();
        }
        if (t_flag) {
          def_t(&ch);
        }
        if (v_flag) {
          def_v(&ch);
        }
        if (empty_line < 2) {
          printf("%c", ch);
        }
        temp = ch;
      }
      fclose(fp);
    }
    where_file++;
  }
  return error;
}

void def_n(int **n_flag, char temp) {
  if (**n_flag == 1 || temp == '\n') {
    printf("%6d\t", **n_flag);
    **(n_flag) = **(n_flag) + 1;
  }
}

void def_b(int **b_flag, char ch, char temp) {
  if ((**b_flag == 1 && ch != '\n') || (temp == '\n' && ch != '\n')) {
    printf("%6d\t", **b_flag);
    **(b_flag) = **(b_flag) + 1;
  }
}

void def_e() { printf("$"); }

void def_s(char ch, char temp, int *empty_line) {
  if (ch == '\n' && temp == '\n') {
    *(empty_line) = *(empty_line) + 1;
  } else if (ch != '\n') {
    *empty_line = 0;
  }
}

void def_t(char *ch) {
  if (*ch == '\t') {
    printf("^");
    *ch = 'I';
  }
}

void def_v(char *ch) {
  if (*ch < 32 && *ch != 9 && *ch != 10) {
    printf("^");
    *ch += 64;
  }
  if (*ch == 127) {
    printf("^");
    *ch = '?';
  }
}

int parse(char *argv[], int i, int j, int **b_flag, int **e_flag, int **n_flag,
          int **s_flag, int **t_flag, int **v_flag) {
  int error = 0;
  if (!strcmp(argv[i], "--number-nonblank")) {
    **(b_flag) = 1;
  } else if (!strcmp(argv[i], "--number")) {
    if (**(b_flag) == 1) {
      **(n_flag) = 0;
    } else {
      **(n_flag) = 1;
    }
  } else if (!strcmp(argv[i], "--squeeze-blank")) {
    **(s_flag) = 1;
  } else {
    if (argv[i][j] == 'b') {
      **(b_flag) = 1;
    } else if (argv[i][j] == 'e') {
      **(e_flag) = 1;
      **(v_flag) = 1;
    } else if (argv[i][j] == 'n') {
      if (**(b_flag) == 1) {
        **(n_flag) = 0;
      } else {
        **(n_flag) = 1;
      }
    } else if (argv[i][j] == 's') {
      **(s_flag) = 1;
    } else if (argv[i][j] == 't') {
      **(t_flag) = 1;
      **(v_flag) = 1;
    } else if (argv[i][j] == 'v') {
      **(v_flag) = 1;
    } else if (argv[i][j] == 'E') {
      **(e_flag) = 1;
    } else if (argv[i][j] == 'T') {
      **(t_flag) = 1;
    }

    else {
      error = 1;
      printf(error_flag, argv[i][j]);
    }
  }
  return error;
}