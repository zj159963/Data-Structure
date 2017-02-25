//
//  main.c
//  习题 2.13
//
//  Created by JianZhang on 2017/2/24.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrimeNumber(unsigned int n);

int main(int argc, const char * argv[])
{
    printf("%s\n", isPrimeNumber(37) ? "YES" : "NO");
    return 0;
}

int isPrimeNumber(unsigned int n)
{
    if (n <= 3)
        return n > 1;
    
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    
    unsigned int index;
    
    for (index = 5; index * index < n; index += 6)
        if (n % index == 0 || n % (index + 2) == 0)
            return 0;
    
    return 1;
}
