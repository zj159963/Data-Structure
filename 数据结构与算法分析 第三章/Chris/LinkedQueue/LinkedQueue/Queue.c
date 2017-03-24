//
//  Queue.c
//  LinkedQueue
//
//  Created by JianZhang on 2017/3/22.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Queue.h"

struct Node {
    ElementType Element;
    PtrToNode Next;
};

struct QueueRecord {
    PtrToNode Front, Rear;
};

static PtrToNode _QueueCreateNode_(ElementType E)
{
    PtrToNode P;
    
    P = malloc(sizeof(struct Node));
    assert(P != NULL);
    P->Element = E;
    P->Next = NULL;
    return P;
}

Queue QueueCreate(void)
{
    Queue q;
    PtrToNode p;
    
    q = malloc(sizeof(struct QueueRecord));
    assert(q != NULL);
    
    p = _QueueCreateNode_(0);
    
    q->Front = p;
    q->Rear = p;
    return q;
}

void QueueDispose(Queue Q)
{
    while (Q->Front) {
        Q->Rear = Q->Front->Next;
        free(Q->Front);
        Q->Front = Q->Rear;
    }
}

int QueueIsEmpty(Queue Q)
{
    return Q->Front == Q->Rear;
}

int QueueLength(Queue Q)
{
    int length;
    PtrToNode P;
    
    length = 0;
    P = Q->Front->Next;
    
    while (P != NULL) {
        length++;
        P = P->Next;
    }
    return length;
}

void QueueEnqueue(Queue Q, ElementType E)
{
    PtrToNode P;
    
    P = _QueueCreateNode_(E);
    Q->Rear->Next = P;
    Q->Rear = P;
}

ElementType QueueDequeue(Queue Q)
{
    ElementType E;
    PtrToNode P;
    
    assert(!QueueIsEmpty(Q));
    
    P = Q->Front->Next;
    E = P->Element;
    Q->Front->Next = P->Next;
    
    if (Q->Rear == P)
        Q->Rear = Q->Front;
    free(P);
    return E;
}

void QueueEmpty(Queue Q)
{
    PtrToNode P, TempCell;
    
    Q->Rear = Q->Front;
    P = Q->Front->Next;
    Q->Front->Next = NULL;
    
    while (P != NULL) {
        TempCell = P;
        P = P->Next;
        free(TempCell);
    }
}

void QueuePrint(Queue Q)
{
    PtrToNode P;
    
    if (QueueIsEmpty(Q)) {
        printf("Empty Queue!\n");
        return;
    }
    
    P = Q->Front->Next;
    while (P != NULL) {
        printf("%d, ", P->Element);
        P = P->Next;
    }
    
    putchar('\n');
}
