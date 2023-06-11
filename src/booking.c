#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define nameLength 50
#define timeLength 17
#define telNumLen 25

typedef struct booking {
    int idPerson;
    int idTable;
    char startTime[timeLength];
    char endTime[timeLength];
    struct booking* next;
} booking;

int main() {
    int num_bookings = 0;
    struct booking* bookings = NULL;

    int idPerson, idTable;
    char startTime[timeLength];
    char endTime[timeLength];

    // prompt for person ID, table ID, start time, and end time
    printf("Please enter the person ID: ");
    scanf("%d", &idPerson);

    printf("Please enter the table ID: ");
    scanf("%d", &idTable);

    printf("Please enter the start time: ");
    scanf("%s", startTime);

    printf("Please enter the end time: ");
    scanf("%s", endTime);

    // saving the booking
    struct booking* new_bookings = realloc(bookings, (num_bookings + 1) * sizeof(struct booking));

    if (!new_bookings) {
        printf("Error: Memory could not be allocated!\n");
        free(bookings);
        return 1;
    }

    bookings = new_bookings;

    bookings[num_bookings].idPerson = idPerson;
    bookings[num_bookings].idTable = idTable;
    strncpy(bookings[num_bookings].startTime, startTime, timeLength);
    strncpy(bookings[num_bookings].endTime, endTime, timeLength);
    bookings[num_bookings].next = NULL;

    num_bookings++;

    // output of booking list
    printf("\n--- Bookings ---\n");
    for (int i = 0; i < num_bookings; i++) {
        printf("ID: %d, Table: %d, Start Time: %s, End Time: %s\n", bookings[i].idPerson, bookings[i].idTable, bookings[i].startTime, bookings[i].endTime);
    }
    printf("----------------\n\n");

    // release of memory
    free(bookings);

    return 0;
}

int addBooking(booking* booking)
{
 int num_bookings = 0;
    struct booking* bookings = NULL;

    int idPerson, idTable;
    char startTime[timeLength];
    char endTime[timeLength];

    // prompt for person ID, table ID, start time, and end time
    printf("Please enter the person ID: ");
    scanf("%d", &idPerson);

    printf("Please enter the table ID: ");
    scanf("%d", &idTable);

    printf("Please enter the start time: ");
    scanf("%s", startTime);

    printf("Please enter the end time: ");
    scanf("%s", endTime);

}
void showBookingList(booking* booking)
{
    int num_bookings=sizeof(booking);
    printf("\n--- Bookings ---\n");
    for (int i = 0; i < num_bookings; i++) {
        printf("ID: %d, Table: %d, Start Time: %s, End Time: %s\n", booking[i].idPerson, booking[i].idTable, booking[i].startTime, booking[i].endTime);
    }
    printf("----------------\n\n");

}
