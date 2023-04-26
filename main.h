#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int exit_shell(ssize_t, char *);
int token_num(char *, const char *);
void execmd(char **argv);

#endif
