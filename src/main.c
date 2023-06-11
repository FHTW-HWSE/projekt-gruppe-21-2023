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

    // menu loop
    do {
        printf("Menu:\n");
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
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            
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
                break;
            case 9;


            case 10;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 8);

    return 0;
}
