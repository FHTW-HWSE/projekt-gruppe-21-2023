#pragma once   

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "structhandeling.h"


#define MAX_FILE_LENGHT 1000

int writeFile(char *filename, char *inputString);
int readFile(char *filename, char *text);
int getRows(char *filename);


void loadPerson(struct person *headPerson);
void loadTable(struct table *headTable);
void loadBooking(struct booking *headBooking);

void savePerson(struct person *headPerson);
void saveTable(struct table *headTable);
void saveBooking(struct booking *headBooking);


