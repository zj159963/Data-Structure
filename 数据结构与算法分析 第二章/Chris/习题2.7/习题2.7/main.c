//
//  main.c
//  习题2.7
//
//  Created by JianZhang on 2017/2/22.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

static int const COUNT = 250;

int randInt(void);

void function_1(int *array);
void function_2(int *array);
void function_3(int *array);

void printArray(int *array, unsigned int count);
clock_t test(void (func)(int *array), int *array);

int main(int argc, const char * argv[])
{
    int array[COUNT] = {-1}, i;
    clock_t sum = 0;
    
    for (i = 0; i < 10; i++) {
        sum += test(function_1, array);
    }
    
    printf("%lu\n", sum);
    
//    int array1[COUNT] = {-1};
//    int array2[COUNT] = {-1};
//    int array3[COUNT] = {-1};
    
//    clock_t d1, d2, d3;
    
//    d1 = test(function_1, array1);
//    d2 = test(function_2, array2);
//    d3 = test(function_3, array3);
    
//    printf("Function1\n\tDuration: %lu\n\tArray1:\n\t\t", d1);
//    printArray(array1, COUNT);
//    
//    printf("Function2\n\tDuration: %lu\n\tArray2:\n\t\t", d2);
//    printArray(array2, COUNT);
//
//    printf("Function3\n\tDuration: %lu\n\tArray3:\n\t\t", d3);
//    printArray(array3, COUNT);
    return 0;
}

int randInt(void)
{
    return arc4random() % COUNT;
}

void function_1(int *array)
{
    int i, j, randomNumber;
    
    i = 0;
    while (i < COUNT) {
        randomNumber = randInt();
        for (j = 0; j < i; j++)
            if (array[j] == randomNumber)
                break;
        
        if (j == i) {
            array[i] = randomNumber;
            i++;
        }
    }
}

void function_2(int *array)
{
    int i, randomNumber;
    int used[COUNT] = {0};
    
    i = 0;
    while (i < COUNT) {
        randomNumber = randInt();
        if (used[randomNumber] == 0) {
            used[randomNumber] = 1;
            array[i] = randomNumber;
            i++;
        }
    }
}

void function_3(int *array)
{
    int i, temp;
    
    for (i = 0; i < COUNT; i++)
        array[i] = i;
    
    for (i = 0; i < COUNT; i++) {
        int randomLocation = randInt();
        
        temp = array[i];
        array[i] = array[randomLocation];
        array[randomLocation] = temp;
    }
}

void printArray(int *array, unsigned int count)
{
    int index;
    
    for (index = 0; index < count; index++) {
        printf("%d", array[index]);
        
        if (index != count - 1)
            printf(", ");
        else
            printf(".\n");
    }
}

clock_t test(void (func)(int *array), int *array)
{
    clock_t start, end;
    
    start = clock();
    func(array);
    end = clock();
    return end - start;
}
