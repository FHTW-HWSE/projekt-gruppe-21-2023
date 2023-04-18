#include <stdio.h>
#include <stdlib.h>

int** createIntArray(int x, int y) {
    int** arr = (int**)malloc(x * sizeof(int*)); // Speicher für x Zeiger auf Integer reservieren
    if (arr == NULL) {
        printf("Fehler: Speicher konnte nicht allokiert werden.\n");
        exit(1); // Beenden des Programms mit Fehlercode 1
    }

    for (int i = 0; i < x; i++) {
        arr[i] = (int*)malloc(y * sizeof(int)); // Speicher für y Integer reservieren
        if (arr[i] == NULL) {
            printf("Fehler: Speicher konnte nicht allokiert werden.\n");
            exit(1); // Beenden des Programms mit Fehlercode 1
        }
    }

    return arr;
}
