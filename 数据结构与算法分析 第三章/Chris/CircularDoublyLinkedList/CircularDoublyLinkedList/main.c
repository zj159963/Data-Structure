//
//  main.c
//  CircularDoublyLinkedList
//
//  Created by JianZhang on 2017/3/8.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "CircularDoublyLinkedList.h"

static int const Count = 10;

int main(int argc, const char * argv[])
{
    int Source[Count] = {0};
    CircularDoublyLinkedList List, A;
    int index;
    
    for (index = 0; index < Count; index++)
        Source[index] = index;
    
    List = CircularDoublyLinkedListCreate(Source, Count);
    printf("The created list is : ");
    CircularDoublyLinkedListPrint(List);
    
    printf("The reversing list is : ");
    CircularDoublyLinkedListPrintReversing(List);
    
    printf("The list is %sempty.\n", CircularDoublyLinkedListIsEmpty(List) ? "" : "not ");
    printf("The length of the list is %d.\n", CircularDoublyLinkedListLength(List));
    
    printf("The node which element is %d is%s the first node of the list.\n", CircularDoublyLinkedListRetrieve(CircularDoublyLinkedListFirstNode(List)), CircularDoublyLinkedListIsFirstNode(List, CircularDoublyLinkedListFirstNode(List)) ? "" : " not");
    
    printf("The node whitch element is %d is%s the last node of the list.\n", CircularDoublyLinkedListRetrieve(CircularDoublyLinkedListFirstNode(List)), CircularDoublyLinkedListIsLastNode(List, CircularDoublyLinkedListAdvance(List)) ? "" : " not");
    
    /*
    int bad, *flag = calloc(1, sizeof(int));
    
    List->Next->Next->Next = List->Next->Next;
    bad = CircularDoublyLinkedListIsBadLoop(List);
    
    if (bad != 0) {
        printf("There is a bad loop in the %s branch.\n", bad > 0 ? "next" : "prior");
        printf("The length of the bad loop is %d.\n", CircularDoublyLinkedListBadLoopLength(List, flag));
        printf("The element of the bad loop entrance is %d.\n", CircularDoublyLinkedListFindBadLoopEntrance(List, flag)->Element);
        free(flag);
    } else
        printf("There is none bad loop in the list.\n");
     */
    
    printf("The list after insert element %d is : ", 10);
    CircularDoublyLinkedListInsertElement(List, CircularDoublyLinkedListFirstNode(List), 10);
    CircularDoublyLinkedListPrint(List);
    
    for (index = 0; index < Count; index++)
        Source[index] = index + 11;
    
    A = CircularDoublyLinkedListCreate(Source, Count);
    printf("The list A created is : .\n");
    CircularDoublyLinkedListPrint(A);
    
    CircularDoublyLinkedListAppendList(List, A);
    printf("The list after appending list A is : ");
    CircularDoublyLinkedListPrint(List);
    
    CircularDoublyLinkedListDeleteElement(List, 10);
    printf("The list after deleting element %d is : ", 10);
    CircularDoublyLinkedListPrint(List);
    
    CircularDoublyLinkedListDeleteNode(List, CircularDoublyLinkedListFindPrior(List, List));
    printf("The list after deleting the node is : ");
    CircularDoublyLinkedListPrint(List);
    
    CircularDoublyLinkedListRevere(List);
    printf("The list after reversing is : ");
    CircularDoublyLinkedListPrint(List);
    CircularDoublyLinkedListPrintReversing(List);
    
    CircularDoublyLinkedListDeleteList(List);
    printf("The list after deleting list is : ");
    CircularDoublyLinkedListPrint(List);
    CircularDoublyLinkedListPrintReversing(List);
    
    return 0;
}
