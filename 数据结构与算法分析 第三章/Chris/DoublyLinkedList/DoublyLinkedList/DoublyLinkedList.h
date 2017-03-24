//
//  DoublyLinkedList.h
//  DoublyLinkedList
//
//  Created by JianZhang on 2017/3/7.
//  Copyright © 2017年 NUT. All rights reserved.
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include <stdio.h>

struct Node;

typedef struct Node *PtrToNode;
typedef PtrToNode DoublyLinkedList;
typedef PtrToNode Position;

DoublyLinkedList DoublyLinkedListCreate(const int Source[], unsigned int count);

int DoublyLinkedListIsLegal(DoublyLinkedList L);
int DoublyLinkedListIsEmpty(DoublyLinkedList L);
int DoublyLinkedListIsFirstNode(DoublyLinkedList L, Position P);
int DoublyLinkedListIsLastNode(DoublyLinkedList L, Position P);
int DoublyLinkedListLength(DoublyLinkedList L);
/*
 *  If next branch has a loop , return value is positive;
 *  Else if prior branch has a loop, return value is negtive.
 *  If there is none loop, return 0.
 */
int DoublyLinkedListIsBadLoop(DoublyLinkedList L);
/*
 *  If next branch has a loop , Flag value is positive;
 *  Else if prior branch has a loop, Flag value is negtive.
 *  If there is none loop, Flag is 0.
 */
int DoublyLinkedListBadLoopLength(DoublyLinkedList L, int *Flag);

int DoublyLinkedListRetrieve(Position P);

Position DoublyLinkedListFirstNode(DoublyLinkedList L);
Position DoublyLinkedListLastNode(DoublyLinkedList L);
Position DoublyLinkedListMiddleNode(DoublyLinkedList L);
Position DoublyLinkedListFindNode(DoublyLinkedList L, int Element);
Position DoublyLinkedListFindPreviousNode(DoublyLinkedList L, int Element);
Position DoublyLinkedListFindPriorNode(DoublyLinkedList L, Position P);
Position DoublyLinkedListFindNodeFromTail(DoublyLinkedList L, unsigned int Distance);
/*
 *  If next branch has a loop , Flag value is positive;
 *  Else if prior branch has a loop, Flag value is negtive.
 *  If there is none loop, Flag is 0.
 */
Position DoublyLinkedListFindBadLoopEntrance(DoublyLinkedList L, int *Flag);
Position DoublyLinkedListAdvance(Position P);

void DoublyLinkedListAppendList(DoublyLinkedList L, DoublyLinkedList A);
void DoublyLinkedListInsertElement(DoublyLinkedList L, Position P, int Element);
void DoublyLinkedListDeleteElement(DoublyLinkedList L, int Element);
void DoublyLinkedListDeleteNode(DoublyLinkedList L, Position P);
void DoublyLinkedListDeleteList(DoublyLinkedList L);
void DoublyLinkedListReverse(DoublyLinkedList L);
void DoublyLinkedListPrint(DoublyLinkedList L);

#endif /* DoublyLinkedList_h */
