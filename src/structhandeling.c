#include "../include/parser.h"
#include "../include/structhandeling.h"

struct person *createPersonHead(){   
    person *new = malloc(sizeof(person));

    if (new != NULL){
        return NULL;
    }

    new->next = NULL; 
    return new;
}

struct table *createTableHead(){   
    table *new = malloc(sizeof(table));

    if (new != NULL){
        return NULL;
    }

    new->next = NULL; 
    return new;
}

struct booking *createBookingHead(){
    booking *new = malloc(sizeof(booking));
    if (new != NULL){
        return NULL;
    }
    new->next = NULL;
    return new;

}

void addPersonList(struct person *old){
    person *new = malloc(sizeof(person)); 

    if(new == NULL){
        return;
    }

    new = old;

    while(new->next != NULL){
        new = new->next;
    }
    old->next = new;
    new->next = NULL;
}

void addTableList(struct table *old){
    table *new = malloc(sizeof(table));

    if(new == NULL){
        return;
    }

    new = old;

    while(new->next != NULL){
        new = new->next;
    }
    old->next = new;
    new->next = NULL;
}

void addBookingList(struct booking *old){
    booking *new = malloc(sizeof(booking));

    if(new == NULL){
        return;
    }

    new = old;

    while(new->next != NULL){
        new = new->next;
    }
    old->next = new;
    new->next = NULL;
}

void cleanPerson(struct person *toClean){
    struct person *temp;
    temp = toClean;

    while(temp->next != NULL){
        temp = toClean->next;        
        free(toClean);
        toClean = temp;
    }
    free(temp);
}

void cleanTable(struct table *toClean){
    struct table *temp;
    temp = toClean;

    while(temp->next != NULL){
        temp = toClean->next;        
        free(toClean);
        toClean = temp;
    }
    free(temp);
}


void cleanBooking(struct booking *toClean){
    struct booking *temp;
    temp = toClean;

    while(temp->next != NULL){
        temp = toClean->next;        
        free(toClean);
        toClean = temp;
    }
    free(temp);
}