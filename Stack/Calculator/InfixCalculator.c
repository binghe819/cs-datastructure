#include <string.h>
#include <stdlib.h>
#include "InfixToPositfix.h"
#include "PostCalculator.h"

// 중위 표기법의 수식을 입력하면 계산해주는 코드 ( InfixToPostfix와 PostCalculator를 합친 것 )

int EvalInfixExp(char exp[])
{
    int len = strlen(exp);
    int ret;
    char *expcpy = (char*)malloc(len+1); // 문자열 저장공간
    strcpy(expcpy, exp); // exp를 expcpy에 복사
    
    ConvToRPNExp(expcpy); // 후위 표기법의 수식으로 변환
    ret = EvalRPNExp(expcpy); // 변환된 수식의 계산
    
    free(expcpy); // 문자열 저장공간 해제
    return ret; // 반환.
}
