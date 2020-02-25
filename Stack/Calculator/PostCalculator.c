#include "PostCalculator.h"
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

// 후위 표기법의 수식을 계산

int EvalRPNExp(char exp[])
{
    Stack stack;
    StackInit(&stack);
    
    int explen = strlen(exp);
    int i;
    char tok, op1, op2;
    
    for(i = 0; i < explen; i++)
    {
        tok = exp[i];
        if(isdigit(tok)) // 숫자면
            SPush(&stack, tok-'0'); // 정수면 숫자(아스키코드 참고)로 변환 후 스택에 push
        else // 연산자면
        {
            op2 = SPop(&stack); // 스택에서 두 번째 연산자 꺼내기.
            op1 = SPop(&stack); // 스택에서 첫 번째 연산자 꺼내기.
            
            switch (tok)
            {
                case '+':
                    SPush(&stack, op1+op2);
                    break;
                case '-':
                    SPush(&stack, op1-op2);
                    break;
                case '*':
                    SPush(&stack, op1*op2);
                    break;
                case '/':
                    SPush(&stack, op1/op2);
                    break;
            }
        }
    }
    return SPop(&stack); // 마지막 연산 결과를 스택에서 꺼내어 반환.
}
