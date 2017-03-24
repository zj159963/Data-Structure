//
//  CircularDoublyLinkedList.c
//  CircularDoublyLinkedList
//
//  Created by JianZhang on 2017/3/8.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdlib.h>
#include <assert.h>
#include "CircularDoublyLinkedList.h"

struct Node {
    int Element;
    Position Prior;
    Position Next;
};

CircularDoublyLinkedList CircularDoublyLinkedListCreate(const int Source[], unsigned int Count)
{
    CircularDoublyLinkedList List;
    Position P, TempCell;
    unsigned int index;
    
    List = calloc(1, sizeof(struct Node));
    assert(List != NULL);
    
    P = List;
    for (index = 0; index < Count; index++) {
        TempCell = calloc(1, sizeof(struct Node));
        assert(TempCell != NULL);
        TempCell->Element = Source[index];
        P->Next = TempCell;
        TempCell->Prior = P;
        P = TempCell;
    }
    P->Next = List;
    List->Prior = P;
    return List;
}

int CircularDoublyLinkedListIsEmpty(CircularDoublyLinkedList L)
{
    return L->Next == L;
}

int CircularDoublyLinkedListLength(CircularDoublyLinkedList L)
{
    int length;
    Position P;
    
    length = 0;
    P = L->Next;
    while (P != L) {
        P = P->Next;
        length++;
    }
    return length;
}

int CircularDoublyLinkedListIsFirstNode(CircularDoublyLinkedList L, Position P)
{
    return P == L->Next;
}

int CircularDoublyLinkedListIsLastNode(CircularDoublyLinkedList L, Position P)
{
    return P->Next == L;
}

int CircularDoublyLinkedListIsBadLoop(CircularDoublyLinkedList L)
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
    
    Slow = L;
    Fast = L;
    
    while (Fast->Prior != L && Fast->Prior->Prior != L) {
        Slow = Slow->Prior;
        Fast = Fast->Prior->Prior;
        if (Slow == Fast)
            return -1;
    }
    return 0;
}

int CircularDoublyLinkedListBadLoopLength(CircularDoublyLinkedList L, int *Flag)
{
    int length;
    Position Slow, Fast;
    
    *Flag = 0;
    Slow = L;
    Fast = L;
    
    while (Fast->Next != L && Fast->Next->Next != L) {
        Slow = Slow->Next;
        Fast = Fast->Next->Next;
        if (Slow == Fast) {
            *Flag = 1;
            break;
        }
    }
    
    if (*Flag == 1) {
        length = 1;
        Fast = Fast->Next;
        while (Slow != Fast) {
            Fast = Fast->Next;
            length++;
        }
        return length;
    }
    
    Slow = L;
    Fast = L;
    
    while (Fast->Prior != L && Fast->Prior->Prior != L) {
        Slow = Slow->Prior;
        Fast = Fast->Prior->Prior;
        if (Slow == Fast) {
            *Flag = -1;
            break;
        }
    }
    
    if (*Flag == -1) {
        Fast = Fast->Prior;
        length = 1;
        while (Slow != Fast) {
            Fast = Fast->Prior;
            length++;
        }
        return length;
    }
    return length;
}

int CircularDoublyLinkedListRetrieve(Position P)
{
    return P->Element;
}

Position CircularDoublyLinkedListAdvance(Position P)
{
    return P->Next;
}

Position CircularDoublyLinkedListFirstNode(CircularDoublyLinkedList L)
{
    return L->Next;
}

Position CircularDoublyLinkedListLastNode(CircularDoublyLinkedList L)
{
    return L->Prior;
}

Position CircularDoublyLinkedListFindMiddleNode(CircularDoublyLinkedList L)
{
    Position Slow, Fast;
    
    Slow = L;
    Fast = L;
    while (Fast->Next != L && Fast->Next->Next != L) {
        Slow = Slow->Next;
        Fast = Fast->Next->Next;
    }
    return Fast->Next == L ? Slow : Slow->Next;
}

Position CircularDoublyLinkedListFindNodeFromTail(CircularDoublyLinkedList L, unsigned int Distance)
{
    Position P, TempCell;
    unsigned int index;
    
    index = 0;
    TempCell = L;
    while (index < Distance && TempCell->Next != L) {
        TempCell = TempCell->Next;
        index++;
    }
    
    if (index < Distance)
        return NULL;
    
    P = L;
    while (TempCell->Next != L) {
        P = P->Next;
        TempCell = TempCell->Next;
    }
    return P;
}

Position CircularDoublyLinkedListFind(CircularDoublyLinkedList L, int Element)
{
    Position P;
    
    P = L->Next;
    while (P->Next != L && P->Element != Element)
        P = P->Next;
    return P == L ? NULL : P;
}

Position CircularDoublyLinkedListFindPrevious(CircularDoublyLinkedList L, int Element)
{
    Position P;
    
    P = L;
    while (P->Next != L && P->Next->Element != Element)
        P = P->Next;
    return P->Next == L ? NULL : P;
}

Position CircularDoublyLinkedListFindPrior(CircularDoublyLinkedList L, Position P)
{
    Position TempCell;
    
    assert(P != NULL);
    TempCell = L;
    while (TempCell->Next != L && TempCell->Next != P)
        TempCell = TempCell->Next;
    return TempCell->Next == P ? TempCell : NULL;
}

Position CircularDoublyLinkedListFindBadLoopEntrance(CircularDoublyLinkedList L, int *Flag)
{
    Position Slow, Fast;
    
    *Flag = 0;
    Slow = L;
    Fast = L;
    
    while (Fast->Next != L && Fast->Next->Next != L) {
        Slow = Slow->Next;
        Fast = Fast->Next->Next;
        if (Slow == Fast) {
            *Flag = 1;
            break;
        }
    }
    
    if (*Flag == 1) {
        Slow = L;
        while (Slow != Fast) {
            Slow = Slow->Next;
            Fast = Fast->Next;
        }
        return Slow;
    }
    
    Slow = L;
    Fast = L;
    
    while (Fast->Prior != L && Fast->Prior->Prior != L) {
        Slow = Slow->Prior;
        Fast = Fast->Prior->Prior;
        if (Slow == Fast) {
            *Flag = -1;
            break;
        }
    }
    
    if (*Flag == -1) {
        Slow = L;
        while (Slow != Fast) {
            Slow = Slow->Prior;
            Fast = Fast->Prior;
        }
        return Slow;
    }
    return NULL;
}

void CircularDoublyLinkedListAppendList(CircularDoublyLinkedList L, CircularDoublyLinkedList A)
{
    Position LTail, ATail;
    
    if (CircularDoublyLinkedListIsEmpty(A))
        return;
    
    LTail = CircularDoublyLinkedListLastNode(L);
    ATail = CircularDoublyLinkedListLastNode(A);
    LTail->Next = A->Next;
    LTail->Next->Prior = LTail;
    ATail->Next = L;
    L->Prior = ATail;
}

void CircularDoublyLinkedListInsertElement(CircularDoublyLinkedList L, Position P, int Element)
{
    Position TempCell;
    
    TempCell = calloc(1, sizeof(struct Node));
    assert(TempCell != NULL);
    TempCell->Element = Element;
    TempCell->Next = P->Next;
    TempCell->Next->Prior = TempCell;
    TempCell->Prior = P;
    P->Next =TempCell;
}

void CircularDoublyLinkedListDeleteElement(CircularDoublyLinkedList L, int Element)
{
    Position Prior, TempCell;
    
    Prior = CircularDoublyLinkedListFindPrevious(L, Element);
    TempCell = Prior->Next;
    Prior->Next = TempCell->Next;
    Prior->Next->Prior = Prior;
    free(TempCell);
}

void CircularDoublyLinkedListDeleteNode(CircularDoublyLinkedList L, Position P)
{
    assert(L != P);
    
    P->Prior->Next = P->Next;
    P->Next->Prior = P->Prior;
    free(P);
}

void CircularDoublyLinkedListDeleteList(CircularDoublyLinkedList L)
{
    Position P, TempCell;
    
    P = L->Next;
    L->Next = L;
    L->Prior = L;
    while (P != L) {
        TempCell = P->Next;
        free(P);
        P = TempCell;
    }
}

void CircularDoublyLinkedListRevere(CircularDoublyLinkedList L)
{
    Position P, R, TempCell;
    
    P = L->Next;
    TempCell = L;
    L->Prior = L->Next;
    while (P != L) {
        R = P->Next;
        P->Next = TempCell;
        P->Prior = R;
        TempCell = P;
        P = R;
    }
    L->Next = TempCell;
}

void CircularDoublyLinkedListPrint(CircularDoublyLinkedList L)
{
    Position P;
    
    P = L->Next;
    while (P != L) {
        printf("%d, ", P->Element);
        P = P->Next;
    }
    putchar('\n');
}

void CircularDoublyLinkedListPrintReversing(CircularDoublyLinkedList L)
{
    Position P;
    
    P = L->Prior;
    while (P != L) {
        printf("%d, ", P->Element);
        P = P->Prior;
    }
    putchar('\n');
}
