//
//  Queue.h
//  LinkedQueue
//
//  Created by JianZhang on 2017/3/22.
//  Copyright © 2017年 NUT. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>

struct Node;
struct QueueRecord;

typedef struct Node *PtrToNode;
typedef struct QueueRecord *Queue;
typedef int ElementType;

Queue QueueCreate(void);
void QueueDispose(Queue Q);

int QueueIsEmpty(Queue Q);
int QueueLength(Queue Q);

void QueueEnqueue(Queue Q, ElementType E);
ElementType QueueDequeue(Queue Q);

void QueueEmpty(Queue Q);
void QueuePrint(Queue Q);

#endif /* Queue_h */
