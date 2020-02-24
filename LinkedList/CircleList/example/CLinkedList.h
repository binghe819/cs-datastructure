#ifndef CLinkedList_h
#define CLinkedList_h

#include <stdio.h>
#include "Employee.h"

#define TRUE 1
#define FALSE 0

//typedef int LData;
typedef Employee *LData;

typedef struct __node
{
    LData data;
    struct __node *next;
} Node;

typedef struct __CircleLinkedList
{
    Node *tail;
    Node *cur;
    Node *before;
    int numOfData;
} CList;

typedef CList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data); // 꼬리에 추가
void LInsertFront(List *plist, LData data); // 머리에 추가

int LFirst(List *plist, LData *data);
int LNext(List *plist, LData *data);

LData LRemove(List *plist);
int LCount(List *plist);

#endif /* CLinkedList_h */
