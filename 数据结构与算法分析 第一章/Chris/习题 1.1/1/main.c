//
//  main.c
//  1
//
//  Created by JianZhang on 2017/2/7.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <time.h>

int main(int argc, const char * argv[])
{
    
    clock_t begin, end;
    
    begin = clock();
    
    __unused long double value = 1000000000000000000.0 / 2.0;
    // __unused long double value = 0.0 / 2.0;
    
    end = clock();
    
    clock_t duration = end - begin;
    
    printf("%lu\n", duration);
    
    return 0;
}
