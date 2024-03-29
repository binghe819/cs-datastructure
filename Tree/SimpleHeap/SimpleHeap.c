#include "SimpleHeap.h"
#include <stdlib.h>

void HeapInit(Heap *ph)
{
    ph->numOfData = 0; // 힙의 초기화
}

int HIsEmpty(Heap *ph)
{
    if(ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx) // 부모 노드의 인덱스 값 반환
{
    return idx/2;
}

int GetLChildIDX(int idx) // 왼쪽 자식 노드의 인덱스 값 반환
{
    return idx*2;
}

int GetRChildIDX(int idx) // 오른쪽 자식 노드의 인덱스 값 반환
{
    return GetLChildIDX(idx)+1;
}

// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
int GetHiPriChildIdx(Heap *ph, int idx)
{
    // 자식 노드가 존재하지 않는다면 ( 그림으로 완전 이진트리를 그리면 if문의 조건이 이해가 간다. )
    if(GetLChildIDX(idx) > ph->numOfData)
        return 0;
    // 자식 노드가 왼쪽 자신 노드 하나만 존재한다면 ( 완전 이진 트리이므로 왼쪽부터 데이터가 쌓임, 그림을 그리면 이해가 빠르다. )
    else if(GetLChildIDX(idx) == ph->numOfData)
        return GetLChildIDX(idx);
    // 자식 노드가 둘 다 존재한다면
    else
    {
        if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
            return GetRChildIDX(idx); // 낮은 숫자가 더 높은 우선순위를 가진다는 기준으로 구현함.
        else
            return GetLChildIDX(idx);
    }
}

HData HDelete(Heap *ph)
{
    HData rData = (ph->heapArr[1]).data; // 반환을 위해서 삭제할 데이터.
    HeapElem lastElem = ph->heapArr[ph->numOfData]; // 마지막노드
    
    // parentIdx는 마지막 노드가 저장될 위치정보가 담긴다.
    int parentIdx = 1; // 루트 노드가 위치해야 할 인덱스 값 저장. ( 루트노드부터 아래로 훝는다.)
    int childIdx;
    
    while(childIdx = GetHiPriChildIdx(ph, parentIdx))
    {
        if(lastElem.pr <= ph->heapArr[childIdx].pr) // 마지막 노드와 우선순위 비교
            break; // 마지막 노드의 우선순위가 높으면 반복문 탈출
        
        // 마지막 노드보다 우선순위 높으니, 비교대상 노드의 위치를 한 레벨 올림
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx; // 마지막 노드가 저장될 위치정보를 한 레벨 내림
    }  // 반복문 탈출하면 parentIdx에는 마지막 노드의 위치정보가 저장됨.
    
    ph->heapArr[parentIdx] = lastElem; // 마지막 노드 최종 저장
    ph->numOfData -= 1;
    return rData;
}

void HInsert(Heap *ph, HData data, Priority pr)
{
    int idx = ph->numOfData+1; // 새로운 노드가 들어갈 위치(인덱스(
    HeapElem newElem = {pr,data}; // 새 노드의 생성 및 초기화
    
    while(idx != 1) // 새로운 노드의 인덱스가 루트노드를 가리키면 탈출
    {
        // 새 노드와 부모 노드의 우선순위 비교
        if(pr < ph->heapArr[GetParentIDX(idx)].pr) // 새 노드의 우선순위가 높다면
        {
            // 부모 노드를 한 레벨 내림, 실제로 내림
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            
            // 새 노드를 한 레벨 올림, 실제로 올리지는 않고 인덱스 값만 갱신
            idx = GetParentIDX(idx);
        }
        else // 새 노드의 우선순위가 높지 않다면
            break;
    }
    
    ph->heapArr[idx] = newElem; // 새 노드를 배열에 저장
    ph->numOfData += 1;
}
