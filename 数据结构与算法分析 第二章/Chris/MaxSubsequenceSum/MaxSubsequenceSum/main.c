//
//  main.c
//  MaxSubsequenceSum
//
//  Created by JianZhang on 2017/2/20.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef SUM_MIN
#endif

int *createRandomArray(unsigned int count);
void printArray(int *array, unsigned int count);

int maxSubsequenceSum_version_ON3(int *array, unsigned int count); /// 傻瓜版本
int maxSubsequenceSum_version_ON2(int *array, unsigned int count); /// 正常版本
int maxValueOf(int v0, int v1, int v2);
int maxSubsequenceSum_version_N_O_Log_N(int *array, int left, int right); /// 费事的分治法版本
int maxSubsequenceSum_version_ON(int *array, unsigned int count); /// 聪明版本

int main(int argc, const char * argv[])
{
    int *array, sum;
    unsigned count;
    clock_t start, end;
    
    count = 5;
    array = createRandomArray(count);
    
    printArray(array, count);
    
    start = clock();
    sum = maxSubsequenceSum_version_ON3(array, count);
    end = clock();
    printf("Sum (O(n^3)): %d. Duration: %lu.\n", sum, end - start);
    
    start = clock();
    sum = maxSubsequenceSum_version_ON2(array, count);
    end = clock();
    printf("Sum (O(n^2)): %d. Duration: %lu.\n", sum, end - start);
    
    start = clock();
    sum = maxSubsequenceSum_version_N_O_Log_N(array, 0, count - 1);
    end = clock();
    printf("Sum (O(n * Log(N))): %d. Duration: %lu.\n", sum, end - start);

    
    start = clock();
    sum = maxSubsequenceSum_version_ON(array, count);
    end = clock();
    printf("Sum (O(n)): %d. Duration: %lu.\n", sum, end - start);
    
    return 0;
}

int *createRandomArray(unsigned int count)
{
    int *array, *p;
    
    array = malloc(sizeof(int) * count);
    
    for (p = array; p < array + count; p++)
        *p = arc4random() % 21 - 10;
    
    return array;
}

void printArray(int *array, unsigned int count)
{
    int index;
    
    for (index = 0; index < count; index++) {
        printf("%d", *(array + index));
        
        if (index != count - 1)
            printf(", ");
        else
            printf(".\n");
    }
}

int maxSubsequenceSum_version_ON3(int *array, unsigned int count)
{
    int i, j, k, sum, maxSum;
    
    maxSum = 0;
    for (i = 0; i < count; i++) {
        for (j = i; j < count; j++) {
            sum = 0;
            
            for (k = j; k < count; k++) {
                sum += array[k];
                
                if (sum > maxSum)
                    maxSum = sum;
            }
        }
    }
    return maxSum;
}

int maxSubsequenceSum_version_ON2(int *array, unsigned int count)
{
    int i, j, sum, maxSum;
    
    maxSum = 0;
    for (i = 0; i < count; i++) {
        sum = 0;
        for (j = i; j < count; j++) {
            sum += array[j];
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    return maxSum;
}

int maxValueOf(int v0, int v1, int v2)
{
    int max = v0 > v1 ? v0 : v1;
    return max > v2 ? max : v2;
}

int maxSubsequenceSum_version_N_O_Log_N(int *array, int left, int right)
{
    int maxLeftSum, maxRightSum;
    int leftBorderSum, rightBorderSum;
    int maxLeftBorderSum, maxRightBorderSum;
    int center, index;
    
    if (left == right) {
        int value = *(array + left);
        return value > 0 ? value : 0;
    }
    
    center = (left + right) / 2;
    
    maxLeftSum = maxSubsequenceSum_version_N_O_Log_N(array, left, center);
    maxRightSum = maxSubsequenceSum_version_N_O_Log_N(array, center + 1, right);

    leftBorderSum = 0;
    maxLeftBorderSum = 0;
    
    for (index = center; index >= left; index--) {
        leftBorderSum += array[index];
        
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }
    
    rightBorderSum = 0;
    maxRightBorderSum = 0;
    
    for (index = center + 1; index <= right; index++) {
        rightBorderSum += array[index];
        
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }
    
    return maxValueOf(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

int maxSubsequenceSum_version_ON(int *array, unsigned int count)
{
    int index, sum, maxSum;
    
    maxSum = 0;
    sum = 0;
    
    for (index = 0; index < count; index++) {
        sum += array[index];
        
        if (sum < 0)
            sum = 0;
        else if (sum > maxSum)
            maxSum = sum;
    }
    return maxSum;
}
