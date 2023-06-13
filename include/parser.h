#pragma once 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "structhandeling.h"

#define wordLength 50


int parseTable (char *text, struct table *toTable);
int parsePerson(char *text, struct person *toPerson);
int parseBooking (char *text, struct booking *toBooking);
void toDate(char *date);
void toDateOffset2(char *date);
int personToString(struct person *startPerson, char *text);
int tableToString(struct table *startTable, char *text);
int bookingToString(struct booking *startBooking, char *text);
