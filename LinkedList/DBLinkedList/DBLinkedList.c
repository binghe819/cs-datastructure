#include "DBLinkedList.h"
#include <stdlib.h>

void ListInit(List *plist)
{
    plist->head = NULL;
    plist->numOfData = 0;
}

void LInsert(List *plist, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    // 자세한 코드
//    if(plist->head == NULL)
//    {
//        plist->head = newNode; // head가 새 노드를 가리킴.
//        newNode->prev = NULL; // 새 노드의 prev를 null로 초기화.
//        newNode->next = plist->head; // 새 노드의 next를 null로 초기화.
//    }
//
//    plist->head->prev = newNode; // 기존 노드가 새 노드를 가리키게 한다.
//    newNode->next = plist->head; // 새 노드가 기존 노드를 가리키게 한다.
//    newNode->prev = NULL;
//    plist->head = newNode;
    
    // 간단화
    newNode->next = plist->head;
    if(plist->head != NULL)
        plist->head->prev = newNode; // 두 번째 이후의 노드를 추가할 때만 실행
    
    newNode->prev = NULL;
    plist->head = newNode;
    
    (plist->numOfData)++;
}

int LFirst(List *plist, Data *data)
{
    if(plist->head == NULL)
        return FALSE;
    
    plist->cur = plist->head;
    *data = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, Data *data)
{
    if(plist->cur->next == NULL)
        return FALSE;
    
    plist->cur = plist->cur->next;
    *data = plist->cur->data;
    return TRUE;
}

int LPrevious(List *plist, Data *data)
{
    if(plist->cur->prev == NULL)
        return FALSE;
    
    plist->cur = plist->cur->prev;
    *data = plist->cur->data;
    return TRUE;
}

int LCount(List *plist);
