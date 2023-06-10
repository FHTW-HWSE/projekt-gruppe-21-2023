#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "structhandeling.h"
#include "contact.h"


struct booking *findBookingfromPerson(struct booking *toSearch, struct person *toFind){
    while(toSearch->next != NULL){
        if(toFind->id == toSeach->idPerson){

        }


        toSearch = toSearch->next;
    }
    return toSeach;

}


int *findContact(int distance, int *returnArray, struct booking *startBooking, struct booking *findContact, struct person *toFind, struct person *startPerson, struct table *startTable){
    struct table *tempTableToComp1;
    struct table *tempTableToComp2;
    int i = 0;

    while(startBooking->next != NULL){
        
        if(strcmp(findContact->starttime, startBooking->endtime) > 0 || strcmp(findContact->endtime, startBooking->starttime) < 0) {
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
                    if(betrag(tempTableToComp1->x - tempTableToComp2->x == 1 + tempTableToComp1->x - tempTableToComp2->x == -1) <= distance){
                        returnArray[i] = startBooking->idPerson;
                        i++;                    
                    }
                    startTable = startTable->next;
                }
            }
        }


        startBooking = startBooking->next;
    }

    return returnArray;
}   



int betrag (int i){
    if(i >= 0){
        return i;
    }
    if(i < 0){
        return -i;
    }
} 


    /* 2   -   1    -    2
             |
     1   -   0    -    1 */