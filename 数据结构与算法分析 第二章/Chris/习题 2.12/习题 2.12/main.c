//
//  main.c
//  习题 2.12
//
//  Created by JianZhang on 2017/2/23.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int value;
    int index;
} Item;

int minSubsequenceSum(const int *array, int count);
int minPositiveSubsequenceSum(const int *array, int count);
int compare(const void *left, const void *right);

int main(int argc, const char * argv[])
{
    int array[8] = {-4, -1, -6, -2, -2, 14, -1, -4};
    printf("%d\n", minSubsequenceSum(array, 8));
    printf("%d\n", minPositiveSubsequenceSum(array, 8));
    return 0;
}

int minSubsequenceSum(const int *array, int count)
{
    int sum, minSum, index;
    
    sum = 0;
    minSum = 0;
    for (index = 0; index < count; index++) {
        sum += array[index];
        if (sum > 0)
            sum = 0;
        else if (minSum > sum)
            minSum = sum;
    }
    return minSum;
}

int compare(const void *left, const void *right)
{
    return ((Item *)left)->value - ((Item *)right)->value;
}

int minPositiveSubsequenceSum(const int *array, int count)
{
    Item *items;
    int index, itemIndex, minPositiveSum, currentPositiveSum;
    
    items = malloc(sizeof(Item) * (count + 1));
    items[0].value = 0;
    items[0].index = 0;
    itemIndex = 1;
    
    for (index = 0; index < count; index++) {
        items[itemIndex].index = itemIndex;
        items[itemIndex].value = items[index].value + array[index];
        itemIndex++;
    }
    
    qsort((void*)items, count + 1, sizeof(items[0]), compare);
    
    minPositiveSum = INT_MAX;
    
    for (int i = 0; i <= count; i++) {
        printf("Value: %d, Index: %d\n", items[i].value, items[i].index);
    }
    
    for (index = 1; index <= count; index++) {
        int currentValue = items[index].value;
        int currentIndex = items[index].index;
        int previousValue = items[index - 1].value;
        int previousIndex = items[index - 1].index;
        
        currentPositiveSum = currentValue - previousValue;
        
        if (currentIndex > previousIndex &&
            currentPositiveSum > 0 &&
            currentPositiveSum < minPositiveSum)
            minPositiveSum = currentPositiveSum;
    }
    
    free(items);
    return minPositiveSum == INT_MAX ? 0 : minPositiveSum;
}
