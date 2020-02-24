#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

void showEmp(Employee *data)
{
    printf("사번 : %d, 이름 : %s \n",data->EmpNum, data->name);
}

Employee* WhosNightDuty(List *plist, char *name, int day)
{
    Employee *data;
    int i;
    int numOfElement = LCount(plist);
    
    LFirst(plist, &data);
    
    if(strcmp((data->name), name) != 0)
    {
        for(i = 0; i < numOfElement-1; i++)
        {
            LNext(plist, &data);
            
            if(strcmp(data->name, name) == 0)
                break;
        }
        if(i >= numOfElement-1)
            return NULL;
    }
    
    for(i = 0; i < day; i++)
        LNext(plist, &data);
    
    return data;
}

int main() {
    
    // 리스트 생성 및 초기화
    List list;
    ListInit(&list);
    Employee *data;
    
    // 직원정보
    Employee *emp1 = (Employee*)malloc(sizeof(Employee));
    emp1->EmpNum = 1;
    emp1->name = "kim";
    
    Employee *emp2 = (Employee*)malloc(sizeof(Employee));
    emp2->EmpNum = 2;
    emp2->name = "lee";
    
    Employee *emp3 = (Employee*)malloc(sizeof(Employee));
    emp3->EmpNum = 3;
    emp3->name = "park";
    
    Employee *emp4 = (Employee*)malloc(sizeof(Employee));
    emp4->EmpNum = 4;
    emp4->name = "oh";
    
    // 직원 정보 리스트에 저장
    LInsert(&list, emp1);
    LInsert(&list, emp2);
    LInsert(&list, emp3);
    LInsert(&list, emp4);
    
    data = WhosNightDuty(&list, "kim", 3);
    showEmp(data);
    
    
    
    
    return 0;
}
