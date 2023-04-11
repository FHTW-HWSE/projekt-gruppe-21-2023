# Datastructure

## Structs

```plantuml

struct table {
 int x;
 int y;
 int id;
}


struct person {
 char name [50];
 char telefonnumber [32];
 int id;
}


struct booking {
 struct person;
 struct table;
 date startTime;
 date endTime;
}

```

## CSVs

Pro Struct existiert eine einge CSV Datei.

Bei den Tischen wird pro Tisch eine Zeile gespeichert.

> BSP 1,0,0

Bei den Personen wird pre bekannter Person, die mal einen Tisch gebucht hat, eine Zeile gespeichert.

> BSP 1,Petar,06641234567

Bei den Buchungen wird pro Buchung eine Zeile erstellt mit einer Startzeit und einer Endezeit

> BSP #PersonenID,#TischID,yyyy:mm:dd:hh:mm,yyyy:mm:dd:hh:mm
