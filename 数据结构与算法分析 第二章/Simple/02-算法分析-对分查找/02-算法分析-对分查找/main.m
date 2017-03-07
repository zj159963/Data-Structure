//
//  main.m
//  02-算法分析-对分查找
//
//  Created by 得威 on 2017/3/3.
//  Copyright © 2017年 LCF. All rights reserved.
//

#import <Foundation/Foundation.h>



/// 求数X 是不是属于A[]
int BinarySearch(const int A[],int X, int N);

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}

/// 二分查找
int BinarySearch(const int A[],int X, int N){
    
    int Low, Mid, High;
    Low = 0; High = N - 1;
    while (Low <= High) {
        Mid = (Low + High) / 2;
        if (A[Mid] < X) {
            Low = Mid + 1;
        }else if (A[Mid] > X){
            High = Mid - 1;
        }else{
            return Mid;
        }
    }
    return -1;
}
