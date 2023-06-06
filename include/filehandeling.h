#pragma once   

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define MAX_FILE_LENGHT 1000

int writeFile(char *filename, char *inputString, char *mode);
int readFile(char *filename, char *text);
int getRows(char *filename);

