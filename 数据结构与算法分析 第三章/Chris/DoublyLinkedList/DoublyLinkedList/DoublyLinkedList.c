//
//  DoublyLinkedList.c
//  DoublyLinkedList
//
//  Created by JianZhang on 2017/3/7.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdlib.h>
#include <assert.h>
#include "DoublyLinkedList.h"

struct Node {
    int Element;
    Position Prior;
    Position Next;
};

DoublyLinkedList DoublyLinkedListCreate(const int Source[], unsigned int count)
{
    DoublyLinkedList List;
    Position P, TempCell;
    unsigned int index;
    
    List = calloc(1, sizeof(struct Node));
    assert(List != NULL);
    P = List;
    
    for (index = 0; index < count; index++) {
        TempCell = calloc(1, sizeof(struct Node));
        assert(TempCell != NULL);
        TempCell->Element = Source[index];
        P->Next = TempCell;
        TempCell->Prior = P;
        P = TempCell;
    }
    return List;
}

int DoublyLinkedListIsLegal(DoublyLinkedList L)
{
    Position P, TempCell;
    
    P = L;
    TempCell = L->Next;
    
    while (TempCell != NULL && TempCell->Prior == P) {
        P = TempCell;
        TempCell = TempCell->Next;
    }
    
    return TempCell == NULL;
}

int DoublyLinkedListIsEmpty(DoublyLinkedList L)
{
    return L->Next == NULL;
}

int DoublyLinkedListIsFirstNode(DoublyLinkedList L, Position P)
{
    assert(P != NULL);
    return P == L->Next;
}

int DoublyLinkedListIsLastNode(DoublyLinkedList L, Position P)
{
    assert(P != NULL);
    return P->Next == NULL;
}

int DoublyLinkedListLength(DoublyLinkedList L)
{
    unsigned int length;
    Position P;
    
    length = 0;
    P = L->Next;
    while (P != NULL) {
        length++;
        P = P->Next;
    }
    return length;
}

int DoublyLinkedListIsBadLoop(DoublyLinkedList L)
{
    Position Slow, Fast;
    
    Slow = L;
    Fast = L;
    
    while (Fast->Next != NULL && Fast->Next->Next != NULL) {
        Slow = Slow->Next;
        Fast = Fast->Next->Next;
        if (Slow == Fast)
            return 1;
    }
    
    while (Fast->Next != NULL)
        Fast = Fast->Next;
    
    Slow = Fast;
    
    while (Fast->Prior != NULL && Fast->Prior->Prior != NULL) {
        Slow = Slow->Prior;
        Fast = Fast->Prior->Prior;
        if (Slow == Fast)
            return -1;
    }
    return 0;
}

int DoublyLinkedListBadLoopLength(DoublyLinkedList L, int *Flag)
{
    int length;
    Position Slow, Fast;
    
    Slow = L;
    Fast = L;
    *Flag = 0;
    
    while (Fast->Next != NULL && Fast->Next->Next != NULL) {
        Slow = Slow->Next;
        Fast = Fast->Next->Next;
        if (Slow == Fast) {
            *Flag = 1;
            break;
        }
    }
    
    if (*Flag > 0) {
        length = 1;
        Fast = Fast->Next;
        while (Slow != Fast) {
            length++;
            Fast = Fast->Next;
        }
        return length;
    }
    
    while (Fast->Next != NULL)
        Fast = Fast->Next;
    
    Slow = Fast;
    
    while (Fast->Prior != NULL && Fast->Prior->Prior != NULL) {
        Slow = Slow->Prior;
        Fast = Fast->Prior->Prior;
        if (Slow == Fast) {
            *Flag = -1;
            break;
        }
    }
    
    if (*Flag < 0) {
        length = 1;
        Fast = Fast->Prior;
        while (Slow != Fast) {
            length++;
            Fast = Fast->Prior;
        }
        return length;
    }
    return 0;
}

int DoublyLinkedListRetrieve(Position P)
{
    return P->Element;
}

Position DoublyLinkedListFirstNode(DoublyLinkedList L)
{
    return L->Next;
}

Position DoublyLinkedListLastNode(DoublyLinkedList L)
{
    Position P;
    
    P = L;
    while (P->Next)
        P = P->Next;
    return P;
}

Position DoublyLinkedListMiddleNode(DoublyLinkedList L)
{
    Position Slow, Fast;
    
    Slow = L;
    Fast = L;
    
    while (Fast->Next != NULL && Fast->Next->Next != NULL) {
        Slow = Slow->Next;
        Fast = Fast->Next->Next;
    }
    return Fast->Next == NULL ? Slow : Slow ->Next;
}

Position DoublyLinkedListFindNode(DoublyLinkedList L, int Element)
{
    Position P;
    
    P = L->Next;
    while (P != NULL && P->Element != Element)
        P = P->Next;
    return P;
}

Position DoublyLinkedListFindPreviousNode(DoublyLinkedList L, int Element)
{
    Position P;
    
    P = L;
    while (P->Next != NULL && P->Next->Element != Element)
        P = P->Next;
    return P->Next == NULL ? NULL : P;
}

Position DoublyLinkedListFindPriorNode(DoublyLinkedList L, Position P)
{
    Position TempCell;
    
    assert(P != NULL);
    TempCell = L;
    while (TempCell->Next != NULL && TempCell->Next != P)
        TempCell = TempCell->Next;
    return TempCell;
}

Position DoublyLinkedListFindNodeFromTail(DoublyLinkedList L, unsigned int Distance)
{
    unsigned int index;
    Position P, TempCell;
    
    index = 0;
    TempCell = L;
    while (TempCell->Next != NULL && index < Distance) {
        TempCell = TempCell->Next;
        index++;
    }
    
    if (index < Distance)
        return NULL;
    
    P = L;
    while (TempCell->Next != NULL) {
        P = P->Next;
        TempCell = TempCell->Next;
    }
    return P;
}

Position DoublyLinkedListFindBadLoopEntrance(DoublyLinkedList L, int *Flag)
{
    Position Slow, Fast, Tail;
    
    Slow = L;
    Fast = L;
    *Flag = 0;
    
    while (Fast->Next != NULL && Fast->Next->Next != NULL) {
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
    
    while (Fast->Next != NULL)
        Fast = Fast->Next;
    
    Tail = Fast;
    Slow = Fast;
    
    while (Fast->Prior != NULL && Fast->Prior->Prior) {
        Slow = Slow->Prior;
        Fast = Fast->Prior->Prior;
        if (Slow == Fast) {
            *Flag = -1;
            break;
        }
    }
    
    if (*Flag == -1) {
        Slow = Tail;
        while (Slow != Fast) {
            Slow = Slow->Prior;
            Fast = Fast->Prior;
        }
        return Slow;
    }
    return NULL;
}

Position DoublyLinkedListAdvance(Position P)
{
    return P->Next;
}

void DoublyLinkedListAppendList(DoublyLinkedList L, DoublyLinkedList A)
{
    Position LTail;
    
    if (DoublyLinkedListIsEmpty(A))
        return;
    
    LTail = DoublyLinkedListLastNode(L);
    
    LTail->Next = A->Next;
    A->Next->Prior = LTail;
}

void DoublyLinkedListInsertElement(DoublyLinkedList L, Position P, int Element)
{
    Position TempCell;
    
    TempCell = calloc(1, sizeof(struct Node));
    assert(TempCell != NULL);
    TempCell->Element = Element;
    TempCell->Prior = P;
    TempCell->Next = P->Next;
    P->Next = TempCell;
    if (TempCell->Next != NULL)
        TempCell->Next->Prior = TempCell;
}

void DoublyLinkedListDeleteElement(DoublyLinkedList L, int Element)
{
    Position P, TempCell;
    
    P = DoublyLinkedListFindPreviousNode(L, Element);
    
    if (P == NULL)
        return;
    
    TempCell = P->Next;
    P->Next = TempCell->Next;
    if (TempCell->Next != NULL)
        TempCell->Next->Prior = P;
    free(TempCell);
}

void DoublyLinkedListDeleteNode(DoublyLinkedList L, Position P)
{
    assert(L != P);
    P->Prior->Next = P->Next;
    if (P->Next != NULL)
        P->Next->Prior = P->Prior;
    free(P);
}

void DoublyLinkedListDeleteList(DoublyLinkedList L)
{
    Position P, TempCell;
    
    P = L->Next;
    L->Next = NULL;
    while (P != NULL) {
        TempCell = P->Next;
        free(P);
        P = TempCell;
    }
}

void DoublyLinkedListReverse(DoublyLinkedList L)
{
    Position P, R, TempCell;
    
    P = L->Next;
    TempCell = NULL;
    while (P != NULL) {
        R = P->Next;
        P->Next = TempCell;
        if (TempCell != NULL)
            TempCell->Prior = P;
        TempCell = P;
        P = R;
    }
    L->Next = TempCell;
    TempCell->Prior = L;
}

void DoublyLinkedListPrint(DoublyLinkedList L)
{
    Position P;
    
    P = L->Next;
    while (P != NULL) {
        printf("%d, ", P->Element);
        P = P->Next;
    }
}
