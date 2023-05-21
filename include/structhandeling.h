#ifndef  PARSER_H

#define  PARSER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define wordLength 50

struct table newTable();
struct person newPerson();
struct booking newBooking();

void addTable(struct table *oldTable);
void addPerson(struct person *oldPerson);
void addBooking(struct booking *oldBooking);



#endif