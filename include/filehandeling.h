#pragma once   

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define MAX_FILE_LENGHT 1000

int writeFile(char *filename, char *inputString);
int readFile(char *filename, char *text);
int getRows(char *filename);

void saveBooking(struct booking *headBooking);
void saveTable(struct table *headTable);
void savePerson(struct person *headPerson);
void loadBooking(struct booking *headBooking);
void loadTable(struct table *headTable);
void loadPerson(struct person *headPerson);