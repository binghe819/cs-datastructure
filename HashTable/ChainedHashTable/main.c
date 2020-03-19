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
    np = MakePersonData(900254, "kim", "seoul");
    TBLInsert(&myTBL, GetSSN(np), np);
    
    np = MakePersonData(900139, "lee", "jeju");
    TBLInsert(&myTBL, GetSSN(np), np);
    
    np = MakePersonData(900827, "park", "seoul");
    TBLInsert(&myTBL, GetSSN(np), np);
    
    // 데이터 탐색
    sp = TBLSearch(&myTBL, 900254);
    if(sp != NULL)
        ShowPersonInfo(sp);
    
    sp = TBLSearch(&myTBL, 900139);
    if(sp != NULL)
        ShowPersonInfo(sp);
    
    sp = TBLSearch(&myTBL, 900827);
    if(sp != NULL)
        ShowPersonInfo(sp);
    
    // 데이터 삭제
    rp = TBLDelete(&myTBL, 900254);
    if(rp != NULL)
        free(rp);
    
    rp = TBLDelete(&myTBL, 900139);
    if(rp != NULL)
        free(rp);
    
    rp = TBLDelete(&myTBL, 900827);
    if(rp != NULL)
        free(rp);
    
    return 0;
}

