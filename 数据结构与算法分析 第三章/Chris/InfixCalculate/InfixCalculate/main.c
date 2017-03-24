//
//  main.c
//  InfixCalculate
//
//  Created by JianZhang on 2017/3/22.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include "Calculate.h"

int main(int argc, const char * argv[])
{
    int PostfixFile[] = {6, 5, 2, -3, '+', 8, '*', '+', 3, '+', '*'};
    int InfixFile[] = {6, '*', '(', 5, '+', '(', 2, '+', -3, ')', '*', 8, '+', 3, ')'};
    
    printf("%d\n", PostfixCalculate(PostfixFile, 11));
    printf("%d\n", InfixCalculate(InfixFile, 15));
    return 0;
}
