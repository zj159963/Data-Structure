//
//  main.c
//  LinkedList
//
//  Created by JianZhang on 2017/2/27.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(int argc, const char *argv[])
{
    LinkedList L;
    int src[] = {0, 1, 2, 3, 4, 5};
    
    L = CreateList(src, 6);
    
    printf("Length of list is: %d\n", Length(L));
    PrintList(L);
    
    Position SSS = calloc(1, sizeof(struct Node));
    DeleteNode(SSS, L);
    
    PrintList(L);
    
    putchar('\n');
    return 0;
}
