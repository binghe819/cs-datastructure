#include "CircularQueue.h"
#include <stdio.h>

void QueueInit(QUEUE *pq) // 텅 빈 경우 front와 rear은 동일 위치 가리킴
{
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(QUEUE *pq)
{
    if(pq->front == pq->rear) // 큐가 텅 비었다면
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos)
{
    if(pos == QUE_LEN-1) // 배열의 마지막 요소의 인덱스 값이라면 ( 회전을 해야되는 상황이라면 )
        return 0;
    else
        return pos+1;
}

void Enqueue(QUEUE *pq, Data data)
{
    if(NextPosIdx(pq->rear) == pq->front) // 큐가 꽉 찼다면
    {
        printf("Queue Memory Error!\n");
        exit(-1);
    }
    
    pq->rear = NextPosIdx(pq->rear); // rear을 한칸 이동
    pq->queArr[pq->rear] = data; //rear이 가리키는 곳에 데이터 저장
}

Data Dequeue(QUEUE *pq)
{
    if(QIsEmpty(pq)) // 큐가 텅 비어있다면
    {
        printf("Queue Memory Error!\n");
        exit(-1);
    }
    
    pq->front = NextPosIdx(pq->front); // front를 다음 인덱스로 이동
    return pq->queArr[pq->front]; // front가 가리키는 데이터 반환
    // 삭제를 안하는 이유는 어차피 덮어씌우는 형식으로 하기 때문이다.
}

Data QPeek(QUEUE *pq)
{
    if(QIsEmpty(pq)) // 큐가 텅 비어있다면
    {
        printf("Queue Memory Error!\n");
        exit(-1);
    }
    
    return pq->queArr[NextPosIdx(pq->front)];
}
