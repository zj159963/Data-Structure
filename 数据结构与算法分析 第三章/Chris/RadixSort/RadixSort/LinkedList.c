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
#include <math.h>
#include "LinkedList.h"

int const HEAD_FALG = INT_MAX;

LinkedList LinkedListCreate(const ElementType *array, int count)
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

LinkedList LinkedListCopy(LinkedList L)
{
    LinkedList Copy;
    Position P, CP, TempCell;
    
    Copy = calloc(1, sizeof(struct Node));
    assert(Copy != NULL);
    
    P = L->Next;
    CP = Copy;
    while (P != NULL) {
        TempCell = calloc(1, sizeof(struct Node));
        assert(TempCell != NULL);
        
        TempCell->Element = P->Element;
        CP->Next = TempCell;
        CP = TempCell;
        P = P->Next;
    }
    return Copy;
}

int LinkedListLength(LinkedList L)
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

int LinkedListIsEmpty(LinkedList L)
{
    return L->Next == NULL;
}

int LinkedListIsLastNode(Position P, LinkedList L)
{
    return P->Next == NULL;
}

int LinkedListIsFirstNode(Position P, LinkedList L)
{
    return P == L->Next;
}

int LinkedListIsLoop(LinkedList L)
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

int LinkedListLoopLength(LinkedList L)
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

Position LinkedListFirstNode(LinkedList L)
{
    return L->Next;
}

Position LinkedListLastNode(LinkedList L)
{
    Position P;
    
    P = L;
    while (P->Next)
        P = P->Next;
    
    return P;
}

Position LinkedListFindNode(ElementType E, LinkedList L)
{
    Position P;
    
    P = L->Next;
    while (P != NULL && P->Element != E)
        P = P->Next;
    
    return P;
}

Position LinkedListFindPreviousNode(ElementType E, LinkedList L)
{
    Position P;
    
    P = L;
    while (P->Next != NULL && P->Next->Element != E)
        P = P->Next;
    return P->Next == NULL ? NULL : P;
}

Position LinkedListFindPriorNode(LinkedList L, Position P)
{
    Position TempCell;
    
    assert(P != NULL);
    TempCell = L;
    while (TempCell->Next != NULL && TempCell->Next != P)
        TempCell = TempCell->Next;
    return TempCell;
}

Position LinkedListFindMidNode(ElementType E, LinkedList L)
{
    Position Slow, Fast;
    
    Slow = L;
    Fast = L;
    
    while (Fast != NULL && Fast->Next != NULL) {
        Slow = Slow->Next;
        Fast = Fast->Next->Next;
    }
    return Fast->Next == NULL ? Slow : Slow ->Next;
}

Position LinkedListFindNodeFromTail(unsigned int Distance, LinkedList L)
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

Position LinkedListFindLoopEntrance(LinkedList L)
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

void LinkedListAppend(LinkedList L, LinkedList A)
{
    LinkedListLastNode(L)->Next = A->Next;
    free(A);
}

void LinkedListInsertElement(ElementType E, Position P, LinkedList L)
{
    Position TmpCell;
    
    TmpCell = malloc(sizeof(struct Node));
    assert(TmpCell != NULL);
    TmpCell->Element = E;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void LinkedListDeleteNode(Position NodeToDelete, LinkedList L)
{
    Position TempCell, Prior;
    
    assert(L != NodeToDelete);
    
    if (LinkedListIsLastNode(NodeToDelete, L)) {
        Prior = LinkedListFindPriorNode(L, NodeToDelete);
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

void LinkedListDeleteElement(ElementType E, LinkedList L)
{
    Position P, TmpCell;
    
    P = LinkedListFindPreviousNode(E, L);
    if (P != NULL) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
        TmpCell = NULL;
    }
}

void LinkedListDeleteList(LinkedList L)
{
    Position P, TmpCell;
    
    P = L->Next;
    L->Next = NULL;
    while (P != NULL) {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}

void LinkedListReverse(LinkedList L)
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

void LinkedListRadixSort(LinkedList L, unsigned int Places)
{
    int index, jndex, place = 0;
    LinkedList *Buckets, TempList;
    Position P, Q, TempCell;
    
    Buckets = calloc(10, sizeof(LinkedList));
    assert(Buckets != NULL);
    
    for (index = 0; index < 10; index++) {
        Buckets[index] = calloc(1, sizeof(struct Node));
        assert(Buckets[index] != NULL);
    }
    
    TempList = LinkedListCopy(L);
    
    for (index = 0; index < Places; index++) {
        P = TempList;
        while (P->Next != NULL) {
            TempCell = calloc(1, sizeof(struct Node));
            assert(TempCell != NULL);
            
            place = P->Next->Element;
            for (jndex = 0; jndex <= index; jndex++) {
                if (index == 0 || jndex == index)
                    place %= 10;
                else
                    place /= 10;
            }
            
            TempCell->Element = P->Next->Element;
            TempCell->Next = LinkedListLastNode(Buckets[place])->Next;
            LinkedListLastNode(Buckets[place])->Next = TempCell;
            P = P->Next;
        }
        LinkedListDeleteList(TempList);
        
        Q = TempList;
        for (jndex = 0; jndex < 10; jndex++) {
            P = Buckets[jndex]->Next;
            while (P != NULL) {
                TempCell = calloc(1, sizeof(struct Node));
                assert(TempCell != NULL);
                TempCell->Element = P->Element;
                Q->Next = TempCell;
                Q = TempCell;
                P = P->Next;
            }
        }
        
        for (jndex = 0; jndex < 10; jndex++) {
            LinkedListDeleteList(Buckets[jndex]);
        }
    }
    
    for (index = 0; index < 10; index++)
        free(Buckets[index]);
    
    LinkedListDeleteList(L);
    
    L->Next = TempList->Next;
    free(TempList);
}

void LinkedListPrint(LinkedList L)
{
    Position P;
    
    if (LinkedListIsEmpty(L)) {
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
