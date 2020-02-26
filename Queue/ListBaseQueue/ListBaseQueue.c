#include "ListBaseQueue.h"
#include <stdlib.h>

void QueueInit(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue *pq)
{
    if(pq->front == NULL) // front를 통해서 데이터를 빼는데 front에 null이 저장되어 있으면
        return TRUE;  // 큐가 텅 빈 것인 것과 같다.
    else
        return FALSE;
}

void Enqueue(Queue *pq, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if(QIsEmpty(pq)) // 첫 번째 노드의 추가라면
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else // 두 번째 노드의 추가라면 ( front는 움직이지 않고 rear만 움직인다. )
    {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

Data Dequeue(Queue *pq)
{
    Node *rNode;
    Data rdata;
    
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!\n");
        exit(-1);
    }
    
    rNode = pq->front;
    rdata = rNode->data;
    pq->front = rNode->next; // 삭제할 노드의 다음 노르를 front가 가리킴
    
    free(rNode);
    return rdata;
}


Data QPeek(Queue *pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!\n");
        exit(-1);
    }
    
    return pq->front->data;
}
