#ifndef MAYM_H
#define MAYM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 100
#define MAX_ARGS 10

void handle_signal(int signo);
void execute_com(char *args[], int background);

#endif
