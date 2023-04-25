# Project Guidelines

## Benennung der Variablen

Die Variablen sind in der englischen Sprache geschrieben. Desweiteren sollten die Variablen keine Sonderzeichen und Zahlen erhalten.Falls die Variable aus zwei Wörter bestehen, wird der CamelCase-Schreibweise verwendet.Variablen-Namen beginnen mit einem Kleinbuchstaben.

_Beispiel_: Addition zweier Zahlen:
- 1 Summand:firstSummand
- 2 Summand:secondSummand
- Summe: sum

## Bennung der Funktionen:
Es gelten die gleichen Regeln wie oben:
- Es wird in Englisch verfasst
- Keine Zahlen oder Sonderzeichen
- Falls die Name der Funktion aus mehrere Wörter besteht:CamelCase
- Muss anhand der Name klar sein, was die Funktion tun soll
Beispiel: int addition(int firstSum,int secondSum)

## Unit-Tests Bennenung

Es gelten folgende Regeln bei Bennenung von Unit-Test:
- Es wird in Englisch verfasst
- Keine Zahlen oder Sonderzeichen
- Falls die Name der Funktion aus mehrere Wörter besteht:CamelCase
- Muss anhand der Name klar sein, was die Funktion tun soll
- Basiert auf das Given-When-Then Prinzip

## Dokumentation vom Code

- Ist auf Englisch,
- Basiert auf die Doxygen-Dokumentation

## Ordner Struktur

In den folgenden Ordner befinden sich folgende  Datein:

| Ordner | Arten von Dateien |
| :---: | :---: | 
| dummy | Dieser Ordner dient zur Überprüfung ob das Hochladne bei GitHub funktionier | 
| doc | Dort werden Dokumentation bzw. Überlegungen in Form eines Markdown-Files angezeigt |
| src | dort wird der ganze Code gespeichert |
| test | dort werden die ganzen Unit-Test gespeichert |
|database| dort befinnden sich die CSV-Datei |

 
## Datei-Guideline:

/src
- booking.c
- contact.c
- filehandeling.c
- main.c
- parser.c
- restaurant.c

/doc
- datastructure.c
- projectGuidlines.c

/test
-bookingTest.c
-contactTest.c
-restaurantTest.c
-filehandelingTest.c

/database
-booking.csv
-restaurant.csv
-contact.csv
