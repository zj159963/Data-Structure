//
//  main.c
//  Stack
//
//  Created by JianZhang on 2017/3/21.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include "Stack.h"

int main(int argc, const char * argv[])
{
    Stack S;
    int index;
    
    S = StackCreate();
    
    for (index = 0; index < 10; index++)
        StackPush(S, index);
    
    StackPrint(S);
    
    printf("%d, ", StackPop(S));
    printf("%d, ", StackPop(S));
    printf("%d, ", StackPop(S));
    
    StackPush(S, 20);
    
    putchar('\n');
    StackPrint(S);
    return 0;
}
