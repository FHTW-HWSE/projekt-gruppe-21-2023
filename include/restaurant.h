#ifndef RESTAURANT_H;
#define ReSTAURANT_H;

#include <stdio.h>
#include <stdlib.h>
#define MAX_TABLES 10
struct Table 
{
    int tableNumber;
    float length;
    float width;
};
struct Restaurant 
{
    float length;
    float width;
    struct Table tables[MAX_TABLES];
    int numTables;
};
void displayRestaurantSize(struct Restaurant restaurant);
void displayTables(struct Restaurant restaurant);
int addTable(struct Restaurant *restaurant, float length, float width);
int removeTable(struct Restaurant *restaurant, int tableNumber);
int main();
#endif