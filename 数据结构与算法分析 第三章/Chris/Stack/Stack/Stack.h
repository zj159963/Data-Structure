//
//  Stack.h
//  Stack
//
//  Created by JianZhang on 2017/3/21.
//  Copyright © 2017年 NUT. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

typedef int ElementType;
struct Node;

typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

struct Node {
    ElementType Element;
    PtrToNode Next;
};

Stack StackCreate(void);
int StackIsEmpty(Stack S);
void StackMakeEmpty(Stack S);
void StackDispose(Stack S);
void StackPush(Stack S, ElementType E);
ElementType StackPop(Stack S);
void StackPrint(Stack S);

#endif /* Stack_h */
