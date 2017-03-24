//
//  LinkedList.h
//  LinkedList
//
//  Created by JianZhang on 2017/2/27.
//  Copyright © 2017年 NUT. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>

extern int const HEAD_FALG;
typedef int ElementType;
struct Node;

typedef struct Node* PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode LinkedList;

LinkedList LinkedListCreate(const ElementType *array, int count);
LinkedList LinkedListCopy(LinkedList L);

int LinkedListLength(LinkedList L);
int LinkedListIsEmpty(LinkedList L);
int LinkedListIsLastNode(Position P, LinkedList L);
int LinkedListIsFirstNode(Position P, LinkedList L);
int LinkedListIsLoop(LinkedList L);
int LinkedListLoopLength(LinkedList L);

Position LinkedListFirstNode(LinkedList L);
Position LinkedListLastNode(LinkedList L);
Position LinkedListFindNode(ElementType E, LinkedList L);
Position LinkedListFindPreviousNode(ElementType E, LinkedList L);
Position LinkedListFindPriorNode(LinkedList L, Position P);
Position LinkedListFindMidNode(ElementType E, LinkedList L);
Position LinkedListFindNodeFromTail(unsigned int Distance, LinkedList L);
Position LinkedListFindLoopEntrance(LinkedList L);

void LinkedListAppend(LinkedList L, LinkedList A);
void LinkedListInsertElement(ElementType E, Position P, LinkedList L); /// Insert new Element after P
void LinkedListDeleteNode(Position NodeToDelete, LinkedList L);
void LinkedListDeleteElement(ElementType E, LinkedList L);
void LinkedListDeleteList(LinkedList L);
void LinkedListReverse(LinkedList L);
void LinkedListRadixSort(LinkedList L, unsigned int Places);

void LinkedListPrint(LinkedList L);

#endif /* LinkedList_h */
