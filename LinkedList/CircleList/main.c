#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

int main() {
    
    // 리스트 생성 및 초기화
    List list;
    int data;
    ListInit(&list);
    
    // 데이터 삽입
    LInsert(&list, 3);
    LInsert(&list, 4);
    LInsert(&list, 5);
    LInsert(&list, 6);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);
    
    // 모든 데이터 출력 ( 3회 )
    if(LFirst(&list, &data))
    {
        printf("%d\t",data);
        for(int i = 0; i < LCount(&list)*3-1; i++)
        {
            if(LNext(&list, &data))
            printf("%d\t",data);
        }
    }
    
    // 2의 배수 찾아서 모두 삭제
    int nodeNum = LCount(&list);
    
    if(nodeNum != 0)
    {
        LFirst(&list, &data);
        if(data %2 == 0)
            LRemove(&list);
        
        for(int i = 0; i < nodeNum; i++)
        {
            LNext(&list, &data);
            if(data %2 == 0)
                LRemove(&list);
        }
    }
    
    // 전체 데이터 한번 출력
    printf("\n");
    if(LFirst(&list, &data))
    {
        printf("%d\t",data);
        for(int i = 0; i < LCount(&list)-1; i++)
        {
            if(LNext(&list, &data))
            printf("%d\t",data);
        }
    }
    
    return 0;
}
