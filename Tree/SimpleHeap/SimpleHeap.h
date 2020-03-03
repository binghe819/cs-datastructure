// 순수한 힙을 위한 헤더파일이 아닌, 우선순위 큐를 위한 힙의 헤더파일.

#ifndef SimpleHeap_h
#define SimpleHeap_h

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct __node
{
    Priority pr; // 기준 : 값이 작을수록 높은 우선순위
    HData data;
} HeapElem;

typedef struct __heap
{
    int numOfData;
    HeapElem heapArr[HEAP_LEN]; // 배열
} Heap;

void HeapInit(Heap *ph);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data, Priority pr); // 힙에 데이터 저장
HData HDelete(Heap *ph); // 힙에서 데이터 삭제

#endif /* SimpleHeap_h */
