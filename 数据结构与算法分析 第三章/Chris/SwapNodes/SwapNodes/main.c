//
//  main.c
//  SwapNodes
//
//  Created by JianZhang on 2017/3/27.
//  Copyright © 2017年 NUT. All rights reserved.
//

#define TARGET_LINKED_LIST 0

#include <stdio.h>

#if TARGET_LINKED_LIST
#include "LinkedList.h"
#else
#include "DoublyLinkedList.h"
#endif

int main(int argc, const char * argv[])
{
    int Sources[5] = {0, 1, 2, 3, 4};
    
#if TARGET_LINKED_LIST
    LinkedList L;
    
    L = CreateList(Sources, 5);
    PrintList(L);
    Swap(L, FindFromTail(2, L));
    PrintList(L);
#else
    DoublyLinkedList L;
    
    L = DoublyLinkedListCreate(Sources, 5);
    DoublyLinkedListPrint(L);
    DoublyLinkedListSwap(L, DoublyLinkedListFindNodeFromTail(L, 4));
    DoublyLinkedListPrint(L);
#endif
    return 0;
}
