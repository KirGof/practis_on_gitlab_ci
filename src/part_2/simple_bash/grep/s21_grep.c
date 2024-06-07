#include "s21_grep.h"

int main(int argc, char *argv[]) {
  if (argc < 3) {
    exit(EXIT_FAILURE);
  }
  options opt = {0};
  FILE *fp = NULL;
  char *pattern = NULL;
  parser(argc, argv, &opt, &pattern, fp);
  opt.count_file = argc - optind;
  int error_open_file = 0;
  while (argv[optind] != NULL) {
    my_strcpy(opt.data_name, argv[optind]);
    error_open_file = open_file(argv[optind], &fp, &opt);
    if (error_open_file == 1) {
      error_open_file = 0;
      optind++;
      continue;
    }
    regexik(&pattern, &opt, fp);
    def_c_or_l(&opt);

    opt.count_match = 0;
    opt.count_line = 0;
    optind++;
  }
  if (pattern != NULL) {
    free(pattern);
  }
  return 0;
}

int open_file(char *path, FILE **fp, options *opt) {
  int error = 0;
  *fp = fopen(path, "rt");
  if (*fp == NULL && opt->s_flag == 0) {
    printf(error_file, path);
    error = 1;
  } else if (*fp == NULL) {
    error = 1;
  }

  return error;
}

void read_pattern(FILE *fp, char **data_file, options *opt) {
  char ch;
  char *data = NULL;
  fseek(fp, 0, SEEK_END);
  int size = ftell(fp) + 1;
  fseek(fp, 0, SEEK_SET);
  alloc(&data, size);
  for (int i = 0; (ch = fgetc(fp)) != EOF;) {
    if (ch == '{' || ch == '}' || ch == '|' || ch == '(' || ch == ')') {
      size += 1;
      re_alloc(&data, size);
      data[i] = '\\';
      data[i + 1] = '\0';
      i++;
    }
    if (ch == 13 || ch == 10) {
      if (i == 0 && ch == '\n') {
        continue;
      }
      if (i > 0) {
        if (ch == '\n' && data[i - 1] == '|') {
          continue;
        }
      }
      ch = '|';
    }
    data[i] = ch;
    data[i + 1] = '\0';
    i++;
  }

  if (opt->count_pattern == 0) {
    loading_patten(data_file, data, opt);
  } else {
    loading_patten(data_file, data, opt);
  }
  free(data);
  fclose(fp);
}

void loading_patten(char **pattern, char *data, options *opt) {
  int size = my_strlen(data);
  char *buff = NULL;
  if (opt->type_pattern == 0) {
    alloc(&buff, size);
    for (int i = 0, j = 0; data[i] != '\0'; i++, j++) {
      if (data[i] == '{' || data[i] == '}' || data[i] == '|' ||
          data[i] == '(' || data[i] == ')') {
        size += 1;
        re_alloc(&buff, size);
        buff[j] = '\\';
        buff[j + 1] = '\0';
        j++;
      }
      buff[j] = data[i];
      buff[j + 1] = '\0';
    }
    size = my_strlen(buff);
  }

  if (opt->count_pattern == 0) {
    opt->size_pattern += size;
    alloc(pattern, opt->size_pattern);
    my_strcpy(*pattern, data = (buff == NULL) ? data : buff);
    opt->count_pattern++;
    opt->type_pattern = 0;
  } else {
    size += my_strlen("|");
    opt->size_pattern += size;
    re_alloc(pattern, opt->size_pattern);
    my_strcat(*pattern, "|");
    my_strcat(*pattern, data = (buff == NULL) ? data : buff);
    opt->count_pattern++;
    opt->type_pattern = 0;
  }
  if (buff != NULL) {
    free(buff);
  }
}

void parser(int argc, char *argv[], options *opt, char **pattern, FILE *fp) {
  char ch;
  int error = 0;
  while ((ch = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    if (ch == 'e') {
      opt->e_flag = 1;
    } else if (ch == 'i') {
      opt->i_flag = 1;
    } else if (ch == 'v') {
      opt->v_flag = 1;
    } else if (ch == 'c') {
      opt->c_flag = 1;
    } else if (ch == 'l') {
      opt->l_flag = 1;
    } else if (ch == 'n') {
      opt->n_flag = 1;
    } else if (ch == 'h') {
      opt->h_flag = 1;
    } else if (ch == 's') {
      opt->s_flag = 1;
    } else if (ch == 'f') {
      opt->f_flag = 1;

      if (optarg != NULL) {
        error = open_file(optarg, &fp, opt);
        if (error == 1) {
          exit(EXIT_FAILURE);
        }
        opt->type_pattern = 1;
        read_pattern(fp, pattern, opt);
      }
    } else if (ch == 'o') {
      opt->o_flag = 1;
    }
    if (optarg != NULL && ch != 'f') {
      loading_patten(pattern, optarg, opt);
    }
  }
  if (opt->e_flag == 0 && opt->f_flag == 0) {
    loading_patten(pattern, argv[optind], opt);
    optind++;
  }
}

void def_c_or_l(options *opt) {
  if (opt->c_flag == 1 && opt->l_flag == 0) {
    if (opt->count_file > 1 && opt->h_flag == 0) {
      printf("%s:", opt->data_name);
    }

    printf("%d\n", opt->count_match);
  }
  if (opt->l_flag == 1 && opt->count_match > 0) {
    printf("%s\n", opt->data_name);
  }
}

void printing_flag(options *opt, char *data_file) {
  if (opt->c_flag == 0 && opt->l_flag == 0) {
    if (opt->count_file > 1 && opt->h_flag == 0 && opt->o_flag == 0) {
      printf("%s:", opt->data_name);
    } else if (opt->count_file > 1 && opt->h_flag == 0 && opt->o_flag == 1 &&
               opt->v_flag == 0) {
      printf("%s:", opt->data_name);
    }

    if (opt->n_flag == 1 && opt->o_flag == 0) {
      printf("%d:", opt->count_line);
    }
    if (opt->o_flag == 0) {
      printf("%s\n", data_file);
    }
  }
}

void n_flag_for_o_flag(char *buff, options *opt, int i, int z) {
  int j = 0;
  int a = strlen(buff);
  while (j < i) {
    if (buff[j] == '\n' && opt->check_buff_on_o != a) {
      opt->count_line++;
    }
    j++;
  }
  if ((i - z) != 1 && opt->check == 0) {
    printf("%d:", opt->count_line);
    opt->check = 1;
  } else if ((i - z) == 1) {
    printf("%d:", opt->count_line);
  }
}

void regexik(char **pattern, options *opt, FILE *fp) {
  regex_t regex;
  regmatch_t pmatch[100];
  char *data_file = NULL, ch;
  fseek(fp, 0, SEEK_END);
  int size = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  alloc(&data_file, size);
  int cflags = REG_EXTENDED, check_for_match = 0;
  if (opt->i_flag) {
    cflags = REG_ICASE | REG_EXTENDED;
  }
  // if ((*pattern)[strlen(*pattern) - 1] == '|')
  // {
  //     (*pattern)[strlen(*pattern) - 1] = '\0';
  // }

  while (((ch = fgetc(fp)) != EOF)) {
    int i = 0;
    for (data_file[i] = '\0'; ch != EOF && ch != '\n'; ch = fgetc(fp)) {
      data_file[i] = ch;
      data_file[i + 1] = '\0';
      i++;
    }
    char *buff = data_file;
    // printf("%s\n", *pattern);
    if (regcomp(&regex, *pattern, cflags) == 0) {
      opt->count_line++;
      if (opt->o_flag == 1 && opt->v_flag == 0) {
        while ((regexec(&regex, buff, 1, pmatch, 0) == 0) &&
               (pmatch[0].rm_so != pmatch[0].rm_eo)) {
          printing_flag(opt, buff);
          regoksik(pmatch, opt, buff);
          buff += pmatch[0].rm_eo;
          check_for_match = 1;
        }
        if (check_for_match == 1) {
          opt->count_match++;
          check_for_match = 0;
        }
      } else {
        if (regexec(&regex, buff, 0, NULL, 0) == opt->v_flag) {
          opt->count_match++;
          printing_flag(opt, buff);
        }
      }

      regfree(&regex);
    } else {
      // printf("not compil");
    }
  }
  free(data_file);
  fclose(fp);
}

void regoksik(regmatch_t pmatch[100], options *opt, char *buff) {
  if (opt->l_flag == 0 && opt->c_flag == 0 && opt->v_flag == 0) {
    for (int i = pmatch[0].rm_so; i < pmatch[0].rm_eo; i++) {
      if (opt->n_flag) {
        n_flag_for_o_flag(buff, opt, pmatch[0].rm_eo, pmatch[0].rm_so);
      }

      printf("%c", buff[i]);
    }
    printf("\n");
    opt->check = 0;
  }
}
