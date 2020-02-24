#include <stdio.h>
#include "DBLinkedList.h"


int main(){
    
    List list;
    Data data;
    ListInit(&list);
    
    // 데이터 저장
    LInsert(&list, 1); LInsert(&list, 2);
    LInsert(&list, 3); LInsert(&list, 4);
    LInsert(&list, 5); LInsert(&list, 6);
    LInsert(&list, 7); LInsert(&list, 8);
    
    // 저장된 데이터 조회
    if(LFirst(&list, &data))
    {
        printf("%d\t",data);
        while(LNext(&list, &data))
            printf("%d\t",data);
        
        printf("\n");
    }
    
    // 2의 배수 전부 삭제
    if(LFirst(&list, &data))
    {
        if(data %2 == 0)
            LRemove(&list);
        while(LNext(&list, &data))
        {
            if(data %2 == 0)
                LRemove(&list);
        }
    }
    
    // 데이터 다시 조회
    if(LFirst(&list, &data))
    {
        printf("%d\t",data);
        while(LNext(&list, &data))
            printf("%d\t",data);
        
        printf("\n");
    }
    
    return 0;
}

