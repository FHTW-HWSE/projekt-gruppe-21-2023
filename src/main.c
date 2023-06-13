#include "../include/restaurant.h"
#include "../include/structhandeling.h"
#include "../include/parser.h"
#include "../include/filehandeling.h"
#include "../include/contact.h"
#include "../include/booking.h"
#include "../include/contacTracing.h"

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

/*
struct Restaurant restaurant;
struct Table table;
struct Contact contact;
struct Booking booking;

*/


/* int main()
{
 struct Restaurant *restaurant = malloc(sizeof(restaurant));
 char command[30];
 printf("Willkommen beim Reservierungsystem. Wie kann ich Ihnen behilflich sein?");
 scanf("%s",command);
 while(1)
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
   if(strcmp(command,"")){
    
   }


 }
} */





int main() {
    struct Restaurant *restaurant = malloc (sizeof(restaurant));
    float newLength, newWidth;
    int choice, tableNumber, personID;
    int tableX, tableY;
    char personName[nameLength];
    char personNumber[telNumLen];

    char timeBufferStart[timeLength];
    char timeBufferEnd[timeLength];
    int tempTimeInt;
    char functionBuffer[MAX_BUFFER];
    int functionCheck;
    char filename[nameLength];
    int flagTable = 0;
    int flagPerson = 0;
    int flagBooking = 0;

    // initialize restaurant
    restaurant->length = 0.0f;
    restaurant->width = 0.0f;
    restaurant->numTables = 0;
    restaurant->people = NULL;

    // prompt user to enter initial size of restaurant
    printf("Please enter the initial size of the restaurant in m:\n");
    printf("Length: ");
    scanf("%f", &restaurant->length);
    printf("Width: ");
    scanf("%f", &restaurant->width);

    // display initial size of restaurant
    displayRestaurantSize(restaurant);

    //Create Heads for the Table Person and Booking Structs
    person *headPerson = malloc(sizeof(booking));
    booking *headBooking = malloc(sizeof(booking));
    table *headTable = malloc(sizeof(booking));

    table *tempTable = malloc(sizeof(table));
    person *tempPerson = malloc(sizeof(person));
    booking *tempBooking = malloc(sizeof(booking));

    restaurant->people = headPerson;


    // menu loop
    do {
        printf("Menu:\n");
        printf("1. Add table\n");
        printf("2. Remove table\n");
        printf("3. Add person\n");
        printf("4. Change person's information\n");
        printf("5. Remove person\n");
        printf("6. Display tables\n");
        printf("7. Display people\n");
        printf("8. Exit\n");
        printf("9. Save data\n");
        printf("10. Start Contact-Tracing\n");
        printf("11. Load data from Files\n");
        printf("12. Add Booking\n");
        printf("13. Display Bookings\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter an integer.\n");

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        continue;
    }
        

        switch (choice) {
            case 1:
                printf("Geben Sie eine y Koordinate an: \n ");
                scanf("%d", &tableY);
                printf("Geben Sie eine x Koordinate an: \n ");
                scanf("%d", &tableX);
                functionCheck = addTable(restaurant, tableX, tableY);

                
                printf("Tshoot Segmentation fault\n");

                if(functionCheck == 1){

                  if(flagTable == 0){
                    fillTableHead(headTable, tableX, tableY);
                    restaurant->tables[0] = headTable;
                    flagTable = 1;

                  } else {
                    addTableList(headTable);
                    tempTable = headTable;

                    do{
                     if(tempTable->next == NULL){
                       tempTable->x = tableX;
                       tempTable->y = tableY;
                     }
                     else{
                       tempTable = tempTable->next;
                     }
                    }
                    while(tempTable->next != NULL);
                  }
                }
                

                break;

            case 2:
                // remove table from restaurant
                printf("Enter the table number to remove: ");
                scanf("%d", &tableNumber);
                removeTable(restaurant, tableNumber);
                break;
            case 3:
                // add person to restaurant
                printf("Enter the person's name: ");
                scanf("%s", personName);
                printf("Enter the person's phone number: ");
                scanf("%s", personNumber);
                

                if(flagPerson == 0){
                  fillPersonHead(headPerson, personName, personNumber);
                  flagPerson = 1;
                  restaurant->people = headPerson;
                }
                else{
                  addPerson(restaurant, personName, personNumber);
                }

                /*addPersonXY(headPerson);
                tempPerson = headPerson;

                  do{
                    if(tempPerson->next == NULL){
                      strncpy(tempPerson->name, personName, nameLength);
                      strncpy(tempPerson->number, personNumber, telNumLen);
                    }
                    else{
                      tempPerson = tempPerson->next;
                    }
                  }
                  while(tempPerson->next != NULL);*/


                break;
            case 4:
                // change person's information
                printf("Enter the person's ID: ");
                scanf("%d", &personID);
                printf("Enter the new name: ");
                scanf("%s", personName);
                printf("Enter the new phone number: ");
                scanf("%s", personNumber);
                if (changePerson(restaurant, personID, personName, personNumber)) {
                    printf("Person information updated successfully.\n");
                } else {
                    printf("Person not found.\n");
                }
                break;
            case 5:
                // remove person from restaurant
                printf("Enter the person's ID to remove: ");
                scanf("%d", &personID);
                if (removePerson(restaurant, personID)) {
                    printf("Person removed successfully.\n");
                } else {
                    printf("Person not found.\n");
                }
                break;
            case 6:
                // display tables in restaurant
                displayTables(restaurant);
                break;
            case 7:
                // display people in restaurant
                displayPeople(restaurant);
                break;
            case 8:
                // exit program
                printf("Exiting...\n");
                return 0;
                break;
            case 9:
                printf("Please choose the data you want to save:\n");
                printf("  1. Person data\n");
                printf("  2. Table data\n");
                printf("  3. Booking data\n");
                printf("  4. All\n");
                scanf("%d", &choice);
                do{
                switch(choice){
                  case 1:
                    savePerson(headPerson);
                    break;
                  case 2:
                    saveTable(headTable);
                    break;
                  case 3:
                    saveBooking(headBooking);
                    break;
                  case 4:
                    savePerson(headPerson);
                    saveTable(headTable);
                    saveBooking(headBooking);
                    break;
                  default:
                    printf("Error with the input please choose a valid option.\n");
                    break;

                }
                } while(choice > 4);




                break;               

            case 10:
                printf("Please enter the person Id you want to trace: \n");
                scanf("%d", &personID);
                printf("Please enter the distance to search: \n");
                int distance = 0;
                scanf("%d", &distance);
                traceContact(distance, headBooking, headTable, personID);

                //ToDo
                break;

            case 11:
                loadPerson(headPerson);
                loadTable(headTable);
                loadBooking(headBooking);
                break;

            case 12:
                printf("Please enter the person and table Ids \n");
                printf("ID person:\n");
                scanf("%d", &personID);
                printf("ID table:\n");
                scanf("%d", &tableNumber);
                printf("Time:\n");

                do{

                  printf("1. Automatically + 2h offset\n");
                  printf("2. Manual start and endtime\n");
                  scanf("%d", &choice);
                  

                  switch(choice){
                    case 1:
                      toDate(timeBufferStart);
                      toDateOffset2(timeBufferEnd);

                      printf("Startime: %s\n", timeBufferStart);
                      printf("Endtime: %s\n", timeBufferEnd);
                      if(flagBooking == 0){
                        fillBookingHead(headBooking, personID, tableNumber, timeBufferStart, timeBufferEnd);
                        flagBooking = 1;
                      } else {
                        addBookingData(headBooking, personID, tableNumber, timeBufferStart, timeBufferEnd);
                      }
                      break;

                    case 2:
                      //ToDo -> errorhandeling was passiert wenn falsche Zeit... oder input String zu lange
                      printf("Please enter the start and then the endtime: \n");
                      scanf("%s", timeBufferStart);
                      scanf("%s", timeBufferEnd);
                      if(flagBooking == 0){
                        fillBookingHead(headBooking, personID, tableNumber, timeBufferStart, timeBufferEnd);
                        flagBooking = 1;
                      } else {
                        addBookingData(headBooking, personID, tableNumber, timeBufferStart, timeBufferEnd);
                      }

                      break;
                    default:

                      printf("Error with the input please choose a valid option.\n");
                      break;
                      

                  }
                }while(choice > 2);
                break;

                case 13:
                  displayBookingsID(headBooking);
                  //displayBookingsName(headBooking, headPerson, headTable);
                  break;


            default:
                printf("Invalid choice. Please try again. Choice %d\n", choice);
                break;
        }


        printf("\n");
    } while (1);

    return 0;
}
