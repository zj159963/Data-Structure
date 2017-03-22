//
//  main.c
//  LinkedList_Cursor
//
//  Created by JianZhang on 2017/3/21.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"

int main(int argc, const char * argv[])
{
    ElementType Sources[10];
    List L, M;
    int index;
    
    LinkedListInitializeCursorSpace();
    
    for (index = 0; index < 10; index++)
        Sources[index] = index;
    
    L = LinkedListCreate(Sources, 10);
    M = LinkedListCreate(Sources, 5);
    
    LinkedListPrint(L);
    LinkedListPrint(M);
    
    LinkedListDeleteElement(L, 3);
    LinkedListDeleteElement(M, 0);
    
    LinkedListPrint(L);
    LinkedListPrint(M);
    
    LinkedListInsertElement(L, 3, L);
    LinkedListInsertElement(M, 3, 0);
    
    LinkedListPrint(L);
    LinkedListPrint(M);
    return 0;
}
