//
//  main.c
//  RadixSort
//
//  Created by JianZhang on 2017/3/13.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "LinkedList.h"

ElementType *RandomSourceCreate(unsigned int Places, unsigned int Count);

int main(int argc, const char * argv[])
{
    ElementType *Source;
    LinkedList List;
    unsigned int Count, Places;
    
    Count = 2;
    Places = 2;
    Source = RandomSourceCreate(Places, Count);
    List = LinkedListCreate(Source, Count);
    LinkedListPrint(List);
    
    printf("The list after radix sorting is : \n\t");
    LinkedListRadixSort(List, Places);
    LinkedListPrint(List);
    return 0;
}

ElementType *RandomSourceCreate(unsigned int Places, unsigned int Count)
{
    ElementType *Source, *P;
    int Limits;
    
    Source = calloc(Count, sizeof(ElementType));
    assert(Source != NULL);
    Limits = pow(10, Places);
    
    for (P = Source; P < Source + Count; P++)
        *P = arc4random() % Limits + 1;
    
    return Source;
}
