/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: root
 *
 * Created on June 24, 2016, 9:48 PM
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {
	char line[MAX_LENGTH];

	while (1) {
		printf("$ ");
		if (!fgets(line, MAX_LENGTH, stdin)) break;

		printf("%s", line);

		system(line);
	}

	return 0;
}

