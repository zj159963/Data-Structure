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

struct Node {
    ElementType Element;
    Position Next;
};

int const HEAD_FALG = INT_MAX;

LinkedList CreateList(const ElementType *array, int count)
{
    LinkedList L;
    Position P, TmpCell;
    int index = 0;
    
    L = malloc(sizeof(struct Node));
    assert(L != NULL);
    L->Element = HEAD_FALG; // flag
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
    
    /// head -> 0 -> 1 -> 2 -> 3 -> 0
    /// 环的长度 L = 4
    /// 走了 X 步，Fast 走了 X * 2 距离
    /// Slow 走了 X
    
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

ElementType Retrieve(Position P)
{
    return P->Element;
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
    
    /// head -> 0 -> 1 -> 2 -> NULL
    /// E = 3
    
    /// Positon?
    
    P = L->Next;
    while (P != NULL && P->Element != E)
        P = P->Next;
    
    return P;
}

Position FindPrevious(ElementType E, LinkedList L)
{
    /// head -> 0 -> 1 -> 2 -> null
    /// p = 5, L = head
    Position P;
    
    P = L;
    while (P->Next != NULL && P->Next->Element != E)
        P = P->Next;
    return P->Next == NULL ? NULL : P;
}

Position FindPrior(LinkedList L, Position P)
{
    Position TempCell;
    
    assert(P != NULL);
    TempCell = L;
    while (TempCell->Next != NULL && TempCell->Next != P)
        TempCell = TempCell->Next;
    return TempCell->Next == NULL ? NULL : TempCell;
}

Position FindFromTail(unsigned int Distance, LinkedList L)
{
    Position P, TmpCell;
    int index;
    
    /// head -> 0 -> 1 -> 2 -> 3 -> ... -> 10 -> NULL
    
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
    
    
    // slow -> next， fast -> next ->next
    // 2 N , N
    // lentgh = X (X 是奇数)
    // Fast 走了 2 * N， slow 就走了 N
    // N = (X - 1) / 2
    // 想要的结果 (X - 1) / 2 + 1
    
    /// head -> 0 -> 1 -> 2
    
    Slow = L;
    Fast = L;
    
    while (Fast != NULL && Fast->Next != NULL) {
        Slow = Slow->Next;
        Fast = Fast->Next->Next;
    }
    return Fast->Next == NULL ? Slow : Slow ->Next;
}

Position Advance(Position P)
{
    return P->Next;
}

void Append(LinkedList L, LinkedList A)
{
    // h1 -> 0 -> 1 -> 2 -> NULL
    
    Last(L)->Next = A->Next;
    free(A);
}

void Insert(ElementType E, Position P, LinkedList L)
{
    Position TmpCell;
    
    TmpCell = malloc(sizeof(struct Node));
    assert(TmpCell != NULL);
    TmpCell->Element = E;
    
    // 1
    // h -> 0 -> 2 -> NULL
    
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteNode(Position NodeToDelete, LinkedList L)
{
    Position TempCell, Prior;
    
    assert(L != NodeToDelete);
    
    if (IsLast(NodeToDelete, L)) {
        
        /// head -> 0 -> 1 -> null
        
        Prior = FindPrior(L, NodeToDelete);
        free(NodeToDelete);
        Prior->Next = NULL;
        return;
    }
    
    TempCell = NodeToDelete->Next;
    
    
    
    NodeToDelete->Next = TempCell->Next;
    NodeToDelete->Element = TempCell->Element;
    free(TempCell);
}

void Delete(ElementType E, LinkedList L)
{
    Position P, TmpCell;
    
    /// head -> 0 -> 1 -> 2 -> null
    // E = 0
    
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
    /// mArray removeAll
    Position P, TmpCell;
    /// head -> NULL
    ///  1 -> 2 -> null
    P = L->Next;
    L->Next = NULL;
    while (P != NULL) {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}

void Reverse(LinkedList L)
{
    Position P, R, Tmp;
    //         P    R
    // head -> 0 -> 1 -> 2 -> NULL
    // head -> 2 -> 1 -> 0 -> NULL
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

void PrintLots(LinkedList SourceList, LinkedList IndexList)
{
    Position P, IndexPosition;
    int index;
    
    if (IsEmpty(IndexList)) {
        printf("Empty Indices.\n");
        return;
    }
    
    index = 0;
    P = SourceList->Next;
    IndexPosition = IndexList->Next;
    
    while (IndexPosition != NULL) {
        if (index == IndexPosition->Element) {
            printf("%d, ", P->Element);
            IndexPosition = IndexPosition->Next;
        }
        
        index++;
        P = P->Next;
    }
    putchar('\n');
}
