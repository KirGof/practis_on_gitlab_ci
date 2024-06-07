#include "s21_grep.h"

void alloc(char **data, int size) {
  *data = (char *)calloc(size, sizeof(data));
  if (*data == NULL) {
    exit(EXIT_FAILURE);
  }
}

void re_alloc(char **data, int size) {
  char *new_data = (char *)realloc(*data, size);

  if (new_data == NULL) {
    free(data);
    exit(EXIT_FAILURE);
  } else {
    *data = new_data;
  }
}

char *my_strcpy(char *str1, char *str2) {
  int i = 0;
  while (str2[i] != '\0') {
    str1[i] = str2[i];
    str1[i + 1] = '\0';
    i++;
  }
  return str1;
}

char *my_strcat(char *str1, char *str2) {
  int str1_len = my_strlen(str1) - 1;
  int str2_len = my_strlen(str2);
  for (int i = 0; i < str2_len; i++) {
    str1[str1_len + i] = str2[i];
  }
  return str1;
}

int my_strlen(char *str) {
  int i = 0;
  if (str != NULL) {
    while (str[i] != '\0') {
      i++;
    }
    i++;
  }

  return i;
}
