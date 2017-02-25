//
//  main.c
//  Fibonacci
//
//  Created by JianZhang on 2017/2/20.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fibonacci(unsigned long *array, unsigned int count);
unsigned long *createArray(size_t size, unsigned int count);
void destroyArray(unsigned long **array, unsigned int count);
void printArray(unsigned long *array, unsigned int count);

int main(int argc, const char * argv[])
{
    unsigned long *array;
    unsigned int count;
    clock_t start, end, duration;
    
    count = 5000;
    array = createArray(sizeof(int), count);
    
    start = clock();
    fibonacci(array, count);
    end = clock();
    
    duration = end - start;
    printf("Duration: %lu\n", duration);
    
    printArray(array, count);
    destroyArray(&array, count);
    return 0;
}

void fibonacci(unsigned long *array, unsigned int count)
{
    if (count == 0)
        return;
    
    if (count >= 1)
        *array = 1;
    
    if (count >= 2)
        *(array + 1) = 1;
    
    if (count <= 2)
        return;
    
    unsigned long *p;
    
    for (p = (array + 2); p < array + count; p++)
        *p = *(p - 1) + *(p - 2);
}

unsigned long *createArray(size_t size, unsigned int count)
{
    unsigned long *array, index;
    
    array = malloc(size * count);
    for (index = 0; index < count; index++)
        *(array + index) = 0;
    
    return array;
}

void destroyArray(unsigned long **array, unsigned int count)
{
    unsigned long *p;
    srand((unsigned int)time(NULL));
    for (p = *array; p < *array + count; p++)
        *p = rand();
    
    free(*array);
    *array = NULL;
}

void printArray(unsigned long *array, unsigned int count)
{
    int index;
    
    for (index = 0; index < count; index++) {
        printf("%lu", *(array + index));
        
        if (index != count - 1)
            printf(", ");
        else
            printf(".\n");
    }
}
