//
//  main.c
//  Polynomial
//
//  Created by JianZhang on 2017/3/10.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include "Polynomial.h"

int main(int argc, const char * argv[])
{
    const int Exponents1[] = {5, 4, 3, 2};
    const int Coefficients1[] = {2, 3, 3, 4};
    const unsigned int Count1 = 4;
    
    const int Exponents2[] = {7, 5, 4, 2};
    const int Coefficients2[] = {2, 3, 5, 7};
    const unsigned int Count2 = 4;
    
    Polynomial Poly1, Poly2, PolySum, PolyProduct;
    
    Poly1 = PolynomialCreateWithExponents(Exponents1, Coefficients1, Count1);
    PolynomialPrint(Poly1);
    
    Poly2 = PolynomialCreateWithExponents(Exponents2, Coefficients2, Count2);
    PolynomialPrint(Poly2);
    
    PolySum = PolynomialPlus(Poly1, Poly2);
    PolynomialPrint(PolySum);
    
    PolyProduct = PolynomialMultiply(Poly1, Poly2);
    PolynomialPrint(PolyProduct);
    
    return 0;
}
