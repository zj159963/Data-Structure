//
//  Polynomial.c
//  Polynomial
//
//  Created by JianZhang on 2017/3/10.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Polynomial.h"

struct Node {
    int Coeff;
    int Exponent;
    Position Next;
};

Polynomial PolynomialCreateWithExponents(const int Exponents[], const int Coefficients[], unsigned int Count)
{
    Polynomial Poly;
    Position P ,TempCell;
    unsigned int index;
    
    Poly = calloc(1, sizeof(struct Node));
    assert(Poly != NULL);
    P = Poly;
    
    for (index = 0; index < Count; index++) {
        TempCell = calloc(1, sizeof(struct Node));
        assert(TempCell != NULL);
        TempCell->Exponent = Exponents[index];
        TempCell->Coeff = Coefficients[index];
        P->Next = TempCell;
        P = TempCell;
    }
    return Poly;
}

Polynomial PolynomialPlus(Polynomial Poly1, Polynomial Poly2)
{
    Polynomial Sum;
    Position P, P1, P2, TempCell;
    
    Sum = calloc(1, sizeof(struct Node));
    assert(Sum != NULL);
    
    P = Sum;
    P1 = Poly1->Next;
    P2 = Poly2->Next;
    
    while (P1 != NULL && P2 != NULL) {
        TempCell = calloc(1, sizeof(struct Node));
        assert(TempCell != NULL);
        
        if (P1->Exponent > P2->Exponent) {
            TempCell->Coeff = P1->Coeff;
            TempCell->Exponent = P1->Exponent;
            P1 = P1->Next;
        } else if (P1->Exponent < P2->Exponent) {
            TempCell->Coeff = P2->Coeff;
            TempCell->Exponent = P2->Exponent;
            P2 = P2->Next;
        } else {
            TempCell->Coeff = P1->Coeff + P2->Coeff;
            TempCell->Exponent = P1->Exponent;
            P1 = P1->Next;
            P2 = P2->Next;
        }
        P->Next = TempCell;
        P = TempCell;
    }
    
    P1 = P1 != NULL ? P1 : P2;
    
    while (P1 != NULL) {
        TempCell = calloc(1, sizeof(struct Node));
        assert(TempCell != NULL);
        TempCell->Coeff = P1->Coeff;
        TempCell->Exponent = P2->Exponent;
        P->Next = TempCell;
        P = TempCell;
        P1 = P1->Next;
    }
    return Sum;
}

Position PolynomialFindExponentPosition(Polynomial Poly, int Exponent)
{
    Position P;
    
    P = Poly;
    
    while (P->Next != NULL && P->Next->Exponent >= Exponent)
        P = P->Next;
    return P;
}

Polynomial PolynomialMultiply(Polynomial Poly1, Polynomial Poly2)
{
    Polynomial Product;
    Position P, P1, P2, TempCell;
    int Coeff, Exponent;
    
    Product = calloc(1, sizeof(struct Node));
    assert(Product != NULL);
    
    P1 = Poly1->Next;
    P2 = Poly2->Next;
    
    while (P1 != NULL) {
        while (P2 != NULL) {
            Exponent = P1->Exponent + P2->Exponent;
            Coeff = P1->Coeff * P2->Coeff;
            
            P = PolynomialFindExponentPosition(Product, Exponent);
            if (P == Product || P->Exponent != Exponent) {
                TempCell = calloc(1, sizeof(struct Node));
                assert(TempCell != NULL);
                
                TempCell->Exponent = Exponent;
                TempCell->Coeff = Coeff;
                TempCell->Next = P->Next;
                P->Next = TempCell;
            } else if (P->Exponent == Exponent)
                P->Coeff += Coeff;
            
            P2 = P2->Next;
        }
        P1 = P1->Next;
        P2 = Poly2->Next;
    }
    
    return Product;
}

void PolynomialPrint(Polynomial Poly)
{
    Position P;
    char *LeftBracketOrNil, *RightBracketOrNil;
    int Coeff;
    
    if (Poly->Next == NULL) {
        printf("The polynomial is empty.\n");
        return;
    }
    
    printf("The polynomial is : \n");
    
    P = Poly->Next;
    
    if (P == NULL)
        return;
    
    if (P->Exponent < 0) {
        LeftBracketOrNil = "(";
        RightBracketOrNil = ")";
    } else {
        LeftBracketOrNil = "";
        RightBracketOrNil = "";
    }
    
    printf("%d * X ^ %s%d%s", P->Coeff, LeftBracketOrNil, P->Exponent, RightBracketOrNil);
    
    P = P->Next;
    
    while (P != NULL) {
        Coeff = P->Coeff;
        
        putchar(' ');
        
        if (Coeff > 0)
            putchar('+');
        else {
            Coeff = -Coeff;
            putchar('-');
        }
        
        if (P->Exponent < 0) {
            LeftBracketOrNil = "(";
            RightBracketOrNil = ")";
        } else {
            LeftBracketOrNil = "";
            RightBracketOrNil = "";
        }
        
        printf(" %d * X ^ %s%d%s", Coeff, LeftBracketOrNil, P->Exponent, RightBracketOrNil);
        
        P = P->Next;
    }
    
    putchar('\n');
}
