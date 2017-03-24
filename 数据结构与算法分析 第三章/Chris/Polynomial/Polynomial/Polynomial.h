//
//  Polynomial.h
//  Polynomial
//
//  Created by JianZhang on 2017/3/10.
//  Copyright © 2017年 NUT. All rights reserved.
//

#ifndef Polynomial_h
#define Polynomial_h

struct Node;

typedef struct Node* PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode Polynomial;

/*
 *  The params Exponents should be sorted in descending order.
 *  And the Coefficients' count should be equal to Exponents.
 */
Polynomial PolynomialCreateWithExponents(const int Exponents[], const int Coefficients[], unsigned int Count);
Polynomial PolynomialPlus(Polynomial Poly1, Polynomial Poly2);
Polynomial PolynomialMultiply(Polynomial Poly1, Polynomial Poly2);

void PolynomialPrint(Polynomial Poly);

#endif /* Polynomial_h */
