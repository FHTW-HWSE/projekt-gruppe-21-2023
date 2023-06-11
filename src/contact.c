#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nameLength 50
#define telNumLen 25

typedef struct {
    char name[nameLength];
    char number[telNumLen];
    int id;
} Contact;

void addContact(Contact* contact)
{
    printf("Bitte geben Sie den Namen ein: ");
    fgets(contact->name, sizeof(contact->name), stdin);
    contact->name[strcspn(contact->name, "\n")] = '\0';

    printf("Bitte geben Sie die Telefonnummer ein: ");
    fgets(contact->number, sizeof(contact->number), stdin);
    contact->number[strcspn(contact->number, "\n")] = '\0';

    printf("Bitte geben Sie die ID ein: ");
    scanf("%d", &(contact->id));
    getchar(); 

    printf("Tisch erfolgreich gebucht!\n");
}

/*int main() {
    Contact contact;

    printf("Willkommen im Restaurant!\n");

    addContact(&contact);

    printf("Kontaktdaten:\n");
    printf("Name: %s\n", contact.name);
    printf("Telefonnummer: %s\n", contact.number);
    printf("ID: %d\n", contact.id);

    return 0;
}*/
