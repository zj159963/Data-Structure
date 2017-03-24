//
//  CircularDoublyLinkedList.h
//  CircularDoublyLinkedList
//
//  Created by JianZhang on 2017/3/8.
//  Copyright © 2017年 NUT. All rights reserved.
//

#ifndef CircularDoublyLinkedList_h
#define CircularDoublyLinkedList_h

#include <stdio.h>

struct Node;

typedef struct Node *PtrToNode;
typedef PtrToNode CircularDoublyLinkedList;
typedef PtrToNode Position;

CircularDoublyLinkedList CircularDoublyLinkedListCreate(const int Source[], unsigned int Count);

int CircularDoublyLinkedListIsEmpty(CircularDoublyLinkedList L);
int CircularDoublyLinkedListLength(CircularDoublyLinkedList L);
int CircularDoublyLinkedListIsFirstNode(CircularDoublyLinkedList L, Position P);
int CircularDoublyLinkedListIsLastNode(CircularDoublyLinkedList L, Position P);
/*
 *  If next branch has a loop , return value is positive;
 *  Else if prior branch has a loop, return value is negtive.
 *  If there is none loop, return 0.
 */
int CircularDoublyLinkedListIsBadLoop(CircularDoublyLinkedList L);
int CircularDoublyLinkedListBadLoopLength(CircularDoublyLinkedList L, int *Flag);

int CircularDoublyLinkedListRetrieve(Position P);

Position CircularDoublyLinkedListFirstNode(CircularDoublyLinkedList L);
Position CircularDoublyLinkedListLastNode(CircularDoublyLinkedList L);
Position CircularDoublyLinkedListFindMiddleNode(CircularDoublyLinkedList L);
Position CircularDoublyLinkedListFindNodeFromTail(CircularDoublyLinkedList L, unsigned int Distance);
Position CircularDoublyLinkedListFind(CircularDoublyLinkedList L, int Element);
Position CircularDoublyLinkedListFindPrevious(CircularDoublyLinkedList L, int Element);
Position CircularDoublyLinkedListFindPrior(CircularDoublyLinkedList L, Position P);
Position CircularDoublyLinkedListFindBadLoopEntrance(CircularDoublyLinkedList L, int *Flag);

Position CircularDoublyLinkedListAdvance(Position P);

void CircularDoublyLinkedListAppendList(CircularDoublyLinkedList L, CircularDoublyLinkedList A);
void CircularDoublyLinkedListInsertElement(CircularDoublyLinkedList L, Position P, int Element);
void CircularDoublyLinkedListDeleteElement(CircularDoublyLinkedList L, int Element);
void CircularDoublyLinkedListDeleteNode(CircularDoublyLinkedList L, Position P);
void CircularDoublyLinkedListDeleteList(CircularDoublyLinkedList L);
void CircularDoublyLinkedListRevere(CircularDoublyLinkedList L);
void CircularDoublyLinkedListPrint(CircularDoublyLinkedList L);
void CircularDoublyLinkedListPrintReversing(CircularDoublyLinkedList L);

#endif /* CircularDoublyLinkedList_h */
