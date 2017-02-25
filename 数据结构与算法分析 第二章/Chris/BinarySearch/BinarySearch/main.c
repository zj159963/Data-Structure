//
//  main.c
//  BinarySearch
//
//  Created by JianZhang on 2017/2/20.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef ARRAY_COUNT
#define ARRAY_COUNT 10
#endif

#ifndef NOT_FOUND
#define NOT_FOUND -1
#endif

int binarySearch_recursion(int value, int *array, int left, int right);
int binarySearch_loop(int value, int *array, int left, int right);

int main(int argc, const char * argv[])
{
    int array[] = {0, 3, 7, 12, 13, 27, 31, 50, 67, 69};
    int value, location = 0;
    clock_t start, end;
    
    for (;;) {
        printf("Input number:");
        scanf("%d", &value);
        
        if (value == EOF)
            break;
        
        start = clock();
//        location = binarySearch_recursion(value, array, 0, ARRAY_COUNT - 1);
        location = binarySearch_loop(value, array, 0, ARRAY_COUNT - 1);
        
        end = clock();
        printf("Index: %d\nDuration: %lu\n", location, end - start);
    }
    return 0;
}

int binarySearch_recursion(int value, int *array, int left, int right)
{
    if (left > right)
        return NOT_FOUND;
    
    int mid = (left + right) / 2;
    int midValue = array[mid];
    
    if (midValue > value)
        return binarySearch_recursion(value, array, left, mid - 1);
    else if (midValue < value)
        return binarySearch_recursion(value, array, mid + 1, right);
    else
        return mid;
}

int binarySearch_loop(int value, int *array, int left, int right)
{
    int mid, midValue;
    
    while (left <= right) {
        mid = (left + right) / 2;
        midValue = array[mid];
        
        if (midValue > value)
            right = mid - 1;
        else if (midValue < value)
            left = mid + 1;
        else
            return mid;
    }
    return NOT_FOUND;
}
