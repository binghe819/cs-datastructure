#include <stdio.h>
#include "ArrayList.h"

int main(){
    
    List list;
    LData data;
    
    // 리스트 초기화
    ListInit(&list);
    
    // 리스트에 데이터 저장
    for(int i = 1; i < 10; i++)
        LInsert(&list, i);
    
    // 데이터 출력
    if(LFirst(&list, &data))
    {
        printf("전체 데이터 출력 : %d",data);
        
        while(LNext(&list, &data))
        {
            printf(" %d",data);
        }
        printf("\n\n");
    }
    
    // 2와 3의 배수 데이터 삭제
    if(LFirst(&list, &data))
    {
        if(data % 2 == 0 || data % 3 == 0)
            LRemove(&list);
        
        while(LNext(&list, &data))
        {
            if(data % 2 == 0 || data % 3 == 0)
            LRemove(&list);
        }
    }
    
    // 삭제 후 데이터 출력
    if(LFirst(&list, &data))
    {
        printf("전체 데이터 출력 : %d",data);
        
        while(LNext(&list, &data))
        {
            printf(" %d",data);
        }
        printf("\n\n");
    }
    
    return 0;
}

