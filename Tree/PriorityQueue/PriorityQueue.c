
#include "PriorityQueue.h"

void PQueueInit(PQData *ppq, PriorityComp pc)
{
    HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue *ppq)
{
    return HIsEmpty(ppq);
}

void PEnqueue(PQueue *ppq, HData data)
{
    HInsert(ppq, data);
}

PQData PDequeue(PQueue *ppq)
{
    return HDelete(ppq);
}
