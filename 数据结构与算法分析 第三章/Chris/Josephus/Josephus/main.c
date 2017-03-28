//
//  main.c
//  Josephus
//
//  Created by JianZhang on 2017/3/27.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <assert.h>
#include "CircularLinkedList.h"


void JosephusCallBack(unsigned int index);

int main(int argc, const char * argv[])
{
    Josephus(5, 1, 1, JosephusCallBack);
    
    putchar('\n');
    return 0;
}

void JosephusCallBack(unsigned int index)
{
    printf("%d, \n", index);
}
