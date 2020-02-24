#include "DBLinkedList.h"
#include <stdlib.h>

void ListInit(List *plist)
{
    // 더미노드 추가 ( 헤더와 꼬리 )
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->prev = NULL;
    
    plist->tail = (Node*)malloc(sizeof(Node));
    plist->tail->next = NULL;
    
    // 처음 리스트를 초기화하는 것이기 때문에 더미끼리 연결
    plist->head->next = plist->tail;
    plist->tail->prev = plist->head;
    
    plist->numOfData=0;
}

void LInsert(List *plist, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    // 만약 아무 데이터가 없다면 ( 헤더와 꼬리가 서로 연결되어 있다면 )
//    if(plist->head->next == plist->tail && plist->tail->prev == plist->head)
//    {
//        plist->head->next = newNode;
//        newNode->prev = plist->head;
//
//        plist->tail->prev = newNode;
//        newNode->next = plist->tail;
//    }
//    else
//    {
//        newNode->prev = plist->tail->prev;
//        plist->tail->prev->next = newNode;
//
//        newNode->next = plist->tail;
//        plist->tail->prev = newNode;
//    }
    
    // 더미노드가 있으므로 조건문을 사용하지 않고 데이터 추가가 가능하다.
    newNode->prev = plist->tail->prev;
    plist->tail->prev->next = newNode;

    newNode->next = plist->tail;
    plist->tail->prev = newNode;
    
    (plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
    // 리스트 안에 데이터가 없다면 ( 헤더와 꼬리가 서로 연결되어 있다면 )
    if(plist->head->next == plist->tail)
        return FALSE;
    
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, Data *pdata)
{
    // 더이상 뒤로 데이터가 없다면
    if(plist->cur->next == plist->tail)
        return FALSE;
    
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

Data LRemove(List *plist)
{
    Node *rpos = plist->cur;
    Data rdata = rpos->data;
    
    // 삭제하기 위한 노드간의 연결 재조정.
    rpos->prev->next = rpos->next;
    rpos->next->prev = rpos->prev;
    
    plist->cur = rpos->prev; // cur의 위치 재조정.
    
    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List *plist)
{
    return plist->numOfData;
}
