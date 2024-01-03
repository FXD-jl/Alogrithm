#include "writeShell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSH_RL_BUFSIZE 1024

// 自制getline()函数
/* char *lsh_read_line(void) {
  int bufsize = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;

  if (!buffer) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }
  while (1) {
    c = getchar();
    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else { buffer[position] = c;
    }
    position++;
    if (position >= bufsize) {
      bufsize += LSH_RL_BUFSIZE;
      buffer = realloc(buffer, bufsize * sizeof(char));
      if (!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
} */

char *lsh_read_line(void) {
  char *buffer;
  size_t bufsize = 0;
  if (getline(&buffer, &bufsize, stdin) == -1) {
    if (feof(stdin)) {
      exit(EXIT_SUCCESS);
    } else {
      perror("readline:");
      exit(EXIT_FAILURE);
    }
  }
  return buffer;
}

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
char **lsh_split_line(char *line) {
  int bufsize = LSH_TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char *));
  char *token;

  if (!tokens) {
    fprintf(stderr, "lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }
  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    tokens[position++] = token;
    if (position >= LSH_TOK_BUFSIZE) {
      bufsize += LSH_TOK_BUFSIZE;
      tokens = realloc(tokens, bufsize * sizeof(char *));
      if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
      }
      token = strtok(NULL, LSH_TOK_DELIM);
    }
  }
  tokens[position] = NULL;
  return tokens;
}




void lsh_loop(void) {
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = lsh_read_line();
    args = lsh_split_line(line);
    status = lsh_execute(args);
    free(line);
    free(args);
  } while (status);
}

int main(int argc, char **grgv) {

  // Load config files, ifa any.

  // Run command loop.which interpreter and executes and terminates commands
  lsh_loop();

  // per
  return EXIT_SUCCESS;
}
