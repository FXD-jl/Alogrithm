#ifndef __WRITESHELL
#define __WRITESHELL

char *lsh_read_line(void);
char **lsh_split_line(char *line);

int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);

#endif
