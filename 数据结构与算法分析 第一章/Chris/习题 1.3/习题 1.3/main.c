//
//  main.c
//  习题 1.3
//
//  Created by JianZhang on 2017/2/7.
//  Copyright © 2017年 NUT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <limits.h>

typedef enum {
    false,
    true,
} BOOL;

typedef struct {
    BOOL flag: true; /// if number >= 0, flag == true, else flag == false
    unsigned long integerPart;
    long double fractionPart;
    int decimalPlaces;
} NUTValue;

void printDigit(int digit);
NUTValue NUTValueWithNumber(long double number, int decimalPlaces);
long double fractionPartFrom(long double number, int decimalPlaces);
long double roundUpFraction(long double number, int decimalPlaces);
void printIntegerPart(unsigned long number);
void printFractionPart(long double number, int decimalPlaces);
void printRealNumber(NUTValue value);

int main(int argc, const char * argv[])
{   
    NUTValue value = NUTValueWithNumber(-123.01234567890123, 14);
    printRealNumber(value);
    printf("\n");
    return 0;
}

void printDigit(int digit)
{
    putchar(digit + 48);
}

NUTValue NUTValueWithNumber(long double number, int decimalPlaces)
{
    NUTValue value;
    long double fraction;
    
    /* signed*/
    if (number < 0) {
        value.flag = false;
        number = -number;
    } else
        value.flag = true;
    
    /* integer*/
    value.integerPart = (unsigned long)number;
    
    /* fraction*/
    fraction = fractionPartFrom(number, decimalPlaces);
    value.fractionPart = roundUpFraction(fraction, decimalPlaces);
    
    /* decimal places*/
    value.decimalPlaces = decimalPlaces;
    
    return value;
}

long double fractionPartFrom(long double number, int decimalPlaces)
{
    long double fraction = number - (unsigned long)number;
    return fraction;
}

long double roundUpFraction(long double number, int decimalPlaces)
{
    int index;
    long double roundUp = 0.5;
    
    for (index = 0; index < decimalPlaces; index++)
        roundUp /= 10;
    
    return number + roundUp;
}

void printIntegerPart(unsigned long number)
{
    if (number >= 10)
        printIntegerPart(number / 10);
    
    printDigit((int)number % 10);
}

void printFractionPart(long double number, int decimalPlaces)
{
    int digit;
    
    while (decimalPlaces > 0) {
        number *= 10;
        digit = (int)number;
        printDigit(digit);
        decimalPlaces--;
        number = fractionPartFrom(number, decimalPlaces);
    }
}

void printRealNumber(NUTValue value)
{
    if (!value.flag)
        putchar('-');
    
    printIntegerPart(value.integerPart);
    
    if (value.decimalPlaces > 0) {
        putchar('.');
        printFractionPart(value.fractionPart, value.decimalPlaces);
    }
}
