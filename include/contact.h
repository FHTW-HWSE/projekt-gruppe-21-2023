#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nameLength 50
#define telNumLen 25

typedef struct 
{
    char name[nameLength];
    char number[telNumLen];
    int id;
}Contact;
void addContact(Contact* contact);
