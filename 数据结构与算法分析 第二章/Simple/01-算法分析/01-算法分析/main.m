//
//  main.m
//  01-算法分析
//
//  Created by 得威 on 2017/2/28.
//  Copyright © 2017年 LCF. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 算法1
int MaxSubsequenceSum(const  int A[],int N);

///  算法2
int MaxSubsequenceSumSecond( const  int A[],int N);

/// 算法3
int MaxSubsequenceSumThree(const int A[], int N);

/// 算法4
int MaxSubsequenceSumFour(const int A[], int N);

/// 3个数的最大数
int MaxSumT(int A,int B, int C);

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        int array[8] = {4,-3,5,-2,-1,2,6,-2};
        /// 算法1
        int maxSum =  MaxSubsequenceSum(array, 8);
        ///  算法2
        int maxSumS =  MaxSubsequenceSumSecond(array, 8);
        /// 算法4
        int maxSumF = MaxSubsequenceSumFour(array, 8);
        
        printf("\n1-------%d\n\n",maxSum);
        
        printf("\n2-------%d\n\n",maxSumS);
        
        printf("\n3-------%d\n\n",maxSumF);
        
        NSLog(@"Hello, World!");
        
    }
    return 0;
}


int MaxSubsequenceSumFour(const int A[], int N){
    
    int ThisSum, MaxSum, j;
    
    ThisSum = MaxSum = 0;
    for (j = 0 ; j < N; j++) {
        ThisSum += A[j];
        if (ThisSum > MaxSum) {
            MaxSum = ThisSum;
        }else if (ThisSum < 0){
            ThisSum = 0;
        }
/*
 j  0 1 2 3 4 5 6  7
 t  4 1 6 4 3 5 11 9
 s  4 4 6 6 6 6 11 11
 */
    }
    return MaxSum;
}




static int MaxSubSum(const int A[],int Left, int Right){
    int MaxLeftSum,MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int Center, i;
    
    if (Left == Right) {
        if (A[Left] >0) {
            return A[Left];
        }else{
            return 0;
        }
    }
    
    Center = (Left + Right) / 2;
    MaxLeftSum = MaxSubSum(A,Left,Center);
    MaxRightSum = MaxSubSum(A, Center + 1, Right);
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for (i = Center; i>= Left; i--) {
        LeftBorderSum += A[i];
        if (LeftBorderSum > MaxLeftBorderSum) {
            MaxLeftBorderSum = LeftBorderSum;
        }
    }
    
    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for (i = Center + 1; i <= Right; i++) {
        RightBorderSum = A[i];
        if (RightBorderSum > MaxRightBorderSum) {
            MaxRightBorderSum = RightBorderSum;
        }
    }
    return MaxSumT( MaxLeftSum, MaxRightSum,MaxRightBorderSum + MaxLeftBorderSum);
    
}
int MaxSumT(int A,int B, int C){
    int max;
    if (A > B) {
        max = A;
    }else if (B > C){
        max = B;
    }else{
        max = C;
    }
    return max;
}
int MaxSubsequenceSumThree(const int A[], int N){
    return MaxSubSum(A, 0, N - 1);
}

int MaxSubsequenceSumSecond( const  int A[],int N){
    int ThisSum, MaxSum, i, j;
    
    MaxSum = 0;
    
    for (i = 0; i < N; i++) {
        
        ThisSum = 0;
        
        for (j = i; j < N; j++) {
            
            ThisSum += A[j];
/*
 
 i  0                       1                       .......6
 j  0
 t  [0] [0-1][0-2]...[0-7]  [1] [1-2][1-3]...[1-7]        [7]
 m
 */
            if (ThisSum > MaxSum) {
                
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}
/// 算法-1
int MaxSubsequenceSum( const  int A[],int N){
    int ThisSum, MaxSum,i,j,k;
    MaxSum = 0;
    // 0  1  2  3  4  5  6  7  8  9
    for (i = 0; i < N; i++) {   //N
        for (j = i; j < N; j++) {   // 0    1
            ThisSum = 0;
            for (k = i; k <= j; k++) {//0  0 1
                ThisSum += A[k];      // 1  1 -2
                
/*
 i  0
 j  0 1     2
 k  0 0 1   0 1 2
sum 1 1+-2  1-2+3
    1  1    2
 */
                if (ThisSum > MaxSum) {
                    MaxSum = ThisSum;
                }
            }
//            if (ThisSum > MaxSum) {
//                MaxSum = ThisSum;
//            }
        }
    }

    return MaxSum;
}
