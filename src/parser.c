// TODO Header ins Include File brinngen und aufräumen

#include main.h
#include parser.h

/*! fn getRows
    @brief Liest aus dem Sting die Daten und speichert diese in einem Struct
    @param *text String aus dem der Text gelesen wird *toPerson struct in dem die Daten eingelesen werden
    @return Anzahl der erstellten Personen
*/

int parsePerson(char *text, struct person *toPerson) {

    int i = 0;                              //Zählt wo wir im Text sind
    int p = 0;                              //Zählt wie viele Personen wir haben
    char tempId [wordLength ];                       //Zum Umwandelmn von string to int 
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
        } while(text[i] != ',')

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

        toPerson = toPerson->next;      //TODO Funktionsaufruf unten neue Person anlegen
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
        }while(text[i] != ’,’);

        toTable->x = atoi(toInt);

        k = 0;
        i++;

        do{
            toInt[k] = text[i];
            i++;
            k++;
        }while(text[i] != ’,’);

        toTable->y = atoi(toInt);

        k = 0;
        i++;

        do{
           toInt[k] = text[i];
           i++;
           k++;
        }while(text[i] != ’,’);

        toTable->id = atoi(toInt);

        i++;
        t++;

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
        }

        toBooking->idTable = atoi(toInt);


    }while(text[i] != EOF);


}