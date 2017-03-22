//
//  Stack.c
//  Stack
//
//  Created by JianZhang on 2017/3/21.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"

Stack StackCreate(void)
{
    Stack S;
    
    S = calloc(1, sizeof(struct Node));
    assert(S != NULL);
    StackMakeEmpty(S);
    return S;
}

int StackIsEmpty(Stack S)
{
    return S->Next == NULL;
}

void StackMakeEmpty(Stack S)
{
    PtrToNode P, TempCell;
    
    P = S->Next;
    S->Next = NULL;
    
    while (P != NULL) {
        TempCell = P->Next;
        free(P);
        P = TempCell;
    }
}

void StackDispose(Stack S)
{
    StackMakeEmpty(S);
    free(S);
}

void StackPush(Stack S, ElementType E)
{
    PtrToNode TempCell;
    
    TempCell = calloc(1, sizeof(struct Node));
    assert(TempCell != NULL);
    TempCell->Element = E;
    TempCell->Next = S->Next;
    S->Next = TempCell;
}

ElementType StackPop(Stack S)
{
    ElementType E;
    PtrToNode P;
    
    assert(!StackIsEmpty(S));
    
    P = S->Next;
    E = P->Element;
    S->Next = P->Next;
    free(P);
    return E;
}

void StackPrint(Stack S)
{
    PtrToNode P;
    
    if (StackIsEmpty(S)) {
        printf("Empty Stack.\n");
        return;
    }
    
    P = S->Next;
    while (P != NULL) {
        printf("%d, ", P->Element);
        P = P->Next;
    }
    putchar('\n');
}
