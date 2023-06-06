// TODO Header ins Include File brinngen und aufräumen

#include "parser.h"
#include "structhandeling.h"

/*! fn getRows
    @brief Liest aus dem Sting die Daten und speichert diese in einem Struct
    @param *text String aus dem der Text gelesen wird *toPerson struct in dem die Daten eingelesen werden
    @return Anzahl der erstellten Personen
*/

char *toDate(char *date){
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

    return date;
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

        addPerson(toPerson);
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

        addTable(toTable);
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
    
        toBooking->startTime[k+1] = '\0';

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


        addBooking(toBooking);
        toBooking = toBooking->next;
        b++;

    } while(text[i] != EOF);

    
    return b;

}