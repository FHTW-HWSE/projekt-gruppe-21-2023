#pragma once   

#include <stdio.h>
#include <stdlib.h>
#include "structhandeling.h"


struct booking *findBookingfromPerson (struct booking *toSearch, struct person *toFind);
int *findContact(int distance, int *returnArray, struct booking *startBooking, struct booking *findContact, struct person *toFind, struct person *startPerson, struct table *startTable);
int betrag(int i);
void traceContact(int distance, struct booking *startBooking, struct table *startTable, int personID);