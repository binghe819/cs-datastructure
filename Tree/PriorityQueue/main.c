#include <stdio.h>
#include "UsefulHeap.h"
#include "PriorityQueue.h"

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
    PQueue pq;
    PQueueInit(&pq, DataPriorityComp);
    
    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    printf("%c \n", PDequeue(&pq));
    
    PEnqueue(&pq, 'A');
    PEnqueue(&pq, 'B');
    PEnqueue(&pq, 'C');
    printf("%c \n", PDequeue(&pq));
    
    while(!PQIsEmpty(&pq))
        printf("%c \n", PDequeue(&pq));
    
    return 0;
}

