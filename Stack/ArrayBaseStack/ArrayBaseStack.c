#include "ArrayBaseStack.h"

void StackInit(Stack *pstack)
{
    pstack->topIndex = -1; // 빈 상태를 의미.
}

int SIsEmpty(Stack *pstack)
{
    if(pstack->topIndex == -1) // 스택이 비어있다면.
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data)
{
    (pstack->topIndex)++; // 데이터 추가를 위한 인덱스 값 증가
    pstack->stackArr[pstack->topIndex] = data; // 데이터 저장
}

// 스택에서 꺼낸다는 의미는 삭제와 반환의 의미가 함께 담겨있다.
Data SPop(Stack *pstack)
{
    int rIdx;
    
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory error!");
        exit(-1);
    }
    
    rIdx = pstack->topIndex; // 삭제할 데이터가 저장된 인덱스 값 저장.
    (pstack->topIndex)--; // topIndex 하나 감소.
    
    return pstack->stackArr[rIdx]; // 삭제 데이터 반환.
}

Data SPeek(Stack *pstack)
{
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory error!");
        exit(-1);
    }
    
    return pstack->stackArr[pstack->topIndex]; // 맨 위에 저장된 데이터 반환.
}
