#include <stdio.h>
#include "../include/parser.h"
#include "../include/structhandeling.h"
#include "../include/contact.h"
#include "../include/contacTracing.h"

//Braucht den Anfang der Liste von Buchungen und eine Person die Gefunden werden muss
//Kann man vielleicht optimieren in dem man die ID der Persion verwendet. Ist im Grunde gleich
struct booking *findBookingfromPerson(struct booking *startBooking, struct person *toFind){ //Da ist der Fall von mehreren Buchungen nicht ausgeschlossen
                                                                                            //Müssert man mit einem Array an Structs machen
    do{
        if(toFind->id == startBooking->idPerson){
            return startBooking;
        }

        if(startBooking->next != NULL){
            startBooking = startBooking->next;
        }

    } while(startBooking->next != NULL);
    return NULL;
}


int *findContact(int distance, int *returnArray, struct booking *startBooking, struct booking *findContact, struct person *toFind, struct person *startPerson, struct table *startTable){
    struct table *tempTableToComp1;
    struct table *tempTableToComp2;
    int i = 0;

    while(startBooking->next != NULL){
        
        if(strcmp(findContact->startTime, startBooking->endTime) > 0 || strcmp(findContact->endTime, startBooking->startTime) < 0) {
            //Wenn jemand gegangen ist bevor ein anderer gekommen ist und wenn jemand gekommen ist nachdem jemand anderer gegangen ist können sie keinen Kontakt haben.
            //Alle andere sind betroffen
            if(findContact->idPerson != startBooking->idPerson){
                //Falls eine Person zwei Tische nebeneinander gebucht hat
            
                while(startTable->next != NULL){
                    if(startTable->id == findContact->idTable){
                        tempTableToComp1 = startTable;
                        //Tisch der Person von dem wir das Contact Tracing starten

                    }
                    
                    if(startTable->id == startBooking->idTable){
                        tempTableToComp2 = startTable;
                        //Tisch der Person die potentiel Kontakt hatte
                    }
                    if(betrag(tempTableToComp1->x - tempTableToComp2->x + tempTableToComp1->x - tempTableToComp2->x) <= distance){
                        returnArray[i] = startBooking->idPerson;
                        i++;                    
                    }
                    startTable = startTable->next;
                }
            }
        }


        startBooking = startBooking->next;
    }

    return returnArray; //liefert die Ids der betroffenen Personen zurück
}   



int betrag (int i){
    if(i >= 0){
        return i;
    }
    if(i < 0){
        return -i;
    }
    return -1; // damit der Compieler happy ist
} 


    /* 2   -   1    -    2
             |
     1   -   0    -    1 */