#include <stdio.h>
#include <stdlib.h>

#define MAX_TABLES 10

typedef struct table {
    int x;
    int y;
    int id;
    struct table* next;
} table;

struct Restaurant {
    float length;
    float width;
    table* tables[MAX_TABLES];
    int numTables;
};

// displays size of restaurant
void displayRestaurantSize(struct Restaurant restaurant) {
    printf("Restaurant Size: Length=%.2f, Width=%.2f\n", restaurant.length, restaurant.width);
}

// display tables in restaurant
void displayTables(struct Restaurant restaurant) {
    printf("--- Tables ---\n");
    for (int i = 0; i < restaurant.numTables; i++) {
        printf("Table %d: X=%d, Y=%d, ID=%d\n", i+1, restaurant.tables[i]->x, restaurant.tables[i]->y, restaurant.tables[i]->id);
    }
    printf("-------------\n");
}

// add table to restaurant
int addTable(struct Restaurant* restaurant, int x, int y) {
    if (restaurant->numTables >= MAX_TABLES) {
        printf("Error: Maximum number of tables reached.\n");
        return 0;
    }

    table* newTable = (table*)malloc(sizeof(table));
    newTable->x = x;
    newTable->y = y;
    newTable->id = restaurant->numTables + 1;
    newTable->next = NULL;

    restaurant->tables[restaurant->numTables] = newTable;
    restaurant->numTables++;

    return 1;
}

// remove table from restaurant
int removeTable(struct Restaurant* restaurant, int tableNumber) {
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

int main() {
    struct Restaurant restaurant;
    float newLength, newWidth;
    int choice, tableNumber;
    int tableX, tableY;

    // prompt user to enter the initial size of restaurant
    printf("Please enter the initial size of the restaurant:\n");
    printf("Length: ");
    scanf("%f", &restaurant.length);
    printf("Width: ");
    scanf("%f", &restaurant.width);

    // display initial size of restaurant
    displayRestaurantSize(restaurant);

    // menu loop
    do {
        printf("Menu:\n");
        printf("1. Add table\n");
        printf("2. Remove table\n");
        printf("3. Display tables\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // add table to restaurant
                printf("Enter the position of the table:\n");
                printf("X: ");
                scanf("%d", &tableX);
                printf("Y: ");
                scanf("%d", &tableY);

                if (addTable(&restaurant, tableX, tableY)) {
                    printf("Table added successfully.\n");
                }
                break;
            case 2:
                // remove table from restaurant
                printf("Enter the table number to remove: ");
                scanf("%d", &tableNumber);
                removeTable(&restaurant, tableNumber);
                break;
            case 3:
                // display tables in restaurant
                displayTables(restaurant);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
