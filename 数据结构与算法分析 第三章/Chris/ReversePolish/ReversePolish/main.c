//
//  main.c
//  ReversePolish
//
//  Created by JianZhang on 2017/3/22.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "Stack.h"

int calculate(int n1, int n2, int op);

int main(int argc, const char * argv[])
{
    int FILE[] = {6, 5, 2, 3, '+', 8, '*', '+', 3, '+', '*'};
    int index, ch;
    Stack S;
    
    S = StackCreate();
    
    for (index = 0; index < 11; index++) {
        ch = FILE[index];
        if (ch == '+' || ch == '*')
            StackPush(S, calculate(StackPop(S), StackPop(S), ch));
        else
            StackPush(S, ch);
    }
    
    printf("%d\n", StackPop(S));
    
    return 0;
}

int calculate(int n1, int n2, int op)
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
