//
//  LinkedList.h
//  LinkedList_Cursor
//
//  Created by JianZhang on 2017/3/21.
//  Copyright © 2017年 NUT. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>

typedef int ElementType;
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node {
    ElementType Element;
    Position Next;
};

#define LinkedListCursorSpaceSize 1000
extern struct Node LinkedListCursorSpace[LinkedListCursorSpaceSize];

void LinkedListInitializeCursorSpace(void);

List LinkedListCreate(const ElementType *Sources, unsigned int Count);

int LinkedListIsEmpty(List L);
int LinkedListIsLastNode(List L, Position P);
Position LinkedListFind(List L, ElementType E);
Position LinkedListFindPrevious(List L, ElementType E);
void LinkedListDeleteElement(List L, ElementType E);
void LinkedListInsertElement(List L, ElementType E, Position P);

void LinkedListPrint(List L);

#endif /* LinkedList_h */
