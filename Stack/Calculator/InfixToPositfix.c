#include <stdlib.h>
#include "ListBaseStack.h"
#include <ctype.h>
#include <string.h>

// 중위 표기법을 후위 표기법으로 바꾸는 코드.

// 연산자의 연산 우선순위 정보를 반환한다.
int GetOpPrec(char op)
{
    switch (op)
    {
        case '*':
        case '/':
            return 5; // 가장 높은 연산의 우선순위
        case '+':
        case '-':
            return 3;
        case '(':
            return 1; // 가장 낮은 연산의 우선순위
    }
    return -1; // 등록되지 않은 연산자임을 알림
}

int WhoPrecOp(char op1, char op2)
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);
    
    if(op1Prec > op2Prec) // op1의 우선순위가 더 높다면
        return 1;
    else if(op1Prec < op2Prec) // op2의 우선순위가 더 높다면
        return -1;
    else
        return 0; // op1과 op2의 우선순위가 같다면
}

void ConvToRPNExp(char exp[])
{
    // 연산자 담을 스택 공간.
    Stack stack;
    StackInit(&stack);
    
    // 결과 내보낼 배열 공간.
    int expLen = strlen(exp); // 입력으로 들어온 배열의 길이
    char * convExp = (char*)malloc(sizeof(char)*expLen+1); // 변환된 결과를 담을 공간.
    
    int i, idx = 0;
    char tok, popOp;
    
    memset(convExp, 0, sizeof(char)*expLen+1); // 할당된 배열을 0으로 초기화
    
    for(i = 0; i < expLen; i++)
    {
        tok = exp[i]; // 전달된 배열에서 문자 하나씩 빼기
        if(isdigit(tok)) // 만약 숫자면
            convExp[idx++] = tok; // 변환될 배열에 넣고, idx 1나 추가.
        else // 연산자면
        {
            switch (tok)
            {
                case '(': // 여는 소괄호면
                    SPush(&stack, tok); // 스택에 쌓는다.
                    break;
                case ')':  // 닫는 소괄호면
                    while(1)
                    {
                        popOp = SPop(&stack); // 스택에서 연산자를 꺼낸다.
                        if(popOp == '(') // 연산자 (을 만날 때 까지
                            break;
                        convExp[idx++] = popOp; // 변환된 내용을 담는 배열에 저장한다.
                    }
                    break;
                case '+': case'-':
                case '*': case'/':
                    // 스택이 비어 있지 않으며, 스택에서 꺼낸 값이랑 현재 뽑은 연산자랑 우선순위 비교. ( 만약 스택에서 뽑은 값이 더 우선순위가 크다면 )
                    while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
                    {
                        popOp = SPop(&stack); // 스택에서 맨 위에 연산자를 뺀다. ( * )
                        convExp[idx++] = popOp; // 변환된 내용을 담는 배열에 저장한다.
                    }
                    SPush(&stack, tok); // 현재 뽑은 연산자를 스택에 쌓는다. ( + )
            }
        }
    }
    
    while(!SIsEmpty(&stack)) // 스택에 남아 있는 모든 연산자를
        convExp[idx++] = SPop(&stack); // 변환된 내용을 담는 배열에 저장.
    
    strcpy(exp, convExp); // 변환된 수식을 exp에 복사.
    free(convExp); // 소멸.
}
