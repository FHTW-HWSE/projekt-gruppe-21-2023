#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 25

struct Reservation {
    int time; // time in hours since the start of the day
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
};

int main() {
    int num_reservations = 0;
    struct Reservation *reservations = NULL;

    int time, duration;
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];

    // prompt for time and contact person
    printf("Please enter the time (in hours since the start of the day): ");
    scanf("%d", &time);

    printf("Please enter the name of the contact person: ");
    scanf("%s", name);

    printf("Please enter the phone number of the contact person: ");
    scanf("%s", phone);

    // prompt for reservation duration (optional)
    printf("Do you want to change the reservation duration? (0 = no, 1 = yes): ");
    int response;
    scanf("%d", &response);

    if (response) {
        printf("Please enter the reservation duration in hours: ");
        scanf("%d", &duration);
    } else {
        duration = 1; // Default: 1 hour 
    }

    // saving the reservation
    struct Reservation *new_reservations = realloc(reservations, (num_reservations + 1) * sizeof(struct Reservation));

    if (!new_reservations) {
        printf("Error: Memory could not be allocated!\n");
        free(reservations);
        return 1;
    }

    reservations = new_reservations;

    reservations[num_reservations].time = time;
    strncpy(reservations[num_reservations].name, name, MAX_NAME_LEN);
    strncpy(reservations[num_reservations].phone, phone, MAX_PHONE_LEN);

    num_reservations++;

    // output of reservation list
    printf("\n--- reservations ---\n");
    for (int i = 0; i < num_reservations; i++) {
        printf("time: %d, name: %s, phone number: %s\n", reservations[i].time, reservations[i].name, reservations[i].phone);
    }
    printf("-----------------------\n\n");

    // release of memory
    free(reservations);

    return 0;
}
