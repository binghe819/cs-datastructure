#include "BinarySearchTree.h"
#include <stdlib.h>

// BST의 생성 및 초기화
void BSTMakeAndInit(BTreeNode **pRoot)
{
    *pRoot = NULL;
}

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode * bst)
{
    return bst->data;
}

// BST를 대상으로 데이터 저장 (노드의 생성과정 포함)
void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
    BTreeNode *pNode = NULL; // parent node
    BTreeNode *cNode = *pRoot; // current node
    BTreeNode *nNode = NULL; // new node
    
    // 새로운 노드가 추가될 위치를 찾는다.
    while(cNode != NULL) // 제일 중요.
    {
        // 데이터의(키의) 중복을 허용하지 않음.
        if(data == GetData(cNode))
            return ;
        
        pNode = cNode;
        
        if(GetData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    
    // pnode의 자식 노드로 추가할 새 노드의 생성
    nNode = MakeBTreeNode();
    nNode->data = data;
    
    // pNode의 자식 노드로 추가할 새 노드의 완성
    if(pNode != NULL) // 새 노드가 루트 노드가 아니라면,
    {
        if(data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else // 새 노드가 루트 노드라면,
    {
        *pRoot = nNode;
    }
}

// BST를 대상으로 데이터 탐색
BTreeNode *BSTSearch(BTreeNode *bst, BSTData target)
{
    BTreeNode *cNode = bst; // current Node
    BSTData cd; // current data
    
    while(cNode != NULL)
    {
        cd = GetData(cNode);
        
        if(cd == target)
            return cNode;
        else if(cd > target)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    
    return NULL; // 탐색 대상이 저장되어 있지 않음.
}

// 트리에서 노드를 제거하고 제거된 노드의 주소 값을 반환한다.
BTreeNode * BSTRemove(BTreeNode **pRoot, BSTData target)
{
    // 삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다.
    BTreeNode *pVRoot = MakeBTreeNode(); // 가상 루트 노드
    BTreeNode *pNode = pVRoot; // parent node
    BTreeNode *cNode = *pRoot; // current node
    BTreeNode *dNode; // delete node
    
    // 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 자식 노드가 되게 한다.
    ChangeRightSubTree(pVRoot, *pRoot);
    
    // 삭제 대상인 노드를 탐색
    while(cNode != NULL && GetData(cNode) != target)
    {
        pNode = cNode; // 삭제 대상의 부모 노드.
        if(GetData(cNode) > target)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }
    
    // 삭제 대상이 존재하지 않는다면
    if(cNode == NULL)
        return NULL;
    
    dNode = cNode;
    
    // 첫 번째 경우 : 삭제 대상이 단말 노드인 경우
    if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
    {
        if(GetLeftSubTree(pNode) == dNode)
            RemoveLeftSubTree(pNode);
        else
            RemoveRightSubTree(pNode);
    }
    
    // 두 번째 경우 : 삭제 대상이 하나의 자식 노드를 갖는 경우
    else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
    {
        BTreeNode *dcNode; // 삭제 대상의 자식노드
        
        // 삭제 대상의 자식노드 찾기
        if(GetLeftSubTree(dNode) != NULL)
            dcNode = GetLeftSubTree(dNode);
        else
            dcNode = GetRightSubTree(dNode);
        
        // 삭제 대상의 부모노드와 자식노드를 연결한다.
        if(GetLeftSubTree(pNode) == dNode)
            ChangeLeftSubTree(pNode, dcNode);
        else
            ChangeRightSubTree(pNode, dcNode);
    }
    
    // 세 번째 경우 : 두 개의 자식 노드를 모두 갖는 경우
    else
    {
        BTreeNode *mNode = GetRightSubTree(dNode); // 대체 노드
        BTreeNode *mpNode = dNode; // 대체 노드의 부모 노드
        int delData;
        // 삭제 노드를 대신할 대체 노드를 찾는다.
        while(GetLeftSubTree(mNode) != NULL)
        {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }
        
        // 대체 노드에 저장된 값을 삭제할 노드에 대입한다.
        delData = GetData(dNode); // 대입 전 데이터 백업
        SetData(dNode, GetData(mNode)); // 대입
        
        // 대체 노드의 부모 노드와 자식 노드를 연결.
        if(GetLeftSubTree(mpNode) == mNode)
            ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        else
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
        
        dNode = mNode;
        SetData(dNode, delData); // 백업 데이터 복원.
    }
    
    // 삭제된 노드가 루트 노드인 경우에 대한 추가적인 처리
    if(GetRightSubTree(pVRoot) != *pRoot)
        *pRoot = GetRightSubTree(pVRoot); // 루트 노드의 변경을 반영
    
    free(pVRoot); // 가상 루트 노드의 소멸
    return dNode;
}

void ShowIntData(int data)
{
    printf("%d\t", data);
}

// 이진 탐색 트리에 저장된 모든 노드의 데이터를 출력한다.
void BSTShowAll(BTreeNode * bst)
{
    InorderTraverse(bst, ShowIntData); // 중위 순회
}
