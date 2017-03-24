//
//  main.c
//  Queue_Array
//
//  Created by JianZhang on 2017/3/24.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include "Queue.h"

int main(int argc, const char * argv[])
{
    Queue Q;
    int index;
    
    Q = QueueCreate(10);
    
    for (index = 0; index < 10; index++)
        QueueEnqueue(Q, index);
    
    QueuePrint(Q);
//    QueueEmpty(Q);
    printf("%d\n", QueueLength(Q));
    printf("%d\n", QueueIsEmpty(Q));
    
    for (index = 0; index < 10; index++) {
        printf("%d, ", QueueDequeue(Q));
    }
    putchar('\n');
    
    printf("%d\n", QueueLength(Q));
    printf("%d\n", QueueIsEmpty(Q));
    
    QueueEnqueue(Q, 0);
    printf("%d\n", QueueLength(Q));
    
    printf("%d\n", QueueIsEmpty(Q));
    
    printf("%d\n", QueueLength(Q));
    printf("%d\n", QueueDequeue(Q));
    return 0;
}
