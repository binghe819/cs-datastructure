#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int WhoIsPrecede(int d1, int d2)
{
    if(d1 < d2)
        return 0; // d1이 정렬 순서상 앞선다.
    else
        return 1; // d2가 정렬 순서상 앞서거나 같다.
}

int main(){
    
    List list;
    int data;
    ListInit(&list);
    SetSortRule(&list, WhoIsPrecede); // 정렬의 기준을 등록한다.
    
    // 5개의 데이터 저장
    LInsert(&list, 11);
    LInsert(&list, 55);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);
    
    // 저장된 데이터의 전체 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));
    
    if(LFirst(&list, &data))
    {
        printf("%d \n", data);
        
        while(LNext(&list, &data))
        {
            printf("%d \n", data);
        }
    }
    
    // 숫자 22을 검색하여 모두 삭제
    if(LFirst(&list, &data))
    {
        if(data == 22)
            LRemove(&list);
        while(LNext(&list, &data))
        {
            if(data == 22)
                LRemove(&list);
        }
    }
    
    // 삭제 후 남아 있는 데이터 전체 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));
    if(LFirst(&list, &data))
    {
        printf("%d \n", data);
        
        while(LNext(&list, &data))
        {
            printf("%d \n", data);
        }
    }
    
    return 0;
}
