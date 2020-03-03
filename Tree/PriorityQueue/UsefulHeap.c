#include "UsefulHeap.h"

void HeapInit(Heap *ph, PriorityComp pc)
{
    ph->numOfData = 0;
    ph->comp = pc;
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

int GetHiPriChildeIdx(Heap *ph, int idx)
{
    // 자식 노드가 없다면
    if(GetLChildIDX(idx) > ph->numOfData)
        return 0;
    
    // 왼쪽 자식 노드만 존재한다면
    else if(GetLChildIDX(idx) == ph->numOfData)
        return GetLChildIDX(idx);
    else
    {
        // 사용자가 설정한 기준으로 비교 ( 데이터 위주 )
        if(ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0)
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
        
}

void HInsert(Heap *ph, HData data)
{
    int idx = ph->numOfData+1;
    
    while(idx != 1)
    {
        // 부모 노드와의 우선순위 비교
        if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0) // 새 노드가 부모노드보다 우선순위가 더 높다면
        {
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else
            break;
    }
    
    ph->heapArr[idx] = data;
    ph->numOfData += 1;
}

HData HDelete(Heap *ph)
{
    HData rData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];
    
    int parentIdx = 1;
    int childIdx;
    
    while(childIdx = GetHiPriChildeIdx(ph, parentIdx))
    {
        if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
            break;
        
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    
    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return rData;
}
