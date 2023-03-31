//Realised by Krasivin V. A.
#pragma once
#include <iostream>

using namespace std;


struct Polynomial {
    int N;        // степень полинома
    double* a;    // массив коэффициентов a[i], i=0..N
};

struct Power {
    double a, b, c;    // a*x^b + c
};

struct Exponential {
    double a, b, c, d; // a*b^(c*x) + d
};

struct Logarithm {
    double a, b, c;    // a*ln(b*x) + c
};

struct Sinusoid {
    double a, b, c, d; // a*sin(b*x + c) + d
};

struct Cosinusoid {
    double a, b, c, d; // a*cos(b*x + c) + d
};


void FunctionsMenu();


Polynomial EnterPolynomial();
double PolynomialValue(const Polynomial& p, double x);
double PolynomialDerivative(const Polynomial& p, double x);

Power EnterPower();
double PowerValue(const Power& f, double x);
double PowerDerivative(const Power& f, double x);

Exponential EnterExponental();
double ExponentialValue(const Exponential& f, double x);
double ExponentialDerivative(const Exponential& f, double x);

Logarithm EnterLogarithm();
double LogarithmValue(const Logarithm& f, double x);
double LogarithmDerivative(const Logarithm& f, double x);

Sinusoid EnterSinusoid();
double SinusoidValue(const Sinusoid& f, double x);
double SinusoidDerivative(const Sinusoid& f, double x);

Cosinusoid EnterCosinusoid();
double CosinusoidValue(const Cosinusoid& f, double x);
double CosinusoidDerivative(const Cosinusoid& f, double x);
