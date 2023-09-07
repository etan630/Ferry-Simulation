#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

//initialize
QUEUE queue_init_default(void)
{
    Queue* pQueue = (Queue*)malloc(sizeof(Queue));
    if (pQueue == NULL)
    {
        printf("error in initializing queue -- returning NULL\n");
        return NULL;
    }
    pQueue->head = NULL;
    pQueue->tail = NULL;
    return pQueue;
}


//destroy
void queue_destroy(QUEUE* phQueue)
{
    Queue* pQueue = (Queue*) *phQueue;
    Node* temp;
    
    while(pQueue->head != NULL)
    {
        temp = pQueue->head->next;
        free(pQueue->head);
        pQueue->head = temp;
    }
    free(pQueue);
    *phQueue = NULL;
}


Boolean queue_is_empty(QUEUE hQueue)
{
    Queue* pQ = (Queue*)hQueue;

    return (Boolean)(pQ->head == NULL);
}


//insert
Status queue_enqueue(QUEUE hQueue, int length)
{
    Queue* pQueue = (Queue*) hQueue;
    
    if (length <= 0 || pQueue == NULL)
    {
        return FAILURE;
    }
    
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
    {
        return FAILURE;
    }
    
    temp->carLength = length;
    if(pQueue->head == NULL)
    {
        pQueue->head = temp;
        pQueue->tail = temp;
    }
    else
    {
        pQueue->tail->next = temp;
        pQueue->tail = pQueue->tail->next;
    }
    return SUCCESS;
}


//dequeue
Status queue_dequeue(QUEUE hQueue)
{
    Queue* pQueue = (Queue*) hQueue;
    Node* temp;
    
    if(pQueue->head == NULL)
    {
        return FAILURE;
    }
    
    temp = pQueue->head;
    pQueue->head = pQueue->head->next;
    free(temp);
    
    return SUCCESS;
}


//front
int queue_front(QUEUE hQueue, Status* pStatus)
{
    
    Queue* pQueue = (Queue*)hQueue;

    if (pQueue->head == NULL)
    {
        if (pStatus != NULL)
            *pStatus = FAILURE;
        return -9999;
    }

    if (pStatus != NULL)
        *pStatus = SUCCESS;
    return pQueue->head->carLength;
}
