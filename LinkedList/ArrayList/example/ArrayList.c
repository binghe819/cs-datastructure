//
//  ArrayList.c
//  C_practice
//
//  Created by 김병화 on 18/02/2020.
//  Copyright © 2020 김병화. All rights reserved.
//

#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist)
{
    (plist->numOfData) = 0; // 리스트에 저장된 데이터의 수 0으로 초기화.
    (plist->curPosition) = -1; // 현재 아무 위치도 가리키지 않음.
}

void LInsert(List *plist, LData data)
{
    if((plist->numOfData) >= LIST_LEN) // 저장할 공간이 없을 경우
        return;
    
    plist->arr[plist->numOfData] = data; // 데이터 저장. 배열 인덱스를 리스트의 저장된 데이터의 수로 함.
    plist->numOfData += 1; // 저장된 데이터의 수 증가.
}

int LFirst(List *plist, LData *pdata)
{
    if(plist->numOfData <= 0) // 저장된 데이터가 없다면 0을 반환.
        return FALSE; // 0
    
    plist->curPosition = 0; // 참조 위치 초기화 ( 첫 번째 데이터로 )
    *pdata = plist->arr[plist->curPosition]; //
    return TRUE; // 1
}

int LNext(List *plist, LData *pdata)
{
    // (참조위치가 저장된 데이터의 수-1보다 작거나 같으면 더이상 참조할 것이 없다는 의미 )
    if(plist->curPosition >= (plist->numOfData)-1) // 더 이상 참조 할것이 없다면.
        return FALSE; // 0
    
    plist->curPosition += 1; // 참조 위치를 다음으로
    *pdata = plist->arr[plist->curPosition]; // 데이터 포인터를 통해 데이터 저장.
    return TRUE; // 1
}

// LRemove가 호출되면 리스트의 멤버 curPosition을 확인해서, 조회가 이뤄진 데이터의 위치를 확인한 다음 그 데이터를 삭제한다.
LData LRemove(List *plist)
{
    LData removed_data = plist->arr[plist->curPosition]; // 삭제될 데이터 (반환을 통한 )
    
    // 삭제한 데이터를 기점으로 뒷 데이터 한칸씩 땡기기
    for(int i = plist->curPosition; i < plist->numOfData; i++)
        plist->arr[i] = plist->arr[i+1];
    
    (plist->numOfData) -= 1; // 데이터의 수 감소
    plist->curPosition -= 1; // 참조위치를 하나 되돌린다.
    return removed_data; // 삭제된 데이터의 반환
}

int LCount(List *plist)
{
    return plist->numOfData;
}
