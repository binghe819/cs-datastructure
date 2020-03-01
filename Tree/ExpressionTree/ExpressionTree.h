
#ifndef ExpressionTree_h
#define ExpressionTree_h

#include "BinaryTree.h"

// 이 함수는 후위 표기법의 수식을 문자열의 형태로 받아서, 수식 트리의 루트 노드의 주소 값을 반환한다.
BTreeNode * MakeExpTree(char exp[]);
// 인자로 수식 트리의 수식을 계산하여 그 결과를 반환한다.
int EvaluateExpTree(BTreeNode *bt);

// 수식 트리 검증을 위해서 각각의 표기법들을 출력하는 함수.
void ShowPrefixTypeExp(BTreeNode *bt); // 전위 표기법 기반 출력
void ShowInfixTypeExp(BTreeNode *bt); // 중위 표기법 기반 출력
void ShowPostfixTypeExp(BTreeNode *bt); // 후위 표기법 기반 출력

#endif /* ExpressionTree_h */
