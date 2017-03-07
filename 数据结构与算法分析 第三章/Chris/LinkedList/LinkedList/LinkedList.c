//
//  LinkedList.c
//  LinkedList
//
//  Created by JianZhang on 2017/2/27.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "LinkedList.h"

int const HEAD_FALG = INT_MAX;

LinkedList CreateList(const ElementType *array, int count)
{
    LinkedList L;
    Position P, TmpCell;
    int index = 0;
    
    L = malloc(sizeof(struct Node));
    L->Element = HEAD_FALG;
    P = L;
    
    for (index = 0; index < count; index++) {
        TmpCell = malloc(sizeof(struct Node));
        assert(TmpCell != NULL);
        TmpCell->Element = array[index];
        TmpCell->Next = NULL;
        P->Next = TmpCell;
        P = TmpCell;
    }
    return L;
}

int Length(LinkedList L)
{
    int Length;
    Position P;
    
    Length = 0;
    P = L->Next;
    
    while (P != NULL) {
        P = P->Next;
        Length++;
    }
    return Length;
}

int IsEmpty(LinkedList L)
{
    return L->Next == NULL;
}

int IsLast(Position P, LinkedList L)
{
    return P->Next == NULL;
}

int IsFirst(Position P, LinkedList L)
{
    return P == L->Next;
}

int IsLoop(LinkedList L)
{
    Position Fast, Slow;
    
    Fast = L;
    Slow = L;
    
    while (Fast->Next != NULL && Fast->Next->Next != NULL) {
        Fast = Fast->Next->Next;
        Slow = Slow->Next;
        if (Fast == Slow)
            return 1;
    }
    return 0;
}

int LoopLength(LinkedList L)
{
    int length;
    Position Fast, Slow;
    
    Fast = L;
    Slow = L;
    
    while (Fast->Next != NULL && Fast->Next->Next != NULL) {
        Fast = Fast->Next->Next;
        Slow = Slow->Next;
        if (Fast == Slow)
            break;
    }
    
    if (Fast != Slow)
        return 0;
    
    length = 1;
    Fast = Fast->Next;
    
    while (Fast != Slow) {
        Fast = Fast->Next;
        length++;
    }
    return length;
}

Position First(LinkedList L)
{
    return L->Next;
}

Position Last(LinkedList L)
{
    Position P;
    
    P = L;
    while (P->Next)
        P = P->Next;
    
    return P;
}

Position Find(ElementType E, LinkedList L)
{
    Position P;
    
    P = L->Next;
    while (P != NULL && P->Element != E)
        P = P->Next;
    
    return P;
}

Position FindPrevious(ElementType E, LinkedList L)
{
    Position P;
    
    P = L;
    while (P->Next != NULL && P->Next->Element != E)
        P = P->Next;
    
    return P == L ? NULL : P;
}

Position FindPrior(LinkedList L, Position P)
{
    Position TempCell;
    
    TempCell = L;
    while (TempCell != NULL && TempCell->Next != P)
        TempCell = TempCell->Next;
    return TempCell;
}

Position FindFromTail(unsigned int Distance, LinkedList L)
{
    Position P, TmpCell;
    int index;
    
    TmpCell = L;
    
    for (index = 0; index < Distance; index++) {
        TmpCell = TmpCell->Next;
        if (TmpCell == NULL)
            return NULL;
    }
    
    P = L;
    while (TmpCell->Next != NULL) {
        P = P->Next;
        TmpCell = TmpCell->Next;
    }
    return P;
}

Position FindLoopEntrance(LinkedList L)
{
    Position Slow, Fast;
    
    Slow = L;
    Fast = L;
    
    while (Fast->Next != NULL && Fast->Next->Next != NULL) {
        Slow = Slow->Next;
        Fast = Fast->Next->Next;
        if (Slow == Fast)
            break;
    }
    
    if (Slow != Fast)
        return NULL;
    
    Slow = L;
    
    while (Slow != Fast) {
        Slow = Slow->Next;
        Fast = Fast->Next;
    }
    return Slow;
}

Position FindMid(ElementType E, LinkedList L)
{
    Position Slow, Fast;
    
    Slow = L;
    Fast = L;
    
    while (Fast != NULL && Fast->Next != NULL) {
        Slow = Slow->Next;
        Fast = Fast->Next->Next;
    }
    return Slow;
}

void Append(LinkedList L, LinkedList A)
{
    Last(L)->Next = A->Next;
    free(A);
}

void Insert(ElementType E, Position P, LinkedList L)
{
    Position TmpCell;
    
    TmpCell = malloc(sizeof(struct Node));
    assert(TmpCell != NULL);
    TmpCell->Element = E;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteNode(Position NodeToDelete, LinkedList L)
{
    Position TempCell, Prior;
    
    assert(L != NodeToDelete);
    
    if (IsLast(NodeToDelete, L)) {
        Prior = FindPrior(L, NodeToDelete);
        free(NodeToDelete);
        Prior->Next = NULL;
        return;
    }
    
    TempCell = NodeToDelete->Next;
    
    NodeToDelete->Next = TempCell->Next;
    NodeToDelete->Element = TempCell->Element;
    TempCell = NULL;
    free(TempCell);
}

void Delete(ElementType E, LinkedList L)
{
    Position P, TmpCell;
    
    P = FindPrevious(E, L);
    if (P != NULL) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
        TmpCell = NULL;
    }
}

void DeleteList(LinkedList L)
{
    Position P, TmpCell;
    
    P = L->Next;
    L->Next = NULL;
    while (P) {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}

void Reverse(LinkedList L)
{
    Position P, R, Tmp;
    
    P = L->Next;
    Tmp = NULL;
    while (P != NULL) {
        R = P->Next;
        P->Next = Tmp;
        Tmp = P;
        P = R;
    }
    L->Next = Tmp;
}

void PrintList(LinkedList L)
{
    Position P;
    
    if (IsEmpty(L)) {
        printf("Empty List\n");
        return;
    }

    P = L->Next;
    
    while (P != NULL) {
        printf("%d ", P->Element);
        P = P->Next;
    }
    
    printf("\n");
}
