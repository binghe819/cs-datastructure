#ifndef ListBaseQueue_h
#define ListBaseQueue_h

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct __node
{
    Data data;
    struct __node *next;
} Node;

typedef struct _Queue
{
    Node *front;
    Node *rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue *pq);
int QIsEmpty(Queue *pq);

void Enqueue(Queue *pq, Data data);
Data Dequeue(Queue *pq);
Data QPeek(Queue *pq);

#endif /* ListBaseQueue_h */
