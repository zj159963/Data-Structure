//
//  Queue.c
//  Queue_Array
//
//  Created by JianZhang on 2017/3/24.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"

struct QueueRecord
{
    int Capacity;
    int Front, Rear;
    int Size;
    ElementType *Elements;
};

static int _Queue_Elements_Successor_(Queue Q, int P)
{
    return ++P < Q->Capacity ? P : 0;
}

Queue QueueCreate(int Capacity)
{
    Queue Q;
    
    Q = malloc(sizeof(struct QueueRecord));
    assert(Q != NULL);
    Q->Elements = calloc(Capacity, sizeof(ElementType));
    assert(Q->Elements != NULL);
    
    Q->Capacity = Capacity;
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
    return Q;
}

void QueueDispose(Queue Q)
{
    free(Q->Elements);
    free(Q);
}

int QueueIsEmpty(Queue Q)
{
    return Q->Size == 0;
}

int QueueIsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

int QueueLength(Queue Q)
{
    return Q->Size;
}

void QueueEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

void QueueEnqueue(Queue Q, ElementType E)
{
    assert(!QueueIsFull(Q));
    
    Q->Size++;
    Q->Rear = _Queue_Elements_Successor_(Q, Q->Rear);
    Q->Elements[Q->Rear] = E;
}

ElementType QueueDequeue(Queue Q)
{
    ElementType E;
    assert(!QueueIsEmpty(Q));
    
    E = Q->Elements[Q->Front];
    Q->Size--;
    Q->Front = _Queue_Elements_Successor_(Q, Q->Front);
    return E;
}

void QueuePrint(Queue Q)
{
    int index, P;
    
    if (QueueIsEmpty(Q)) {
        printf("Empty Queue!");
        return;
    }
    
    index = 0;
    P = Q->Front;
    
    while (index < Q->Size) {
        printf("%d, ", Q->Elements[P]);
        P = _Queue_Elements_Successor_(Q, P);
        index++;
    }
    putchar('\n');
}
