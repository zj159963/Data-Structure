//
//  CircularLinkedList.h
//  CircularLinkedList
//
//  Created by JianZhang on 2017/3/7.
//  Copyright © 2017年 NUT. All rights reserved.
//

#ifndef CircularLinkedList_h
#define CircularLinkedList_h

struct Node;

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode CircularLinkedList;
typedef PtrToNode Position;

CircularLinkedList CircularLinkedListCreate(int *Source, unsigned int Count);

unsigned int CircularLinkedListLength(CircularLinkedList L);
int CircularLinkedListIsEmpty(CircularLinkedList L);
int CircularLinkedListIsFirstNode(CircularLinkedList L, Position P);
int CircularLinkedListIsLastNode(CircularLinkedList L, Position P);
int CircularLinkedListIsBadLoop(CircularLinkedList L);
int CircularLinkedListBadLoopLength(CircularLinkedList L);

ElementType CircularLinkedListRetrieve(Position P);

Position CircularLinkedListAdvance(Position P);
Position CircularLinkedListFirstNode(CircularLinkedList L);
Position CircularLinkedListLastNode(CircularLinkedList L);
Position CircularLinkedListFind(CircularLinkedList L, ElementType E);
Position CircularLinkedListFindPrior(CircularLinkedList L, Position P);
Position CircularLinkedListFindPrevious(CircularLinkedList L, ElementType E);
Position CircularLinkedListBadLoopEntrance(CircularLinkedList L);
Position CircularLinkedListFindMid(CircularLinkedList L);
Position CircularLinkedListFindFromTail(CircularLinkedList L, unsigned int Distance);

void Josephus(unsigned int Count, unsigned int Target, unsigned int Start, void(targetCallBack)(unsigned int index));

void CircularLinkedListAppend(CircularLinkedList L, CircularLinkedList A);
void CircularLinkedListInsert(CircularLinkedList L, ElementType Element, Position P);
void CircularLinkedListDeleteNode(CircularLinkedList L, Position P);
void CircularLinkedListDeleteElement(CircularLinkedList L, ElementType E);
void CircularLinkedListDeleteList(CircularLinkedList L);
void CircularLinkedListReverse(CircularLinkedList L);
void CircularLinkedListPrint(CircularLinkedList L, void (log)(ElementType Element));

#endif /* CircularLinkedList_h */
