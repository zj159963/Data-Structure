//
//  Queue.h
//  Queue_Array
//
//  Created by JianZhang on 2017/3/24.
//  Copyright © 2017年 NUT. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

typedef int ElementType;
struct QueueRecord;
typedef struct QueueRecord *Queue;

Queue QueueCreate(int Capacity);
void QueueDispose(Queue Q);

int QueueIsEmpty(Queue Q);
int QueueIsFull(Queue Q);
int QueueLength(Queue Q);

void QueueEmpty(Queue);

void QueueEnqueue(Queue Q, ElementType E);
ElementType QueueDequeue(Queue Q);

void QueuePrint(Queue Q);

#endif /* Queue_h */
