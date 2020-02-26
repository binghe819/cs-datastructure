#include <stdio.h>
#include "CircularQueue.h"

int main(){
    
    // Queue의 생성 및 초기화
    QUEUE q;
    QueueInit(&q);
    
    // 데이터 넣기
    Enqueue(&q, 1); Enqueue(&q, 2);
    Enqueue(&q, 3); Enqueue(&q, 4);
    Enqueue(&q, 5); Enqueue(&q, 6);
    
    // 데이터 꺼내기
    while(!QIsEmpty(&q))
        printf("%d\t",Dequeue(&q));
    
    return 0;
}

