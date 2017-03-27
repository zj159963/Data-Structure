//
//  main.c
//  IntersectionAndUnion
//
//  Created by JianZhang on 2017/3/27.
//  Copyright © 2017年 NUT. AILl rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"

int main(int argc, const char * argv[])
{
    int AscendingSource1[5] = {0, 1, 2, 3, 6};
    int AscendingSource2[5] = {0, 2, 3, 6, 10};
    
    int DescendingSource1[5] = {6, 3, 2, 1, 0};
    int DescendingSource2[5] = {9, 5, 3, 2, 0};
    
    LinkedList AIL, AUL, AL1, AL2;
    LinkedList DIL, DUL, DL1, DL2;
    
    AL1 = CreateList(AscendingSource1, 5);
    AL2 = CreateList(AscendingSource2, 5);
    
    DL1 = CreateList(DescendingSource1, 5);
    DL2 = CreateList(DescendingSource2, 5);
    
    AIL = IntersectSortedLists(AL1, AL2, 1);
    PrintList(AIL);
    
    DIL = IntersectSortedLists(DL1, DL2, 0);
    PrintList(DIL);
    
    AUL = UnionSortedLists(AL1, AL2, 1);
    PrintList(AUL);
    DUL = UnionSortedLists(DL1, DL2, 0);
    PrintList(DUL);
    
    return 0;
}
