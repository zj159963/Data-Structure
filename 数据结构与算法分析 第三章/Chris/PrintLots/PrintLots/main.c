//
//  main.c
//  PrintLots
//
//  Created by JianZhang on 2017/3/27.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"

int main(int argc, const char * argv[])
{
    int Sources[10] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    int Indices[4] = {1, 3, 4, 6};
    
    LinkedList SourceList, IndexList;
    
    SourceList = CreateList(Sources, 10);
    IndexList = CreateList(Indices, 4);
    
    PrintLots(SourceList, IndexList);
    return 0;
}
