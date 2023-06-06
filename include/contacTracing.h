#pragma once   

#include <stdio.h>
#include <stdlib.h>
#include "structhandeling.h"

struct booking *findBookingfromPerson (struct booking toSearch, struct person toFind);
int *findContact(int *returnArray, struct booking startBooking, struct booking findContact, struct person toFind);