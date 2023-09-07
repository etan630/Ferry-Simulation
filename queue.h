#ifndef queue_h
#define queue_h
#include "status.h"

typedef void* QUEUE;

struct node;
typedef struct node Node;

struct node
{
    int carLength;
    Node* next;
};

struct queue
{
    Node* head;
    Node* tail;
};
typedef struct queue Queue;

//initialize
QUEUE queue_init_default(void);
//destroy
void queue_destroy(QUEUE* phQueue);
//empty
Boolean queue_is_empty(QUEUE hQueue);
//insert
Status queue_enqueue(QUEUE hQueue, int length);
//dequeue
Status queue_dequeue(QUEUE hQueue);
//front
int queue_front(QUEUE hQueue, Status* pStatus);


#endif /* queue_h */
