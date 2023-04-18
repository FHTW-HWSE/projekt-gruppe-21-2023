#ifndef  PARSER_H

#define  PARSER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define wordLength 50

int parseTables(char *text);
int parsePerson(char *text);
int parseBookings(char *text);

#endif