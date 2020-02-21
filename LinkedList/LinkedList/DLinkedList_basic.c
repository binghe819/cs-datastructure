//
//  main.c
//  C_practice
//
//  Created by 김병화 on 30/01/2020.
//  Copyright © 2020 김병화. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct __node
{
    int data;
    struct __node *next;
} Node;

int main(){
    
    
    Node *head = NULL;
    Node *tail = NULL;
    Node *cur = NULL;
    
    Node *newNode = NULL;
    int data;
    
    // 더미 노드 추가후 head에 연결
    head = (Node*)malloc(sizeof(Node));
    tail = head;
    
    while(1)
    {
        // 입력을 통한 새로운 노드 추가
        printf("입력 : ");
        scanf("%d", &data);
        if(data == 0)
            break;
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        
        /*
        기존의 연결리스트의 경우
        if(head == NULL)
            head = newNode;
        else
        {
            tail->next = newNode;
        }
        tail = newNode;
        */
        
        // 더미 노드 추가시 아래와 같이 간단해진다.
        tail->next = newNode;
        tail=newNode;
    }
    
    printf("입력 받은 데이터 전부 출력!\n");
    if(head == tail) // head와 tail이 같다는건 tail이 더미노드를 가리킨다는 것.
        printf("저장된 데이터가 없습니다!\n");
    else
    {
        cur = head; // 더미 노드를 가리킴.
        while(cur->next != NULL)
        {
            cur = cur->next;
            printf("%d\n", cur->data);
        }
    }
    
    // 모든 노드 삭제
    if(head == tail)
        printf("저장된 것이 없어 삭제할 데이터가 없습니다 \n");
    else
    {
        Node *delNode = head; // 더미노드
        Node *delNextNode = head->next; // 첫 번째 데이터.
        
        while(delNextNode->next != NULL)
        {
            delNode = delNextNode;
            delNextNode = delNextNode->next;
            printf("%d 삭제\n", delNode->data);
            free(delNode);
        }
    }
    
    return 0;
}

