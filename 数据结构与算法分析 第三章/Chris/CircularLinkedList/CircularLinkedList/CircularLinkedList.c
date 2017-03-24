//
//  CircularLinkedList.c
//  CircularLinkedList
//
//  Created by JianZhang on 2017/3/7.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "CircularLinkedList.h"

struct Node {
    void *Element;
    Position Next;
};

CircularLinkedList CircularLinkedListCreate(void **Src, unsigned int Count)
{
    CircularLinkedList List;
    Position P, TempCell;
    unsigned int index;
    
    List = calloc(1, sizeof(struct Node));
    P = List;
    for (index = 0; index < Count; index++) {
        TempCell = calloc(1, sizeof(struct Node));
        assert(TempCell != NULL);
        TempCell->Element = Src[index];
        P->Next = TempCell;
        P = TempCell;
    }
    P->Next = List;
    return List;
}

unsigned int CircularLinkedListLength(CircularLinkedList L)
{
    Position P;
    int count;
    
    P = L->Next;
    
    while (P != L) {
        count++;
        P = P->Next;
    }
    return count;
}

int CircularLinkedListIsEmpty(CircularLinkedList L)
{
    return L->Next == L;
}

int CircularLinkedListIsFirstNode(CircularLinkedList L, Position P)
{
    return P == L ? 0 : P == L->Next;
}

int CircularLinkedListIsLastNode(CircularLinkedList L, Position P)
{
    return P->Next == L;
}

int CircularLinkedListIsBadLoop(CircularLinkedList L)
{
    Position Slow, Fast;
    
    Slow = L;
    Fast = L;
    
    while (Fast->Next != L && Fast->Next->Next != L) {
        Slow = Slow->Next;
        Fast = Fast->Next->Next;
        if (Slow == Fast)
            return 1;
    }
    return 0;
}

int CircularLinkedListBadLoopLength(CircularLinkedList L)
{
    int length;
    Position Slow, Fast;
    
    Slow = L;
    Fast = L;
    
    while (Fast->Next != L && Fast->Next->Next != L) {
        Slow = Slow->Next;
        Fast = Fast->Next->Next;
        if (Slow == Fast)
            break;
    }
    
    if (Slow != Fast)
        return 0;
    
    length = 1;
    Fast = Fast->Next;
    
    while (Fast != Slow) {
        Fast = Fast->Next;
        length++;
    }
    return length;
}

void * CircularLinkedListRetrieve(Position P)
{
    return P->Element;
}

Position CircularLinkedListAdvance(Position P)
{
    return P->Next;
}

Position CircularLinkedListFirstNode(CircularLinkedList L)
{
    return L->Next;
}

Position CircularLinkedListLastNode(CircularLinkedList L)
{
    Position P;
    
    P = L;
    while (P->Next != L)
        P = P->Next;
    return P;
}

Position CircularLinkedListFind(CircularLinkedList L, void *E)
{
    Position P;
    
    P = L->Next;
    while (P != L && P->Element != E)
        P = P->Next;
    return P == L ? NULL : P;
}

Position CircularLinkedListFindPrior(CircularLinkedList L, Position P)
{
    Position Temp;
    
    assert(P != NULL);
    Temp = L;
    while (Temp->Next != L && Temp->Next != P)
        Temp = Temp->Next;
    return Temp == L ? NULL : Temp;
}

Position CircularLinkedListFindPrevious(CircularLinkedList L, void *E)
{
    Position P;
    
    P = L;
    while (P->Next != L && P->Next->Element != E)
        P = P->Next;
    return P->Next == L ? NULL : P;
}

Position CircularLinkedListFindMid(CircularLinkedList L)
{
    Position Slow, Fast;
    
    Slow = L;
    Fast = L;
    
    while (Fast->Next != L && Fast->Next->Next != L) {
        Slow = Slow->Next;
        Fast = Fast->Next->Next;
    }
    return Fast->Next == L ? Slow : Slow ->Next;
}

Position CircularLinkedListFindFromTail(CircularLinkedList L, unsigned int Distance)
{
    Position P, TempCell;
    unsigned int index;
    
    TempCell = L;
    for (index = 0; index < Distance; index++) {
        TempCell = TempCell->Next;
        if (TempCell == L)
            return NULL;
    }
    
    P = L;
    
    while (TempCell->Next != L) {
        P = P->Next;
        TempCell = TempCell->Next;
    }
    return P;
}

Position CircularLinkedListBadLoopEntrance(CircularLinkedList L)
{
    Position Slow, Fast;
    
    Slow = L;
    Fast = L;
    
    while (Fast->Next != L && Fast->Next->Next != L) {
        Slow = Slow->Next;
        Fast = Fast->Next->Next;
        if (Slow == Fast)
            break;
    }
    
    if (Slow != Fast || Slow == L)
        return NULL;
    
    Slow = L;
    
    while (Slow != Fast) {
        Slow = Slow->Next;
        Fast = Fast->Next;
    }
    return Slow;
}

void CircularLinkedListAppend(CircularLinkedList L, CircularLinkedList A)
{
    if (CircularLinkedListIsEmpty(A)) {
        free(A);
        return;
    }
    
    Position LTail = CircularLinkedListLastNode(L);
    Position ATail = CircularLinkedListLastNode(A);
    
    LTail->Next = A->Next;
    ATail->Next = L;
    free(A);
}

void CircularLinkedListInsert(CircularLinkedList L, void *Element, Position P)
{
    Position TempCell;
    
    TempCell = calloc(1, sizeof(struct Node));
    assert(TempCell != NULL);
    TempCell->Element = Element;
    TempCell->Next = P->Next;
    P->Next = TempCell;
}

void CircularLinkedListDeleteNode(CircularLinkedList L, Position P)
{
    Position TempCell, Prior;
    
    assert(L != P);
    
    if (CircularLinkedListIsLastNode(L, P)) {
        Prior = CircularLinkedListFindPrior(L, P);
        Prior->Next = P->Next;
        free(P->Element);
        free(P);
        return;
    }
    
    TempCell = P->Next;
    free(P->Element);
    P->Element = TempCell->Element;
    P->Next = TempCell->Next;
    free(TempCell);
}

void CircularLinkedListDeleteElement(CircularLinkedList L, void *E)
{
    Position Prior, TempCell;
    
    Prior = CircularLinkedListFindPrevious(L, E);
    TempCell = Prior->Next;
    Prior->Next = TempCell->Next;
    free(TempCell->Element);
    free(TempCell);
}

void CircularLinkedListDeleteList(CircularLinkedList L)
{
    Position P, TempCell;
    
    P = L->Next;
    L->Next = L;
    while (P != L) {
        TempCell = P->Next;
        free(P->Element);
        free(P);
        P = TempCell;
    }
}

void CircularLinkedListReverse(CircularLinkedList L)
{
    Position P, R, TempCell;
    
    P = L->Next;
    TempCell = L;
    while (P != L) {
        R = P->Next;
        P->Next = TempCell;
        TempCell = P;
        P = R;
    }
    L->Next = TempCell;
}

void CircularLinkedListPrint(CircularLinkedList L, void (log)(void *Element))
{
    Position P;
    
    P = L->Next;
    while (P != L) {
        log(P->Element);
        printf(", ");
        P = P->Next;
    }
}
