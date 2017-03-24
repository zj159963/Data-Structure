//
//  LinkedList.c
//  LinkedList_Cursor
//
//  Created by JianZhang on 2017/3/21.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "LinkedList.h"

struct Node {
    ElementType Element;
    Position Next;
};

struct Node LinkedListCursorSpace[LinkedListCursorSpaceSize];

static Position LinkedListCursorAlloc(void)
{
    Position P;
    
    P = LinkedListCursorSpace[0].Next;
    LinkedListCursorSpace[0].Next = LinkedListCursorSpace[P].Next;
    
    return P;
}

static void LinkedListCursorFree(Position P)
{
    LinkedListCursorSpace[P].Next = LinkedListCursorSpace[0].Next;
    LinkedListCursorSpace[0].Next = P;
}

void LinkedListInitializeCursorSpace(void)
{
    static int initialized = 0;
    int index;
    
    if (initialized)
        return;
    
    for (index = 0; index < LinkedListCursorSpaceSize; index++)
        LinkedListCursorSpace[index].Next = index + 1;
    
    initialized = 1;
}

List LinkedListCreate(const ElementType *Sources, unsigned int Count)
{
    List L, P, TempCell;
    unsigned int index;
    
    L = LinkedListCursorAlloc();
    assert(L != 0);
    LinkedListCursorSpace[L].Element = 0;
    LinkedListCursorSpace[L].Next = 0;
    
    P = L;
    
    for (index = 0; index < Count; index++) {
        TempCell = LinkedListCursorAlloc();
        assert(TempCell != 0);
        LinkedListCursorSpace[TempCell].Element = Sources[index];
        LinkedListCursorSpace[TempCell].Next = 0;
        LinkedListCursorSpace[P].Next = TempCell;
        P = TempCell;
    }
    
    return L;
}

int LinkedListIsEmpty(List L)
{
    return LinkedListCursorSpace[L].Next == 0;
}

int LinkedListIsLastNode(List L, Position P)
{
    return LinkedListCursorSpace[P].Next == 0;
}

Position LinkedListFind(List L, ElementType E)
{
    Position P;
    
    P = LinkedListCursorSpace[L].Next;
    while (P != 0 && LinkedListCursorSpace[P].Element != E)
        P = LinkedListCursorSpace[P].Next;
    return P;
}

Position LinkedListFindPrevious(List L, ElementType E)
{
    Position P;
    
    P = L;
    
    while (LinkedListCursorSpace[P].Next != 0 && LinkedListCursorSpace[LinkedListCursorSpace[P].Next].Element != E)
        P = LinkedListCursorSpace[P].Next;
    return LinkedListIsLastNode(L, P) ? 0 : P;
}

void LinkedListDeleteElement(List L, ElementType E)
{
    Position P, TempCell;
    
    P = LinkedListFindPrevious(L, E);
    assert(P != 0);
    
    TempCell = LinkedListCursorSpace[P].Next;
    LinkedListCursorSpace[P].Next = LinkedListCursorSpace[TempCell].Next;
    LinkedListCursorFree(TempCell);
}

void LinkedListInsertElement(List L, ElementType E, Position P)
{
    Position TempCell;
    
    TempCell = LinkedListCursorAlloc();
    LinkedListCursorSpace[TempCell].Element = E;
    LinkedListCursorSpace[TempCell].Next = LinkedListCursorSpace[P].Next;
    LinkedListCursorSpace[P].Next = TempCell;
}

void LinkedListPrint(List L)
{
    Position P;
    
    if (LinkedListIsEmpty(L)) {
        printf("Empty List.\n");
        return;
    }
    
    P = LinkedListCursorSpace[L].Next;
    
    while (P != 0) {
        printf("%d, ", LinkedListCursorSpace[P].Element);
        P = LinkedListCursorSpace[P].Next;
    }
    
    putchar('\n');
}
