#include "Person.h"
#include <stdlib.h>
#include <string.h>

int GetSSN(Person *p)
{
    return p->ssn;
}

void ShowPersonInfo(Person *p)
{
    printf("주민번호 : %d\n", p->ssn);
    printf("이름 : %s\n", p->name);
    printf("주소 : %s\n", p->addr);
}

Person * MakePersonData(int ssn, char * name, char * addr)
{
    Person *newPerson = (Person*)malloc(sizeof(Person));
    newPerson->ssn = ssn;
    strcpy(newPerson->name, name);
    strcpy(newPerson->addr, addr);
    return newPerson;
}
