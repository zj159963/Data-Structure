//
//  main.c
//  习题 2.16
//
//  Created by JianZhang on 2017/2/25.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>

int powx(int x, int n);

int main(int argc, const char * argv[])
{
    printf("%d\n", powx(2, 3));
    return 0;
}

int powx(int x, int n)
{
    int result = 1;
    
    while (n > 0) {
        if (n % 2 != 0)
            result *= x;
        x = x * x;
        n /= 2;
    }
    
    return result;
}
