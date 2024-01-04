#include "writeShell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_pid_t.h>
#include <unistd.h>

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
    } else {
      buffer[position] = c;
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
}
 */

char *lsh_read_line(void) {
  // 有可能是我用的C语言标准不对，buffer必须明确赋值为NULL,因为getline根据NULL值
  // 自动分配内存，非NULL则不会分配。如果不明确赋值NULL,getline的行为无法预测，这有可能是
  // 我选的c标准没用默认给buffer赋值为NULL
  char *buffer = NULL;
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
    }
    token = strtok(NULL, LSH_TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

int lsh_launch(char **args) {
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    // Child process
    if (execvp(args[0], args) == -1) {
      perror("lsh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("lsh");
  } else {
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

