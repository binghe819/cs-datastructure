#include <stdlib.h>
#include <stdio.h>
#include "Deque.h"


void DequeInit(Deque *pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque *pdeq)
{
    if(pdeq->head == NULL) // head가 비어있으면 비어있는 덱.
        return TRUE;
    else
        return FALSE;
}

void DQAddFirst(Deque *pdeq, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->next = pdeq->head;
    
    if(DQIsEmpty(pdeq))
        pdeq->tail = newNode;
    else
        pdeq->head->prev = newNode;
    
    newNode->prev = NULL;
    pdeq->head = newNode;
}

void DQAddLast(Deque *pdeq, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->prev = pdeq->tail;
    
    if(DQIsEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;
    
    newNode->next = NULL;
    pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque *pdeq)
{
    Node *rNode= pdeq->head;
    Data rData = rNode->data;
    
    if(DQIsEmpty(pdeq)) // 덱이 비어있다면
    {
        printf("Queue Memory Error!\n");
        exit(-1);
    }
    
    pdeq->head = rNode->next;
    
    free(rNode);
    
    if(pdeq->head == NULL) // 만약 삭제하는 요소(Dequeue)가 마지막 요소라면
        pdeq->tail = NULL;
    else
        pdeq->head->prev = NULL;
    
    return rData;
}

Data DQRemoveLast(Deque *pdeq)
{
    Node *rNode = pdeq->tail;
    Data rData = rNode->data;
    
    if(DQIsEmpty(pdeq)) // 덱이 비어있다면
    {
        printf("Queue Memory Error!\n");
        exit(-1);
    }
    
    pdeq->tail = rNode->prev;
    free(rNode);
    
    if(pdeq->tail == NULL) // 만약 삭제하는 요소(Dequeue)가 마지막 요소라면
        pdeq->head = NULL;
    else
        pdeq->tail->next = NULL;
    
    return rData;
}

Data DQGetFirst(Deque *pdeq)
{
    if(DQIsEmpty(pdeq)) // 덱이 비어있다면
    {
        printf("Queue Memory Error!\n");
        exit(-1);
    }
    
    return pdeq->head->data;
}
Data DQGetLast(Deque *pdeq)
{
    if(DQIsEmpty(pdeq)) // 덱이 비어있다면
    {
        printf("Queue Memory Error!\n");
        exit(-1);
    }
    
    return pdeq->tail->data;
}
