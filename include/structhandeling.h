#pragma once 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define nameLength 50
#define timeLength 17
#define telNumLen  25
#define MAX_BUFFER 2000

typedef struct person {
    char name [nameLength];   
    char number [telNumLen];
    int id;
    struct person *next;
} person;



typedef struct table {
    int x;
    int y;
    int id;
    struct table *next;
} table;

typedef struct booking {
    int idPerson;
    int idTable;
    char startTime[timeLength];
    char endTime[timeLength];
    struct booking *next;
} booking;




void addPersonList(struct person *old);
void addTableList(struct table *old);
void addBookingList(struct booking *old);
void cleanPerson(struct person *toClean);
void cleanTable(struct table *toClean);
void cleanBooking(struct booking *toClean);
