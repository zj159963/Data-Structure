//
//  Stack.c
//  Stack_Array
//
//  Created by JianZhang on 2017/3/21.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static int const StackEmptyTop = -1;

Stack StackCreate(unsigned int Capacity)
{
    Stack S;
    
    S = calloc(1, sizeof(struct Stack_t));
    assert(S != NULL);
    
    S->Elements = calloc(Capacity, sizeof(ElementType));
    assert(S->Elements != NULL);
    
    S->Capacity = Capacity;
    S->Top = StackEmptyTop;

    return S;
}

int StackIsEmpty(Stack S)
{
    return S->Top == StackEmptyTop;
}

int StackIsFull(Stack S)
{
    return S->Top == S->Capacity - 1;
}

void StackEmpty(Stack S)
{
    S->Top = StackEmptyTop;
}

void StackDispose(Stack S)
{
    free(S->Elements);
    free(S);
}

void StackPrint(Stack S)
{
    int index;
    
    if (StackIsEmpty(S)) {
        printf("Empty Stack!");
        return;
    }
    
    for (index = S->Top; index >= 0; index--)
        printf("%c, ", S->Elements[index]);
    putchar('\n');
}

void StackPush(Stack S, ElementType E)
{
    assert(!StackIsFull(S));
    S->Elements[++S->Top] = E;
}

ElementType StackPop(Stack S)
{
    assert(!StackIsEmpty(S));
    return S->Elements[S->Top--];
}
