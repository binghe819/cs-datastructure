#ifndef CircularQueue_h
#define CircularQueue_h

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100

typedef int Data;

typedef struct __queue
{
    int front;
    int rear;
    Data queArr[QUE_LEN];
} CQUEUE;

typedef CQUEUE QUEUE;

void QueueInit(QUEUE *pq);
int QIsEmpty(QUEUE *pq);

void Enqueue(QUEUE *pq, Data data);
Data Dequeue(QUEUE *pq);
Data QPeek(QUEUE *pq);

#endif /* CircularQueue_h */
