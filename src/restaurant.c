#include <stdio.h>
#include <stdlib.h>

#define MAX_TABLES 10

struct Table {
    int tableNumber;
    float length;
    float width;
};

struct Restaurant {
    float length;
    float width;
    struct Table tables[MAX_TABLES];
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
        printf("Table %d: Length=%.2f, Width=%.2f\n", restaurant.tables[i].tableNumber, restaurant.tables[i].length, restaurant.tables[i].width);
    }
    printf("-------------\n");
}

// add table to restaurant
int addTable(struct Restaurant *restaurant, float length, float width) {
    if (restaurant->numTables >= MAX_TABLES) {
        printf("Error: Maximum number of tables reached.\n");
        return 0;
    }

    struct Table newTable;
    newTable.tableNumber = restaurant->numTables + 1;
    newTable.length = length;
    newTable.width = width;

    restaurant->tables[restaurant->numTables] = newTable;
    restaurant->numTables++;

    return 1;
}

// remove table from restaurant
int removeTable(struct Restaurant *restaurant, int tableNumber) {
    for (int i = 0; i < restaurant->numTables; i++) {
        if (restaurant->tables[i].tableNumber == tableNumber) {
            for (int j = i; j < restaurant->numTables - 1; j++) {
                restaurant->tables[j] = restaurant->tables[j + 1];
            }
            restaurant->numTables--;
            printf("Table %d removed.\n", tableNumber);
            return 1;
        }
    }
    
    printf("Error: Table %d not found.\n", tableNumber);
    return 0;
}

int main() {
    struct Restaurant restaurant;
    float newLength, newWidth;
    int choice, tableNumber;
    float tableLength, tableWidth;

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
                printf("Enter the dimensions of the table:\n");
                printf("Length: ");
                scanf("%f", &tableLength);
                printf("Width: ");
                scanf("%f", &tableWidth);

                if (addTable(&restaurant, tableLength, tableWidth)) {
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


