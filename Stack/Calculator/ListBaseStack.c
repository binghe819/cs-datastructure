#include "ListBaseStack.h"
#include <stdlib.h>

// 리스트 기반의 스택은 일반적인 연결리스트와 비슷하다.
// 실제로 head만 가지고 있는 단방향 연결리스트는 메모리 구조상에서는 스택과 똑같이 볼 수도 있다.
void StackInit(Stack *pstack)
{
    pstack->head = NULL; // head를 NULL로 초기화
}

int SIsEmpty(Stack *pstack)
{
    if(pstack->head == NULL) // 스택에 데이터가 비어있다면 head가 null이므로
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack *pstack, Data data)
{
    Node *newNode = (Node*)malloc(sizeof(Node)); // 새 노드 생성
    newNode->data = data; // 데이터 저장
    
    newNode->next = pstack->head; // 새 노드가 최근에 추가된 노드를 가리킴.
    pstack->head = newNode; // head가 새 노드를 가리킴.
}

Data SPop(Stack *pstack)
{
    Data rdata;
    Node *rnode;
    
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    rnode = pstack->head; // 삭제할 노드의 주소 값을 임시 저장 (free용)
    rdata = rnode->data; // 삭제할 노드의 데이터를 임시 저장. (반환용)
    pstack->head = pstack->head->next; // 삭제할 노드의 다음 노드를 head가 가리킴
    
    free(rnode);
    return rdata;
}

Data SPeek(Stack *pstack)
{
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    return pstack->head->data;
}
