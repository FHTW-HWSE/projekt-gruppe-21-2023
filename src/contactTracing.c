#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "structhandeling.h"
#include "contact.h"


struct booking *findBookingfromPerson(struct booking toSearch, struct person toFind){
    while(toSearch->next != NULL){
        if(toFind->id == toSeach->idPerson){

        }


        toSearch = toSearch->next;
    }
    return toSeach;

}

int *findContact(int *returnArray, struct booking *startBooking, struct booking *findContact, struct person *toFind, struct person *startPerson){
    while(startBooking->next != NULL){
        if(findContact->starttime > startBooking->endtime || findContact->endtime < startBooking->starttime)  // toDo mit Stingcompare machen



    }

    return returnArray;
}   