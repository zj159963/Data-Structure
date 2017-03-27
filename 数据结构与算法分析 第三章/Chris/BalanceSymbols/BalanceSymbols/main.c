//
//  main.c
//  BalanceSymbols
//
//  Created by JianZhang on 2017/3/22.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "Stack.h"

int main(int argc, const char * argv[])
{
    // 栈
    const char *File = "Stack StackCreate(unsigned int Capacity)\
    {\
        Stack S;\
      \
        S = calloc(1, sizeof(struct Stack_t));\
        assert(S != NULL);\
        \
        S->Elements = calloc(Capacity, sizeof(ElementType));\
        assert(S->Elements != NULL);\
        \
        S->Capacity = Capacity;\
        S->Top = StackEmptyTop;\
        \
        return S;\
    }{";
    
    Stack S;
    char ch;
    unsigned int len, index;
    
    len = (unsigned int)strlen(File);
    S = StackCreate(len);
    
    for (index = 0; index < len; index++) {
        ch = File[index];
        
        if (ch == '(' || ch == '[' || ch == '{')
            StackPush(S, ch);
        else if (ch == ')' && StackPop(S) != '(')
            break;
        else if (ch == ']' && StackPop(S) != '[')
            break;
        else if (ch == '}' && StackPop(S) != '{')
            break;
    }
    
    printf("The file is%s symbol balanced.\n", index == len && StackIsEmpty(S) ? "" : "n't");
    return 0;
}
