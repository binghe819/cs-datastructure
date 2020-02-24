#ifndef DBLinkedList_h
#define DBLinkedList_h

#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct __node
{
    Data data;
    struct __node *next;
    struct __node *prev;
} Node;

typedef struct _DLinkedList
{
    Node *head;
    Node *cur;
    int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, Data data);

int LFirst(List *plist, Data *data);
int LNext(List *plist, Data *data);
int LPrevious(List *plist, Data *data);

int LCount(List *plist);

#endif /* DBLinkedList_h */
