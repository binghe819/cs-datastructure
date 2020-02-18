//
//  main.c
//  C_practice
//
//  Created by 김병화 on 30/01/2020.
//  Copyright © 2020 김병화. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main(){
    
    List list;
    Point compPos;
    Point *ppos;
    
    ListInit(&list);
    
    // 2개의 데이터 저장
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);
    
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);
    
    ppos = (Point *)malloc(sizeof(Point));
    SetPointPos(ppos, 1, 2);
    LInsert(&list, ppos);
    
    // 저장된 데이터 출력
    if(LFirst(&list, &ppos)) // &ppos인 이유 : 리스트의 요소(Point)를 받기 위함
    {
        ShowPointPos(ppos);
        
        while(LNext(&list, &ppos))
            ShowPointPos(ppos);
    }
    printf("\n");
    
    // xpos가 2인 모든 데이터 삭제
    compPos.xpos = 2;
    compPos.ypos = 0;
    
    if(LFirst(&list, &ppos))
    {
        if(PointComp(ppos, &compPos) == 1)
        {
            ppos = LRemove(&list);
            free(ppos);
        }
        
        while(LNext(&list, &ppos))
        {
            if(PointComp(ppos, &compPos) == 1)
            {
                ppos = LRemove(&list);
                free(ppos);
            }
        }
    }
    
    // 삭제후 데이터 출력
    printf("삭제 된 후 ");
    if(LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);
        
        while(LNext(&list, &ppos))
            ShowPointPos(ppos);
    }
    return 0;
}

