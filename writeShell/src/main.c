#include "writeShell.h"
#include <stdio.h>
#include<stdlib.h>

#define LSH_RL_BUFSIZE 1024

char *lsh_read_line(void){
  int bufsize = LSH_RL_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char)*bufsize);
  int c;

  if(!buffer){
    fprintf(stderr,"lsh: allocation error\n");
    exit(EXIT_FAILURE);
  }
  while(1){
    c= getchar();

  }
  
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
