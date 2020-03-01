#ifndef ListBaseStack_h
#define ListBaseStack_h

#include "BinaryTree.h"
#define TRUE 1
#define FALSE 0

typedef BTreeNode *Data;

typedef struct _node
{
    struct _node *next;
    Data data; // Data = *BTreeNode ( 중요! )
} Node;

typedef struct _liststack
{
    Node *head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack); // 스택의 초기화
int SIsEmpty(Stack *pstack); // 스택이 비어있는지 확인

void SPush(Stack *pstack, Data data); // push
Data SPop(Stack *pstack); // pop
Data SPeek(Stack *pstack); // peek

#endif /* ListBaseStack_h */
