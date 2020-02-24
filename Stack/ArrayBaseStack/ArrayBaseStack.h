#ifndef ArrayBaseStack_h
#define ArrayBaseStack_h

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

#include <stdio.h>

typedef int Data;

typedef struct _arrayStack
{
    Data stackArr[STACK_LEN];
    int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack *pstack); // 스택의 초기화
int SIsEmpty(Stack *pstack); // 스택이 비어있는지 확인

void SPush(Stack *pstack, Data data); // push
Data SPop(Stack *pstack); // pop
Data SPeek(Stack *pstack); // peek

#endif /* ArrayBaseStack_h */
