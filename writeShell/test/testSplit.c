#include"writeShell.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
  printf("read a line \n");
  char* buf;
  buf = lsh_read_line();
  printf("start split line to tokens\n");
  char** tokens = lsh_split_line(buf);
  int position = 0;
  while(tokens[position] != NULL){
    printf("%s\n",tokens[position++]);
  }
  free(tokens);
  free(buf);
}

