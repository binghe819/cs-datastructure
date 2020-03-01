#include "ExpressionTree.h"
#include "ListBaseStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

BTreeNode * MakeExpTree(char exp[])
{
    Stack stack;
    BTreeNode *pnode;
    
    int expLen = strlen(exp);
    int i = 0;
    
    StackInit(&stack);
    
    for(i = 0; i < expLen; i++)
    {
        pnode = MakeBTreeNode();
        
        if(isdigit(exp[i])) // 피연산자(숫자)라면
        {
            pnode->data = exp[i]-'0'; // 문자를 숫자로 바꿔서 트리노드에 입력.
        }
        else // 연산자라면
        {
            MakeRightSubTree(pnode, SPop(&stack));
            MakeLeftSubTree(pnode, SPop(&stack));
            pnode->data = exp[i];
        }
        
        SPush(&stack, pnode);
    }
    
    return SPop(&stack);
}

int EvaluateExpTree(BTreeNode *bt)
{
    int op1, op2;
    
    // 단말 노드라면 ( 단말 노드 : 자식 노드가 없는 노드 )
    if(GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
        return GetData(bt);
    
    op1 = EvaluateExpTree(GetLeftSubTree(bt));
    op2 = EvaluateExpTree(GetRightSubTree(bt));
    
    switch (GetData(bt))
    {
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
    }
    return 0;
}

void ShowNodeData(int data)
{
    if( 0 <= data && data <= 9) // 숫자라면
        printf("%d\t",data);
    else
        printf("%c\t",data);
}

void ShowPrefixTypeExp(BTreeNode *bt)
{
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode *bt)
{
    InorderTraverse(bt, ShowNodeData);
}
void ShowPostfixTypeExp(BTreeNode *bt)
{
    PostorderTraverse(bt, ShowNodeData);
}
