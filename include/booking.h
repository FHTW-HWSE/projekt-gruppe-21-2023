#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structhandeling.h"

#define nameLength 50
#define timeLength 17
#define telNumLen 25

/*typedef struct booking {
    int idPerson;
    int idTable;
    char startTime[timeLength];
    char endTime[timeLength];
    struct booking* next;
} booking; */

int addBooking(booking* booking);
void showBookingList(booking* booking);
