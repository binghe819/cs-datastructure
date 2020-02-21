#include <stdio.h>
#include <stdlib.h>

typedef struct __node
{
    int data;
    struct __node *next;
} Node;

int main(){
    
    int data;
    Node *head = NULL;
    Node *tail = NULL;
    Node *cur = NULL;
    
    while(1)
    {
        // 입력 받기.
        printf("입력 : ");
        scanf("%d", &data);
        if(data == 0) // 0을 입력하면 반복문 탈출.
            break;
        
        // 노드(요소) 동적 생성.
        Node *newNode = (Node*)malloc(sizeof(Node)); // 노드 생성
        newNode->data = data; // 노드에 데이터 저장.
        newNode->next = NULL; // 노드의 next를 NULL로 초기화.
        
        if(head == NULL) // 첫 번째 노드라면.
            head=newNode; // 첫 번째 노드를 head가 가리키게 함.
        else // 첫번째 노드가 아니라면.
        {
            tail->next=newNode; // 기존의 tail이 가리키는 노드에 next를 새로운 노드에 연결.
        }
        tail = newNode; // 노드의 끝을 tail이 가리키게 함.
    }
    
    
    // 조회
    printf("-------- 출력 --------\n");
    if(head == NULL) // 노드가 없다면.
        printf("저장된 데이터가 없습니다.\n");
    else
    {
        cur = head; // cur이 리스트의 첫 번째 노드를 가리킨다.
        printf("%d\n", cur->data); // 첫 번째 노드의 데이터 출력
        while(cur->next != NULL) // 연결된 노드가 존재한다면
        {
            cur = cur->next; // cur이 다음 노드를 가리키게 한다.
            printf("%d\n", cur->data); // cur이 가리키는 노드를 출력한다.
        }
    }
    
    // 삭제
    if(head == NULL)
        return 0;
    else
    {
        Node *delNode = head; // head를 가리킨다.
        Node *delNextNode = head->next; // head가 가리키는 노드를 삭제하면, 그 다음 노드게 접근이 불가하므로, delNextNode를 통해 다음 노드를 저장.
        
        printf("%d을 삭제합니다. \n", head->data);
        free(delNode); // 첫 번째 노드 삭제.
        
        while(delNextNode != NULL) // 다음 노드가 없다면.
        {
            delNode = delNextNode; // delNode가 다음 노드를 가리킴.
            delNextNode = delNextNode->next; // delNextNode는 그 다음 노드를 가리킴.
            
            printf("%d을 삭제합니다. \n", delNode->data);
            free(delNode); // 메모리 해체 ( 삭제 ).
        }
    }
    
    
    return 0;
}

