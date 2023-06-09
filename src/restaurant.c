
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/restaurant.h"



/*typedef struct table {
    int x;
    int y;
    int id;
    struct table* next;
} table; */

/* typedef struct person {
    char name[nameLength];
    char number[telNumLen];
    int id;
    struct person* next;
} person; */



// displays size of restaurant
void displayRestaurantSize(struct Restaurant *restaurant) {
    printf("Restaurant Size: Length=%.2f, Width=%.2f\n", restaurant->length, restaurant->width);
}

// display tables in restaurant
void displayTables(struct Restaurant *restaurant) {
    printf("--- Tables ---\n");
    for (int i = 0; i < restaurant->numTables; i++) {
        printf("Table %d: X=%d, Y=%d, ID=%d\n", i + 1, restaurant->tables[i]->x, restaurant->tables[i]->y, restaurant->tables[i]->id);
    }
    printf("-------------\n");
}

// add table to restaurant
int addTable(struct Restaurant *restaurant, int x, int y) {
    // check if table already exists at provided coordinates
    for (int i = 0; i < restaurant->numTables; i++) {
        if (restaurant->tables[i]->x == x && restaurant->tables[i]->y == y) {
            printf("Error: A table already exists at coordinates (%d, %d).\n", x, y);
            return 0;
        }
    // check if one of the coorinates is negative
        if(x<0 || y<0)
        {
            printf("Error: One of the coordinates is negaitve.");
            return 0;
        }
        if (x>restaurant->length || y>restaurant->width )
        {
         printf("Error:The table is outside of the coordinates");
         return 0;
        }
       
    }

    if (restaurant->numTables >= maxTables) {
        printf("Error: Maximum number of tables reached.\n");
        return 0;
    }

    printf("start adding new table to struct\n");

    table* newTable = (table*)malloc(sizeof(table));
    newTable->x = x;
    newTable->y = y;
    idTable++;
    //newTable->id = restaurant->numTables + 1;
    newTable->id = idTable;
    newTable->next = NULL;

    restaurant->tables[restaurant->numTables] = newTable;
    restaurant->numTables++;
    printf("addTable return to Main\n");
    return 1;
}

// remove table from restaurant
int removeTable(struct Restaurant *restaurant, int tableNumber) {
    if (tableNumber <= 0 || tableNumber > restaurant->numTables) {
        printf("Error: Invalid table number.\n");
        return 0;
    }

    table* prev = NULL;
    table* current = restaurant->tables[tableNumber - 1];

    if (current == NULL) {
        printf("Error: Table %d not found.\n", tableNumber);
        return 0;
    }

    if (prev != NULL) {
        prev->next = current->next;
    } else {
        restaurant->tables[tableNumber - 1] = current->next;
    }

    free(current);
    restaurant->numTables--;

    printf("Table %d removed.\n", tableNumber);
    return 1;
}

// add person to restaurant
void addPerson(struct Restaurant* restaurant, const char* name, const char* number) {
    person* newPerson = (person*)malloc(sizeof(person));
    strncpy(newPerson->name, name, nameLength);
    strncpy(newPerson->number, number, telNumLen);
    idPerson++;
    //newPerson->id = restaurant->numTables + 1;
    newPerson->id = idPerson;
    newPerson->next = NULL;

    if (restaurant->people == NULL) {
        restaurant->people = newPerson;
    } else {
        person* current = restaurant->people;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPerson;
    }
    printf("Pointer to new person %d\n", newPerson);
}

// change person's information
int changePerson(struct Restaurant* restaurant, int personID, const char* newName, const char* newNumber) {
    person* current = restaurant->people;
    while (current != NULL) {
        if (current->id == personID) {
            strncpy(current->name, newName, nameLength);
            strncpy(current->number, newNumber, telNumLen);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// remove person from restaurant
int removePerson(struct Restaurant *restaurant, int personID) {
    person* prev = NULL;
    person* current = restaurant->people;

    while (current != NULL) {
        if (current->id == personID) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                restaurant->people = current->next;
            }
            free(current);
            return 1;
        }
        prev = current;
        current = current->next;
    }

    return 0;
}

// display people in restaurant
void displayPeople(struct Restaurant *restaurant) {
    printf("--- People ---\n");
    struct person *current = restaurant->people;
    while (current) {
        printf("Pointer to person: %d\n", current);
        printf("ID: %d, Name: %s, Number: %s\n", current->id, current->name, current->number);
        current = current->next;
    }
    printf("--------------\n");
}

void displayBookingsID(struct booking *headBooking) {
    printf("--- Bookings ---\n");

    struct booking *current;
    current = headBooking;

    while(current) {
        printf("IDPerson: %d, IDTable: %d, Starttime: %s, Endtime: %s\n", current->idPerson, current->idTable, current->startTime, current->endTime);
        current = current->next;
    }
    printf("--------------\n");
}

/*void displayBookingsName(struct booking *headBooking, struct person *headPerson, struct table *headTable) {
    printf("--- Bookings ---\n");
    struct person *tmpPerson;
    struct table *tmpTable;

    tmpPerson = headPerson;
    tmpTable = headTable;

    while (headBooking) {
        tmpPerson = headPerson;
        tmpTable = headTable;
        while(tmpPerson->id != headBooking->idPerson && tmpPerson->next != NULL){           
            tmpPerson = tmpPerson->next;
        }
        while(tmpTable->id != headBooking->idTable && tmpTable->next != NULL){
            tmpTable = tmpTable->next;
        }

        printf("Person Name: %s, Table X: %d, Table Y, %d, Starttime: %s, Endtime: %s\n", tmpPerson->name, tmpTable->x, tmpTable->y, headBooking->startTime, headBooking->endTime);
        headBooking = headBooking->next;
    }
    printf("--------------\n");
}
*/
