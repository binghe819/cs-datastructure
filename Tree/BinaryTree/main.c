#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(int data);

int main()
{
    // 노드 생성
    BTreeNode *bt1 = MakeBTreeNode();
    BTreeNode *bt2 = MakeBTreeNode();
    BTreeNode *bt3 = MakeBTreeNode();
    BTreeNode *bt4 = MakeBTreeNode();
    BTreeNode *bt5 = MakeBTreeNode();
    BTreeNode *bt6 = MakeBTreeNode();
    
    // 데이터 저장
    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    SetData(bt6, 6);
    
    // 연결
    MakeLeftSubTree(bt1, bt2); // bt2를 bt1의 왼쪽 자식 노드로
    MakeRightSubTree(bt1, bt3); // bt3를 bt1의 오른쪽 자식 노드로
    MakeLeftSubTree(bt2, bt4); // bt4를 bt2의 왼쪽 자식 노드로
    MakeRightSubTree(bt2, bt5);
    MakeRightSubTree(bt3, bt6);
    
    // 순회
    PreorderTraverse(bt1, ShowIntData);
    printf("\n");
    InorderTraverse(bt1, ShowIntData);
    printf("\n");
    PostorderTraverse(bt1, ShowIntData);
    printf("\n");
    
    // 트리의 모든 노드 삭제 및 반환
    DeleteTree(bt1);
    return 0;
}

void ShowIntData(int data)
{
    printf("%d ",data);
}
