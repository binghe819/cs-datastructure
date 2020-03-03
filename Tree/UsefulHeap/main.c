#include <stdio.h>
#include "UsefulHeap.h"

// 우선 순위 비교함수
int DataPriorityComp(char ch1, char ch2)
{
    // 만약 ch2 - ch1 > 0, ch2가 우선
    //     ch2 - ch1 < 0, ch1가 우선
    //     ch2 - ch1 = 0, 동일
    return ch2 - ch1;
    // ch1 - ch2;
}

int main()
{
    Heap heap;
    HeapInit(&heap, DataPriorityComp); // 힙의 초기화
    
    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    printf("%c \n", HDelete(&heap));
    
    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    printf("%c \n", HDelete(&heap));
    
    while(!HIsEmpty(&heap))
        printf("%c \n", HDelete(&heap));
    
    return 0;
}

