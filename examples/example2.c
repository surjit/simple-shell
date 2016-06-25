/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   example2.c
 * Author: root
 *
 * Created on June 24, 2016, 9:53 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef _WIN32
#include <windows.h>
#define chdir _chdir

#else
#include <unistd.h>
#endif

#define MAX_LENGTH 1024
#define DELIMS " \t\r\n"

int main(int argc, char *argv[]) {
  char *cmd;
  char line[MAX_LENGTH];

  while (1) {
    printf("$ ");
    if (!fgets(line, MAX_LENGTH, stdin)) break;

    // Parse and execute command
    if ((cmd = strtok(line, DELIMS))) {
      // Clear errors
      errno = 0;

      if (strcmp(cmd, "cd") == 0) {
        char *arg = strtok(0, DELIMS);

        if (!arg) fprintf(stderr, "cd missing argument.\n");
        else chdir(arg);

      } else if (strcmp(cmd, "exit") == 0) {
        break;

      } else system(line);

      if (errno) perror("Command failed");
    }
  }

  return 0;
}

