//
//  main.m
//  03-算法分析最大公因数
//
//  Created by 得威 on 2017/3/3.
//  Copyright © 2017年 LCF. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 计算最大公因数
unsigned int GCD(unsigned int M, unsigned int N);

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}

/// 计算最大公因数
unsigned int GCD(unsigned int M, unsigned int N){
    
    unsigned int Rem;
    while (N > 0) {
        Rem = M % N;
        M = N;
        N = Rem;
    }
    return M;
}
