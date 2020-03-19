#ifndef Person_h
#define Person_h

#include <stdio.h>

#define STR_LEN 50

typedef struct _person
{
    int ssn; // 주민등록번호
    char name[STR_LEN];
    char addr[STR_LEN];
} Person;

int GetSSN(Person *p);
void ShowPersonInfo(Person *p);
Person * MakePersonData(int ssn, char * name, char * addr);

#endif /* Person_h */
