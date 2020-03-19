#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
    return k % 100;
}

int main()
{
    Table myTBL;
    Person * np;
    Person * sp;
    Person * rp;
    
    TBLInit(&myTBL, MyHashFunc);
    
    // 데이터 입력
    np = MakePersonData(20120003, "kim", "seoul");
    TBLInsert(&myTBL, GetSSN(np), np);
    
    np = MakePersonData(20120012, "lee", "jeju");
    TBLInsert(&myTBL, GetSSN(np), np);
    
    np = MakePersonData(20120049, "park", "seoul");
    TBLInsert(&myTBL, GetSSN(np), np);
    
    // 데이터 탐색
    sp = TBLSearch(&myTBL, 20120003);
    if(sp != NULL)
        ShowPersonInfo(sp);
    
    sp = TBLSearch(&myTBL, 20120012);
    if(sp != NULL)
        ShowPersonInfo(sp);
    
    sp = TBLSearch(&myTBL, 20120049);
    if(sp != NULL)
        ShowPersonInfo(sp);
    
    // 데이터 삭제
    rp = TBLDelete(&myTBL, 20120003);
    if(rp != NULL)
        free(rp);
    
    rp = TBLDelete(&myTBL, 20120012);
    if(rp != NULL)
        free(rp);
    
    rp = TBLDelete(&myTBL, 20120049);
    if(rp != NULL)
        free(rp);
    
    return 0;
}

