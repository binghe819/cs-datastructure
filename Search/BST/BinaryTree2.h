
#ifndef BinaryTree2_h
#define BinaryTree2_h

#include <stdio.h>

typedef int BTData;

typedef struct _btreenode
{
    BTData data;
    struct _btreenode *left;
    struct _btreenode *right;
}BTreeNode;

// 이진 트리의 노드를 동적할당(생성).
BTreeNode *MakeBTreeNode(void);

// 입력으로 들어온 노드의 데이터 값을 반환
BTData GetData(BTreeNode *bt);

// 입력으로 들어온 데이터를 하나의 이진 트리 노드에 대입.
void SetData(BTreeNode *bt, BTData data);

// 입력으로 들어온 이진 트리 노드의 왼쪽 서브 노드 반환
BTreeNode * GetLeftSubTree(BTreeNode *bt);

// 입력으로 들어온 이진 트리 노드의 오른쪽 서브 노드 반환
BTreeNode * GetRightSubTree(BTreeNode *bt);

// 입력으로 들어온 두 노드를 왼쪽 혹은 오른쪽 서브 노드로 대입.
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *mane, BTreeNode *sub);

typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);

// 왼쪽 혹은 오르쪽 자식 노드를 트리에서 제거, 제거된 노드의 주소 값 반환.
BTreeNode * RemoveLeftSubTree(BTreeNode *bt);
BTreeNode * RemoveRightSubTree(BTreeNode *bt);

// 메모리 소멸을 수반하지 않고 main의 왼쪽 혹은 오른쪽 자식 노드를 변경한다.
void ChangeLeftSubTree(BTreeNode *bt, BTreeNode *sub);
void ChangeRightSubTree(BTreeNode *bt, BTreeNode *sub);

#endif /* BinaryTree2_h */
