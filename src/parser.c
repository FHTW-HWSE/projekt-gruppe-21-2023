// TODO Header ins Include File brinngen und aufräumen
#include "../include/structhandeling.h"
#include "../include/parser.h"

/*! fn getRows
    @brief Liest aus dem Sting die Daten und speichert diese in einem Struct
    @param *text String aus dem der Text gelesen wird *toPerson struct in dem die Daten eingelesen werden
    @return Anzahl der erstellten Personen
*/

void toDate(char *date){
    time_t now = time(NULL);
    struct tm tm = *localtime(&now);    
    int tmp, tmp1, tmp2, tmp3 ,tmp4;
    

    tmp = tm.tm_year + 1900;
    tmp1 = tmp / 1000;
    tmp2 = (tmp - tmp1 * 1000) / 100;
    tmp3 = (tmp - tmp1 * 1000 - tmp2 * 100) / 10;
    tmp4 = (tmp - tmp1 * 1000 - tmp2 * 100 - tmp3 * 10);

    date[0] = tmp1 + '0';
    date[1] = tmp2 + '0';
    date[2] = tmp3 + '0';
    date[3] = tmp4 + '0';
    

    /*
    date[5] = ':';
    
    date[6] = (tm.tm_mon + 1) / 10 + '0';
    date[7] = (tm.tm_mon + 1) % 10 + '0';

    date[8] = ':';

    date[9] = tm.tm_mday / 10 + '0';
    date[10] = tm.tm_mday % 10 + '0';

    date[11] = ':';
     
    date[12] = tm.tm_hour / 10 + '0';
    date[13] = tm.tm_hour % 10 + '0';

    date[14] = ':';

    date[15] = tm.tm_min / 10;
    date[16] = tm.tm_min % 10;
    date[17] = '\0';
    */

    date[4] = (tm.tm_mon + 1) / 10 + '0';
    date[5] = (tm.tm_mon + 1) % 10 + '0';
    date[6] = tm.tm_mday / 10 + '0';
    date[7] = tm.tm_mday % 10 + '0'; 
    date[8] = tm.tm_hour / 10 + '0';
    date[9] = tm.tm_hour % 10 + '0';
    date[10] = tm.tm_min / 10 + '0';
    date[11] = tm.tm_min % 10 + '0';
    date[12] = '\0';
    //printf("%s\n",date);
}


void toDateOffset2(char *date){
    //Solltat mit dem auskommentierten Code auch gehen, habe bei ein paar Sachen die Umwandlung in char falsch gedacht ( + '0')
    time_t now = time(NULL);
    struct tm tm = *localtime(&now);    
    int tmp, tmp1, tmp2, tmp3 ,tmp4;
    
    int tmpOffset1, tmpOffset2, tmpOffset3;

    tmp = tm.tm_year + 1900;
    tmp1 = tmp / 1000;
    tmp2 = (tmp - tmp1 * 1000) / 100;
    tmp3 = (tmp - tmp1 * 1000 - tmp2 * 100) / 10;
    tmp4 = (tmp - tmp1 * 1000 - tmp2 * 100 - tmp3 * 10);

    date[0] = tmp1 + '0';
    date[1] = tmp2 + '0';
    date[2] = tmp3 + '0';
    date[3] = tmp4 + '0';
    /*
    date[5] = ':';
    
    date[6] = (tm.tm_mon + 1) / 10 + '0';
    date[7] = (tm.tm_mon + 1) % 10 + '0';

    date[8] = ':';
    */

                   /* tempTimeInt = atoi(timeBufferStart);
                      printf("toDate: %s\n", timeBufferStart);
                      //Pfusch, hoffentlich passt die Logik
                      if(timeBufferStart[13] > 1 && timeBufferStart[12] == 2){
                          tempTimeInt =  tempTimeInt + 7800;
                      } 
                      else{
                        tempTimeInt = tempTimeInt + 200; 
                      }*/

    date[4] = (tm.tm_mon + 1) / 10 + '0';
    date[5] = (tm.tm_mon + 1) % 10 + '0';
    date[6] = tm.tm_mday / 10 + '0';
    //date[7] = tm.tm_mday % 10 + '0'; 
    //date[8] = tm.tm_hour / 10 + '0';
    //date[9] = tm.tm_hour % 10 + '0';
    date[10] = tm.tm_min / 10 + '0';
    date[11] = tm.tm_min % 10 + '0';
    date[12] = '\0';

    tmpOffset1 = tm.tm_mday % 10;
    tmpOffset2 = tm.tm_hour / 10;
    tmpOffset3 = tm.tm_hour % 10;

    if(tmpOffset3 > 1 && tmpOffset2 == 2){
        tmpOffset1++;
        tmpOffset2 = 0;
        tmpOffset3 = (tmpOffset3 + 2) % 10;
    }
    else{
        tmpOffset3 = tmpOffset3 + 2;
        if(tmpOffset3 > 9){
            tmpOffset3 = tmpOffset3 % 10;
            tmpOffset2++;
        }

    }
    date[7] = tmpOffset1 + '0';
    date[8] = tmpOffset2 + '0';
    date[9] = tmpOffset3 + '0';
/*


    date[9] = tm.tm_mday / 10 + '0';
    date[10] = tmpOffset1;

    date[11] = ':';
     
    date[12] = tmpOffset2;
    date[13] = tmpOffset3;

    date[14] = ':';

    date[15] = tm.tm_min / 10;
    date[16] = tm.tm_min % 10;
    date[17] = '\0';
*/
}

int parsePerson(char *text, struct person *toPerson) {

    int i = 0;                              //Zählt wo wir im Text sind
    int p = 0;                              //Zählt wie viele Personen wir haben
    char tempId [wordLength];               //Zum Umwandelmn von string to int 
    do{

        int k = 0;    
        do{            
            toPerson->name[k] = text[i];
            i++;
            k++;            
        } while(text[i] != ',');

        toPerson->name[k+1] = '\0';
        i++;
        k = 0;

        do{
            toPerson->number[k] = text[i];
            i++;
            k++;
        } while(text[i] != ',');

        toPerson->number[k+1] = '\0';
        i++;
        k = 0;

        do{
            tempId[k] = text[i];
            i++;
            k++;
        }while(text[i] != ',');

        i++;

        toPerson->id = atoi(tempId);

        addPersonList(toPerson);
        toPerson = toPerson->next;      
        p++;

    } while(text[i] != EOF); 

    return p;
}


/*! fn getRows
    @brief Liest aus dem Sting die Daten und speichert diese in einem Struct
    @param *text String aus dem der Text gelesen wird *toTable struct in dem die Daten eingelesen werden
    @return Anzahl der erstellten Personen
*/

int parseTable (char *text, struct table *toTable){
    int i = 0;          // Zählt wo wir im Text sind
    int t = 0;          // Zählt wie viele Tische eingelesen sind
    char toInt [wordLength];    // für atoi

    do{
        int k = 0;

        do{
            toInt[k] = text[i];
            i++;
            k++;
        }while(text[i] != ',');

        toTable->x = atoi(toInt);

        k = 0;
        i++;

        do{
            toInt[k] = text[i];
            i++;
            k++;
        }while(text[i] != ',');

        toTable->y = atoi(toInt);

        k = 0;
        i++;

        do{
           toInt[k] = text[i];
           i++;
           k++;
        }while(text[i] != ',');

        toTable->id = atoi(toInt);

        i++;
        t++;

        addTableList(toTable);
        toTable = toTable->next;

    } while(text[i]!=EOF);
    return t;
}

int parseBooking (char *text, struct booking *toBooking){
    int i = 0;
    int b = 0;
    char toInt [wordLength];

    do{
        int k = 0;
        
        do{
            toInt[k] = text[i];
            i++; 
            k++;
        }while(text[i] != ',');
        
        toBooking->idPerson = atoi(toInt);
        i++;
        k = 0;

        do{
            toInt[k] = text[i];
            i++; 
            k++;
        }while(text[i] != ',');

        toBooking->idTable = atoi(toInt);

        i++;
        k = 0;

        do{
            toBooking->startTime[k] = text[i];
            i++;
            k++;

        }while(text[i] != ',');
    
        toBooking->startTime[k + 1] = '\0';

        i++;
        k = 0;

        do{
            toBooking->endTime[k] = text[i];
            i++;
            k++;

        }while(text[i] != ',');
    
        toBooking->endTime[k+1] = '\0';

        i++;
        k = 0;


        addBookingList(toBooking);
        toBooking = toBooking->next;
        b++;

    } while(text[i] != EOF);

    
    return b;

}


int personToString(struct person *startPerson, char *text){
    int i = 0;
    int k = 0;
    char temp[nameLength];

    //do{
    while(startPerson){

        while(startPerson->name[k] != '\0'){
             text[i] = startPerson->name[k];
            i++; k++;
        }

        k = 0;
        text[i] = ',';
        i++;

        while(startPerson->number[k] != '\0'){
            text[i] = startPerson->number[k];
            i++; k++;
        }

        k = 0;
        text[i] = ',';
        i++;

        sprintf(temp, "%d" , startPerson->id);

        while(temp[k] != '\0'){
            text[i] =  temp[k];
            i++; k++;
        }
        k = 0;
        text[i] = 10;  //10 ist Ascii für Linefeed -> Zeilenumbruch
        i++;

        //if(startPerson->next !=  NULL){
            startPerson = startPerson->next;
        //}

    }
//    }while(startPerson->next != NULL);

    return i;
}


int tableToString(struct table *startTable, char *text){

    if(startTable == NULL){
        return -1;
    }

    int i = 0;
    int k = 0;
    char temp[nameLength];

    //do{
    while(startTable){
        //tostring(, temp);
        sprintf(temp, "%d" , startTable->x);
        while(temp[k] != '\0'){
            text[i] = temp[k];
            i++; k++;
        }

        text[i] = ',';
        i++; k = 0;
        
        //tostring(startTable->y, temp);
        sprintf(temp, "%d" , startTable->y);

        while(temp[k] != '\0'){
            text[i] =  temp[k];
            i++; k++;
        }
        text[i] = ',';
        i++; k = 0;
        
        sprintf(temp, "%d" , startTable->id);
        //tostring(startTable->id, temp);

        while(temp[k] != '\0'){
            text[i] = temp[k];
            i++; k++;
        }

        k = 0;
        text[i] = 10;
        i++;

        startTable = startTable->next;
    }
    //}while (startTable->next != NULL);
    return i;
}

int bookingToString(struct booking *startBooking, char *text){
    int i = 0;
    int k = 0;
    char temp[nameLength];

    do{

        sprintf(temp, "%d" , startBooking->idPerson);
        //tostring(startBooking->idPerson, temp);

        while(temp[k] != '\0'){
            text[i] = temp[k];
            i++; k++;
        }

        k = 0;
        text[i] = ',';
        i++;
        sprintf(temp, "%d" , startBooking->idTable);
        //tostring(startBooking->idTable, temp);

        while(temp[k] != '\0'){
            text[i] = temp[k];
            i++; k++;
        }

        k = 0;
        text[i] = ',';
        i++;

        while(startBooking->startTime[k] != '\0'){
            text[i] = startBooking->startTime[k];
            i++; k++;
        }

        k = 0;
        text[i] = ',';
        i++;

        while(startBooking->endTime[k] != '\0'){
            text[i] = startBooking->endTime[k];
            i++; k++;
        }

        k = 0;
        text[i] = 10;
        i++;

        if(startBooking->next != NULL){
            startBooking = startBooking->next;
        }

    }while(startBooking->next != NULL);

    return i;
}