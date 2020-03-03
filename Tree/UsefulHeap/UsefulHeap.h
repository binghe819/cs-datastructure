
#ifndef UsefulHeap_h
#define UsefulHeap_h

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int PriorityComp (HData d1, HData d2);

typedef struct __heap
{
    PriorityComp *comp;
    int numOfData;
    HData heapArr[HEAP_LEN]; // 배열
} Heap;

void HeapInit(Heap *ph, PriorityComp pc);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data); // 힙에 데이터 저장
HData HDelete(Heap *ph); // 힙에서 데이터 삭제

#endif /* UsefulHeap_h */
