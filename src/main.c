/*
 #ifndef FILENAME_H // Include guard
 #define FILENAME_H
 // Includes for headers required within this file
 #include <stdint.h>
 // Type definitions
 typedef uint8_t u8;
 // Shared macro literals
 #define MAX_QUEUE 64
// Shared function-like macros
 #define ARRAY_SIZE(x) ((sizeof(x)) / (sizeof((x)[0])))
 // Prototypes of shared functions
 unsigned int some_function(u8 a, u8 b);
// "Exports" of global variables
extern int global_variable;
#endif

*/


//TODO Header ins Include File brinngen und aufräumen

#include <stdint.h>
#include "../include/structhandeling.h"
#include "../include/parser.h"
#include "../include/filehandeling.h"
#include "../include/restaurant.h"
#include "../include/contact.h"
#include "../include/booking.h"

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
struct Restaurant restaurant;
struct Table table;
struct Contact contact;
struct Booking booking;
int main()
{
 char command[30];
 printf("Willkommen beim Reservierungsystem. Wie kann ich ihnen behilflich sein?");
 scanf("%s",command);
 for(;;)
 {
   if(strcmp(command,"dipslayRestaurant")==1)
   {
    displayRestaurantSize(restaurant);
   }
   if(strcmp(command,"displayTables")==1)
   {
    displayTables(restaurant);
   }
   if(strcmp(command,"addTable")==1)
   {
     int tableX,tableY;
     
     printf("Bitte geben sie die Position ein:\n");
                printf("X: ");
                scanf("%d", &tableX);
                printf("Y: ");
                scanf("%d", &tableY);
      addTable(restaurant,tableX,tableY);          
   }
   if(strcmp(command,"removeTable")==1)
   {
     int tableID;
     printf("Bitte geben sie die ID von Tisch ein");
     scanf("%d", &tableID);
     removeTable(restaurant,tableID);
   }
   if(strcmp(command,"displayPerson")==1)
   {
    displayPeople(restaurant);
   }
   if(strcmp(command,"finish")==1)
   {
    printf("Vielen Dank für das Benutzen von dem Reservierungssystem");
    break;
   }
   if(strcmp(command,""))

 }
}