#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define nameLength 50
#define timeLength 17
#define telNumLen  25

struct person {
    char name [nameLength];   
    char number [telNumLen];
    int id;
};


struct table {
    int x;
    int y;
    int id;
};

struct booking {
    struct person *personBooking;
    struct table *tableBooking;
    char startTime[timeLength];
    char endTime[timeLength];
};

#endif