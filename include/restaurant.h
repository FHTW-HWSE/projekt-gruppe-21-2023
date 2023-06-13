#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "structhandeling.h"

#define MAX_TABLES 100
/*struct Table 
{
    int tableNumber;
    float length;
    float width;
};*/
typedef struct Restaurant {
    float length;
    float width;
    table* tables[MAX_TABLES];
    int numTables;
    person* people;
} restaurant;

void displayRestaurantSize(struct Restaurant *restaurant);
void displayTables(struct Restaurant *restaurant);
int addTable(struct Restaurant *restaurant, int x, int y);
int removeTable(struct Restaurant *restaurant, int tableNumber);
void displayPeople(struct Restaurant *restaurant);
void addPerson(struct Restaurant* restaurant, const char* name, const char* number);
int changePerson(struct Restaurant* restaurant, int personID, const char* newName, const char* newNumber);
int removePerson(struct Restaurant *restaurant, int personID);
void displayBookingsID(struct booking *headBooking);
void displayBookingsName(struct booking *headBooking, struct person *headPerson, struct table *headTable);
