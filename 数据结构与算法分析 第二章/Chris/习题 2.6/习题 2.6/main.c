//
//  main.c
//  习题 2.6
//
//  Created by JianZhang on 2017/2/22.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <time.h>

void function_1(int n);
void function_2(int n);
void function_3(int n);
void function_4(int n);
void function_5(int n);
void function_6(int n);

clock_t test(void (func)(int), int n);

int main(int argc, const char * argv[])
{
    /// 大 O 表示法结果 1. O(N), 2. O(N^2), 3. O(N^3), 4. O(N^2), 5. O(N^5), 6. O(N^4)
    /// 因为 4 和 2 相比， 4 的内层循环是按照最高来计算的， 所以 4 应该比 2 耗时要低
    /// 根据大 O 表示法推测运行时间由低到高分别为 1, 4, 2, 3, 6, 5.
    
    int n = 100;
    
    printf("Durantion 1: %lu\n", test(function_1, n));
    printf("Durantion 2: %lu\n", test(function_2, n));
    printf("Durantion 3: %lu\n", test(function_3, n));
    printf("Durantion 4: %lu\n", test(function_4, n));
    printf("Durantion 5: %lu\n", test(function_5, n));
    printf("Durantion 6: %lu\n", test(function_6, n));
    
    /*
     Durantion 1: 3
     Durantion 2: 21
     Durantion 3: 2232
     Durantion 4: 22
     Durantion 5: 1687642
     Durantion 6: 25343
     以上是 n = 100 时的一次运行结果， 运行在 MacOS(10.12.3), Xcode(8.2.1) 环境下.
     */
    
    return 0;
}

void function_1(int n)
{
    int sum = 0, i;
    
    for (i = 0; i < n; i++)
        sum++;
}

void function_2(int n)
{
    int sum = 0, i, j;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            sum++;
}

void function_3(int n)
{
    int sum = 0, i, j;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < n * n; j++)
            sum++;
}

void function_4(int n)
{
    int sum = 0, i, j;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < i; j++)
            sum++;
}

void function_5(int n)
{
    int sum = 0, i, j, k;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < i * i; j++)
            for (k = 0; k < j; k++)
                sum++;
}

void function_6(int n)
{
    int sum = 0, i, j, k;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < i * i; j++)
            if (j % i == 0)
                for (k = 0; k < j; k++)
                    sum++;
}

clock_t test(void (func)(int), int n)
{
    clock_t start, end;
    
    start = clock();
    func(n);
    end = clock();
    return end - start;
}
