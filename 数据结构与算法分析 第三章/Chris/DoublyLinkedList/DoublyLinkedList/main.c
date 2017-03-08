//
//  main.c
//  DoublyLinkedList
//
//  Created by JianZhang on 2017/3/7.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include "DoublyLinkedList.h"

static int const Count = 10;

int main(int argc, const char * argv[])
{
    int Source[Count] = {0};
    DoublyLinkedList List, A;
    unsigned int index;
    
    for (index = 0; index < Count; index++)
        Source[index] = index;
    
    List = DoublyLinkedListCreate(Source, Count);
    
    printf("Created list is: ");
    DoublyLinkedListPrint(List);
    putchar('\n');
    
    printf("The List is %sempty.\n", DoublyLinkedListIsEmpty(List) ? "" : "not ");
    printf("The node is %sthe first node of list.\n", DoublyLinkedListIsFirstNode(List, List->Next) ? "" : "not ");
    printf("The node is %sthe last node of list.\n", DoublyLinkedListIsLastNode(List, List->Next) ? "" : "not ");
    printf("The length of list is %d.\n", DoublyLinkedListLength(List));
    
    /*
    int loopKind, loopLength, *loopFlag;
    List->Next->Next->Next->Next->Prior = List->Next->Next->Next->Next->Next;
    loopKind = DoublyLinkedListIsBadLoop(List);
    if (loopKind != 0) {
        printf("The list has a bad loop with %s branch.\n", loopKind > 0 ? "next" : "prior");
        loopLength = DoublyLinkedListBadLoopLength(List, loopFlag);
        printf("The length of the bad loop is %d.\n", loopLength);
        printf("The element of the bad loop entrance is %d.\n", DoublyLinkedListFindBadLoopEntrance(List, loopFlag)->Element);
    } else
        printf("The list does not has a bad loop.\n");
    */
    
    printf("The element of the first node in the list is %d.\n", DoublyLinkedListFirstNode(List)->Element);
    printf("The element of the last node in the list is %d.\n", DoublyLinkedListLastNode(List)->Element);
    printf("The element of the middle node in the list is %d.\n", DoublyLinkedListMiddleNode(List)->Element);
    printf("The node which element is %d is %p.\n", 3, DoublyLinkedListFindNode(List, 3));
    printf("The node which next node's element is %d is %d.\n", 3, DoublyLinkedListFindPreviousNode(List, 3)->Element);
    printf("The node at the proir of %d is %d.\n", 2, DoublyLinkedListFindPriorNode(List, DoublyLinkedListFindNode(List, 2))->Element);
    printf("The elment of %d distance from the tail of the list is %d.\n", 0, DoublyLinkedListFindNodeFromTail(List, 0)->Element);
    
    printf("The list after insert element %d after %d is : ", 10, 9);
    DoublyLinkedListInsertElement(List, DoublyLinkedListFindNode(List, 9), 10);
    DoublyLinkedListPrint(List);
    putchar('\n');
    
    for (index = 0; index < Count; index++)
        Source[index] = index + 11;
    
    A = DoublyLinkedListCreate(Source, Count);
    DoublyLinkedListAppendList(List, A);
    printf("The list after appending list A is : ");
    DoublyLinkedListPrint(List);
    putchar('\n');
    
    DoublyLinkedListDeleteElement(List, 20);
    printf("The list after deleting element %d is : ", 20);
    DoublyLinkedListPrint(List);
    putchar('\n');
    
    printf("The list after delete node %p is : ", DoublyLinkedListMiddleNode(List));
    DoublyLinkedListDeleteNode(List, DoublyLinkedListMiddleNode(List));
    DoublyLinkedListPrint(List);
    putchar('\n');
    
    DoublyLinkedListReverse(List);
    printf("The list after reversing is : ");
    DoublyLinkedListPrint(List);
    putchar('\n');
    
    printf("The list is %slegal doubly linked list.\n", DoublyLinkedListIsLegal(List) ? "" : "not ");

    DoublyLinkedListDeleteList(List);
    printf("The list after deleting is : \n");
    DoublyLinkedListPrint(List);
    putchar('\n');
    
    return 0;
}
