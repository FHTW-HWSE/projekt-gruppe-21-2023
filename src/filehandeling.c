// TODO Header ins Include File brinngen und aufräumen

#include "filehandeling.h"
#include "structhandeling.h"
#include "parser.h"

/*! fn getRows
    @brief gibt aus wie viele Zeilen ein File hat indem es die Zeichen /n sucht
    @param filename File aus dem gelesen werden soll
    @return numRows die Anzahl der Zeilen die einem File sind
    sollte helfen beim einlesen der Daten aus den Strings in die Structs
*/

int getRows(char *filename){
    FILE *file;
    int numRows = 0;
    char next;

    file = fopen(filename, "r");

    if (file == NULL)
    {
        return -1;
    }

    do
    {
        next = fgetc(file);
        if (next == 10) // Ascii 10 ist der Zeilenumbruch
        {
            numRows++;
        }

    } while (next != EOF);

    return numRows;
}


/*! fn readFile
    @brief schreibt die Daten aus einem File in einen String
    @param filename aus dem gelesen wird
    @param test Sting auf dessen Specherplatz dann der eingelesene String gespeichert wird
    @return ein int in dem die Länge des eingelesenen Strings steht
*/

int readFile(char *filename, char *text) {
    FILE *file;
    int i = 0;

    file = fopen(filename, "r");

    if (file == NULL)
    {
        return -1;
    }

    do
    {
        text[i] = fgetc(file);
        i++;
    } while (text[i] != EOF);

    fclose(file);
    // brauchen wir das: text[i] = '/0';
    return i;
}


/*! fn write File
    @brief schreibt die Daten von einem übergebenen String in das angegebene File
    @param filename in das geschrieben 
    @param Sting der in das File geschrieben wird
    @return 0 für Erfolgreich
*/

int writeFile(char *filename, char *inputString, char *mode){
    FILE *file;

    file = fopen(filename, mode);

    if( file == NULL ) {
        return -1;
    }

    fprintf(file, "%s", inputString);

    fclose(file);
    return 0;
}


/*int changeEntry(char *filename, char inputString, int line){
    FILE *file;
    char currentChar = 'i'; //damit  nicht zufällig der uninitialisierte Wert uns rein spuckt


    file = fopen(filename, "r+");

    for(int i = 0; i < line; i++){
        while(currentChar != '\n') {
            currentChar = fgetc(file);


            
        }
    }

}*/