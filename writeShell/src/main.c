#include "writeShell.h"
#include<stdio.h>
#include<stdlib.h>

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


