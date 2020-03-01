
#ifndef BinaryTree_h
#define BinaryTree_h

typedef int BTData;

typedef struct __bTreeNode
{
    BTData data;
    struct __bTreeNode *left;
    struct __bTreeNode *right;
} BTreeNode;

// 이진 트리 노드를 생성하여 그 주소값을 반환.
BTreeNode * MakeBTreeNode(void);
// 노드에 저장된 데이터를 반환한다.
BTData GetData(BTreeNode *bt);
// 노드에 데이터를 저장한다.
void SetData(BTreeNode *bt, BTData data);

// 왼쪽 서브 트리의 주소값을 반환
BTreeNode * GetLeftSubTree(BTreeNode *bt);
// 오른쪽 서브 트리의 주소값을 반환
BTreeNode * GetRightSubTree(BTreeNode *bt);

// 왼쪽 서브 트리를 연결한다.
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
// 오른쪽 서브 트리를 연결한다.
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);


// 순회
typedef void VisitFuncPtr(BTData data); // 함수 포인터 ( 함수를 변수처럼 typedef하고 콜백으로 action의 대한 형식을 지정 )

// 전위 순회
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);

// 중위 순회
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);

// 후위 순회
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);

// 순회를 사용한 노드 소멸 ( 해당 노드를 루트노드로 하는 트리 전부를 소멸 ) 후위순회를 사용한다.
void DeleteTree(BTreeNode *bt);

#endif /* BinaryTree_h */
