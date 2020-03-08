#include "UsefulHeap.h"

void HeapInit(Heap *ph, PriorityComp pc)
{
    ph->numOfData = 0;
    ph->comp = pc;
}

int HIsEmpty(Heap *ph)
{
    if(ph->numOfData <= 0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIdx(int idx)
{
    return idx/2;
}

int GetLChildIdx(int idx)
{
    return idx*2;
}

int GetRChildIdx(int idx)
{
    return idx*2+1;
}

int GetHiPriChildIdx(Heap *ph, int idx)
{
    if(GetLChildIdx(idx) > ph->numOfData)
        return 0;
    else if(GetLChildIdx(idx) == ph->numOfData)
        return GetLChildIdx(idx);
    else
    {
        if(ph->comp(ph->heapArr[GetLChildIdx(idx)], ph->heapArr[GetRChildIdx(idx)]) < 0)
            return GetRChildIdx(idx);
        else
            return GetLChildIdx(idx);
    }
}

void HInsert(Heap *ph, HData data)
{
    int newIdx = ph->numOfData+1;
    
    while(newIdx != 1)
    {
        if(ph->comp(data, ph->heapArr[GetParentIdx(newIdx)]) > 0)
        {
            ph->heapArr[newIdx] = ph->heapArr[GetParentIdx(newIdx)];
            newIdx = GetParentIdx(newIdx);
        }
        else
            break;
    }
    ph->heapArr[newIdx] = data;
    ph->numOfData+=1;
}


int HDelete(Heap *ph)
{
    HData rData = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];
    
    int parentIdx = 1;
    int childIdx;
    
    while(TRUE)
    {
        childIdx = GetHiPriChildIdx(ph, parentIdx);
        if(childIdx == 0)
            break;
        
        if(ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
            break;
        
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    
    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return rData;
}
