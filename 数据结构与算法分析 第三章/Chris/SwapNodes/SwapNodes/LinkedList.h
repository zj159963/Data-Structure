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

LinkedList CreateList(const ElementType *array, int count);

int Length(LinkedList L);
int IsEmpty(LinkedList L);
int IsLast(Position P, LinkedList L);
int IsFirst(Position P, LinkedList L);
int IsLoop(LinkedList L);
int LoopLength(LinkedList L);

ElementType Retrieve(Position P);

Position First(LinkedList L);
Position Last(LinkedList L);
Position Find(ElementType E, LinkedList L);
Position FindPrevious(ElementType E, LinkedList L);
Position FindPrior(LinkedList L, Position P);
Position FindMid(ElementType E, LinkedList L);
Position FindFromTail(unsigned int Distance, LinkedList L);
Position FindLoopEntrance(LinkedList L);
Position Advance(Position P);

void Append(LinkedList L, LinkedList A);
void Insert(ElementType E, Position P, LinkedList L); /// Insert new Element after P
void DeleteNode(Position NodeToDelete, LinkedList L);
void Delete(ElementType E, LinkedList L);
void DeleteList(LinkedList L);
void Reverse(LinkedList L);
void Swap(LinkedList L, Position P); /// Swap the nodes after P

void PrintList(LinkedList L);

#endif /* LinkedList_h */
