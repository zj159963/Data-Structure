//
//  main.c
//  习题 2.9, 2.10
//
//  Created by JianZhang on 2017/2/23.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <math.h>

long normalSum(int *array, int count, int x);
long hornerSum(int *array, int count, int x);

long pow_loop(int x, int n);
long pow_square(int x, int n);

int main(int argc, const char * argv[])
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%ld\n", normalSum(array, 9, 10));
    printf("%ld\n", hornerSum(array, 9, 10));
    return 0;
}

long pow_loop(int x, int n)
{
    if (n == 0)
        return 1;
    
    if (n == 1)
        return x;
    
    int result;
    
    result = x;
    while (n > 1) {
        result *= x;
        n--;
    }
    return result;
}

long pow_square(int x, int n)
{
    if (n == 0)
        return 1;
    
    if (n == 1)
        return x;
    
    if (n % 2 == 0)
        return pow_square(x * x, n / 2);
    
    return pow_square(x * x, n / 2) * x;
}

long normalSum(int *array, int count, int x)
{
    long sum, index;
    
    sum = 0;
    for (index = 0; index < count; index++)
        sum += array[index] * pow(x, index);
    
    return sum;
}

long hornerSum(int *array, int count, int x)
{
    long poly = 0, index;
    
    for (index = count - 1; index >= 0; index--)
        poly = poly * x + array[index];
    return poly;
}
