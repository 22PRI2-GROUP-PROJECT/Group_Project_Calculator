#pragma once
#include <stdlib.h>
#include <locale>
#include <stdio.h>
#include <iostream>
using namespace std;

struct Fraction {
	int numerator = 0;
	int denominator = 0;
	int integer = 0;
	bool minus = false;
};

void FractionsMenu();
void FractionInput(int ch);

void BasicOperationsFractions(struct Fraction Frac, struct Fraction Frac_2);
void ComparisonFractionsCalc(struct Fraction Frac, struct Fraction Frac_2);
void ReductionFractionsCalc(struct Fraction Frac);
void DecimalFractionsCalc(struct Fraction Frac);