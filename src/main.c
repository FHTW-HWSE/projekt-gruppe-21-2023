#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define nameLength 50;
#define timeLength 17;
#define telNumLen  25;
/*
Tisch
    x
    y
    id

Person
    Name
    Telefonnummer
    id

Buchung 
    Starttime
    Endtime
    Person
    Table    



Database.csv

4,5,
*/

/** 
 * Begin der Definitionen der structs
 * aktuell gibts person, table und booking
*/

/**
 * \struct
 *  
 *  
 */  
struct person {
    char name [nameLength];   //
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


int main (int argc, char ** argv){



    printf("Hello World");
    return 0;

}