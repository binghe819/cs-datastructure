
#ifndef UsefulHeap_h
#define UsefulHeap_h

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef int HData;
typedef int (*PriorityComp) (HData d1, HData d2);

typedef struct __heap
{
    PriorityComp comp; // 함수포인터
    int numOfData;
    HData heapArr[HEAP_LEN]; // 배열
} Heap;

void HeapInit(Heap *ph, PriorityComp pc);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data);
int HDelete(Heap *ph);

#endif /* UsefulHeap_h */
