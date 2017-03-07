//
//  main.c
//  CircularLinkedList
//
//  Created by JianZhang on 2017/3/7.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "CircularLinkedList.h"

int const Count = 10;

void LogElement(void *Element);

int main(int argc, const char * argv[])
{
    int *Src[Count], *Arc[Count], index;
    int *ElementTempCell;
    CircularLinkedList List, A;
    
    for (index = 0; index < Count; index++) {
        ElementTempCell = calloc(1, sizeof(int));
        *ElementTempCell = index;
        Src[index] = ElementTempCell;
    }
    
    printf("Source : ");
    for (index = 0; index < Count; index++) {
        LogElement(Src[index]);
        printf(", ");
    }
    putchar('\n');
    
    List = CircularLinkedListCreate((void**)Src, 10);
    
    for (index = 0; index < Count; index++) {
        ElementTempCell = calloc(1, sizeof(int));
        *ElementTempCell = index;
        Arc[index] = ElementTempCell;
    }
    A = CircularLinkedListCreate((void*)Arc, 10);

    printf("Circular Linked List : ");
    CircularLinkedListPrint(List, LogElement);
    putchar('\n');
    
    printf("Length of Circular Linked List : ");
    printf("%d\n", CircularLinkedListLength(List));
    
    printf("Circular Linked List is %sempty.\n", CircularLinkedListIsEmpty(List) ? "" : "not ");
    printf("Circular Linked List is%s first node.\n", CircularLinkedListIsFirstNode(List, List->Next) ? "" : " not");
    printf("Circular Linked List is%s last node.\n", CircularLinkedListIsLastNode(List, CircularLinkedListLastNode(List)) ? "" : " not");
    
    /*
    CircularLinkedListLastNode(List)->Next = List->Next->Next;
    
    printf("Circular Linked List %shas bad loop.\n", CircularLinkedListIsBadLoop(List) ? "" : "doesn't ");
    printf("Circular Linked List bad loop length is %d.\n", CircularLinkedListBadLoopLength(List));
    printf("Circular Linked List bad loop entrance elemnt is ");
    LogElement(CircularLinkedListBadLoopEntrance(List)->Element);
    printf(".\n");
     */
    
    printf("Circular Linked List first element is : ");
    LogElement(CircularLinkedListFirstNode(List)->Element);
    putchar('\n');
    
    printf("Circular Linked List last element is : ");
    LogElement(CircularLinkedListLastNode(List)->Element);
    putchar('\n');
    
    printf("Circular Linked List node which element is 5 : ");
    LogElement(CircularLinkedListFind(List, Src[5])->Element);
    putchar('\n');
    
    printf("Circular Linked List node which next node's element is 5 : ");
    LogElement(CircularLinkedListFindPrevious(List, Src[5])->Element);
    putchar('\n');
    
    printf("Circular Linked List mid node's element is ");
    LogElement(CircularLinkedListFindMid(List)->Element);
    putchar('\n');
    
    printf("Circular Linked List find 3 from tail element is ");
    LogElement(CircularLinkedListFindFromTail(List, 3)->Element);
    putchar('\n');

    CircularLinkedListAppend(List, A);
    printf("Circular Linked List after appending A is: ");
    CircularLinkedListPrint(List, LogElement);
    putchar('\n');

    ElementTempCell = calloc(1, sizeof(int));
    *ElementTempCell = 111;
    CircularLinkedListInsert(List, ElementTempCell, List->Next->Next);
    printf("Circular Linked List after inserting 111 is: ");
    CircularLinkedListPrint(List, LogElement);
    putchar('\n');

    CircularLinkedListDeleteNode(List, CircularLinkedListLastNode(List));
    printf("Circular Linked List after delete node is: ");
    CircularLinkedListPrint(List, LogElement);
    putchar('\n');
    
    CircularLinkedListDeleteElement(List, Src[3]);
    printf("Circular Linked List after delete element is: ");
    CircularLinkedListPrint(List, LogElement);
    putchar('\n');
    
    CircularLinkedListReverse(List);
    printf("Circular Linked List after reversing is: ");
    CircularLinkedListPrint(List, LogElement);
    putchar('\n');
    
    CircularLinkedListDeleteList(List);
    printf("Circular Linked List after delete is: ");
    CircularLinkedListPrint(List, LogElement);
    putchar('\n');
    
    return 0;
}

void LogElement(void *Element)
{
    if (Element == NULL) {
        printf("NULL");
        return;
    }
    
    printf("%d", *(int*)Element);
}
