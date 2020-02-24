#include <stdlib.h>
#include "CLinkedList.h"


void ListInit(List *plist)
{
    plist->tail = NULL;
    plist->before = NULL;
    plist->cur = NULL;
    plist->numOfData = 0;
}

// 꼬리에 추가
void LInsert(List *plist, LData data)
{
    // 새로운 노드 추가.
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data; // 새로운 노드에 데이터 추가.
    
    if(plist->tail == NULL)
    {
        plist->tail = newNode; // tail이 새 노드를 가리킴.
        newNode->next = newNode; // 새 노드 자신을 가리킨다.
    }
    else
    {
        // 노드 연결 ( 꼬리에 연결 ) 머리에 추가하는 것과 코드가 같다!
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        
        // 꼬리를 새로운 노드로 변경 ( 머리에 추가하는 것과 유일한 차이 점 )
        plist->tail = newNode;
    }
    
    (plist->numOfData)++;
}

// 머리에 추가
void LInsertFront(List *plist, LData data)
{
    // 새로운 노드 추가
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if(plist->tail==NULL)
    {
        plist->tail = newNode; // tail이 새 노드를 가리킴.
        newNode->next = newNode; // 새 노드 자신을 가리킨다.
    }
    else
    {
        // 노드 연결 ( 머리에 연결 )
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }
    
    (plist->numOfData)++;
}

int LFirst(List *plist, LData *data)
{
    if(plist->tail == NULL) // 저장된 노드가 없다면
        return FALSE;
    
    plist->cur = plist->tail->next; // cur은 머리
    plist->before = plist->tail; // before은 꼬리를 가리킨다.
    
    *data = plist->cur->data;
    return TRUE;
}

int LNext(List *plist, LData *data)
{
    if(plist->tail == NULL)
        return FALSE;
    
    // 리스트의 끝을 검사하는 코드가 없고, 계속해서 반복된다.
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    
    *data = plist->cur->data;
    return TRUE;
}

LData LRemove(List *plist)
{
    Node *rpos = plist->cur; // 삭제될 노드
    LData rdata = rpos->data; // 삭제될 노드의 데이터
    
    if(rpos == plist->tail) // 삭제 대상을 tail이 가리킨다면
    {
        if(plist->tail == plist->tail->next) // 그리고 마지막 남은 노드라면
            plist->tail = NULL;
        else
            plist->tail = plist->before;
    }
    
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    
    free(rpos);
    (plist->numOfData)--;
    return rdata;
}


int LCount(List *plist)
{
    return plist->numOfData;
}
