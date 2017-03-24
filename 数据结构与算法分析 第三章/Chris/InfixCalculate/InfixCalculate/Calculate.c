//
//  PostfixCalculate.c
//  InfixCalculate
//
//  Created by JianZhang on 2017/3/22.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "Calculate.h"
#include "Stack.h"

static int Calculate(int n1, int n2, int op);
static int PrioriorityOfOperation(int op);

int PostfixCalculate(const int *Input, unsigned int Count)
{
    Stack S;
    int index, Result, ch;
    
    S = StackCreate();
    
    for (index = 0; index < Count; index++) {
        ch = Input[index];
        
        if (ch == '+' || ch == '*')
            StackPush(S, Calculate(StackPop(S), StackPop(S), ch));
        else
            StackPush(S, ch);
    }
    
    Result = StackPop(S);
    assert(StackIsEmpty(S));
    StackDispose(S);
    
    return Result;
}

int InfixCalculate(const int *Input, unsigned int Count)
{
    int *ConvertedInput, ConvertedInputCount, ch;
    Stack S, ConvertedStack;
    unsigned int index;
    
    ConvertedStack = StackCreate();
    S = StackCreate();
    
    for (index = 0; index < Count; index++) {
        ch = Input[index];
        
        if (ch == '+' || ch == '*') {
            while (!StackIsEmpty(S) && StackTop(S) != '(' &&
                   PrioriorityOfOperation(StackTop(S)) >= PrioriorityOfOperation(ch))
                StackPush(ConvertedStack, StackPop(S));
            StackPush(S, ch);
        } else if (ch == '(') {
            StackPush(S, ch);
        } else if (ch == ')') {
            while (StackTop(S) != '(')
                StackPush(ConvertedStack, StackPop(S));
            StackPop(S);
        } else {
            StackPush(ConvertedStack, ch);
        }
    }
    
    while (!StackIsEmpty(S))
        StackPush(ConvertedStack, StackPop(S));
    
    StackMakeEmpty(S);
    
    while (!StackIsEmpty(ConvertedStack))
        StackPush(S, StackPop(ConvertedStack));
    
    ConvertedInputCount = StackDepth(S);
    ConvertedInput = (int*)calloc(ConvertedInputCount, sizeof(int));
    index = 0;
    
    while (!StackIsEmpty(S)) {
        ConvertedInput[index] = StackPop(S);
        index++;
    }
    
    StackDispose(S);
    StackDispose(ConvertedStack);
    
    for (index = 0; index < ConvertedInputCount; index++) {
        printf("%d, ", ConvertedInput[index]);
    }
    putchar('\n');
    
    return PostfixCalculate(ConvertedInput, ConvertedInputCount);
}

static int Calculate(int n1, int n2, int op)
{
    switch (op) {
        case '+':
            return n1 + n2;
        case '*':
            return n1 * n2;
        default:
            assert(0);
            return 0;
    }
}

static int PrioriorityOfOperation(int op)
{
    if (op == '+')
        return 0;
    
    if (op == '*')
        return 1;
    
    return 2;
}
