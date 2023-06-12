#include "../include/restaurant.h"
#include "../include/structhandeling.h"
#include "../include/parser.h"
#include "../include/filehandeling.h"
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

    char functionBuffer[MAX_BUFFER];
    int functionCheck;
    char filename[nameLength];

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
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Geben Sie eine y Koordinate an: \n ");
                scanf("%d", &tableY);
                printf("Geben Sie eine x Koordinate an: \n ");
                scanf("%d", &tableX);
                functionCheck = addTable(restaurant, tableX, tableY);

                if(functionCheck == 1){
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
                addPerson(restaurant, personName, personNumber);
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

                functionCheck = personToString(headPerson, functionBuffer);
                printf("Parsed %d symbols from structs to String \n", functionCheck);

                
                printf("Please enter the filename with including path for persons: \n");
                scanf("%s", filename);

                functionCheck = writeFile(filename, functionBuffer);
                if(functionCheck == 0){
                  printf("Person data saved\n");
                }
                else{
                  printf("Error saving person data\n");
                }

                for(int q = 0; q < MAX_BUFFER; q++){
                  functionBuffer[q] = '\0';
                } 


                functionCheck = tableToString(headTable, functionBuffer);
                printf("Parsed %d symbols from structs to String \n", functionCheck);

                
                printf("Please enter the filename including the path for tables: \n");
                scanf("%s", filename);
                functionCheck = writeFile(filename, functionBuffer);
                if(functionCheck == 0){
                  printf("Table data saved\n");
                }
                else{
                  printf("Error saving table data\n");
                }

                for(int q = 0; q < MAX_BUFFER; q++){
                  functionBuffer[q] = '\0';
                } 

                functionCheck = bookingToString(headBooking, functionBuffer);

                
                printf("Please enter the filename with the path for booking: \n");
                scanf("%s", filename);
                functionCheck = writeFile(filename, functionBuffer);
                if(functionCheck == 0){
                  printf("Table data saved\n");
                }
                else{
                  printf("Error saving booking data\n");
                }

                for(int q = 0; q < MAX_BUFFER; q++){
                  functionBuffer[q] = '\0';
                } 

                break;               

            case 10:

                //ToDo
                break;

            case 11:
                printf("Please enter the filename with the path for persons: \n");
                scanf("%s", filename);
                functionCheck = readFile(filename, functionBuffer);
                if(functionCheck == 0){
                  printf("%d symbols were read.\n", functionCheck);
                }
                else{
                  printf("Error reading from file \n");
                }
                functionCheck = parsePerson(functionBuffer, headPerson);

                printf("%d structs person have been created\n", functionCheck);

                for(int q = 0; q < MAX_BUFFER; q++){
                  functionBuffer[q] = '\0';
                } 

                printf("Please enter the filename with the path for tables: \n");
                scanf("%s", filename);
                functionCheck = readFile(filename, functionBuffer);
                if(functionCheck == 0){
                  printf("%d symbols were read.\n", functionCheck);
                }
                else{
                  printf("Error reading from file \n");
                }
                functionCheck = parseTable(functionBuffer, headTable);
                printf("%d structs table have been created\n", functionCheck);

                for(int q = 0; q < MAX_BUFFER; q++){
                  functionBuffer[q] = '\0';
                }


                printf("Please enter the filename with the path for booking: \n");
                scanf("%s", filename);
                functionCheck = readFile(filename, functionBuffer);
                if(functionCheck == 0){
                  printf("%d symbols were read.\n", functionCheck);
                }
                else{
                  printf("Error reading from file \n");
                }
                functionCheck = parseBooking(functionBuffer, headBooking);
                printf("%d structs booking have been created\n", functionCheck);

                for(int q = 0; q < MAX_BUFFER; q++){
                  functionBuffer[q] = '\0';
                }

                break;

            case 12:
                printf("Bitte geben Sie die ID der Person und die ID des Tisches ein. \n");
                printf("ID person:\n");
                scanf("%d", &personID);
                printf("ID table:\n");
                scanf("%d", &tableNumber);
                printf("Time:\n");

                do{

                  printf("1. Automatically + Offset\n");
                  printf("2. Manual start and endtime\n");

                  switch(choice){
                    case 1:

                      break;

                    case 2:

                      break;

                
                  }
                }while(1);
                break;


            default:
                printf("Invalid choice. Please try again. Choice %d\n", choice);
                break;
        }


        printf("\n");
    } while (1);

    return 0;
}
