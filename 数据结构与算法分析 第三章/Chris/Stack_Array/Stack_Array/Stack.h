//
//  Stack.h
//  Stack_Array
//
//  Created by JianZhang on 2017/3/21.
//  Copyright © 2017年 NUT. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

typedef int ElementType;
struct Stack_t;
typedef struct Stack_t *Stack;
Stack StackCreate(unsigned int Capacity);

int StackIsEmpty(Stack S);
int StackIsFull(Stack S);

void StackEmpty(Stack S);
void StackDispose(Stack S);
void StackPrint(Stack S);

void StackPush(Stack S, ElementType E);
ElementType StackPop(Stack S);

#endif /* Stack_h */
