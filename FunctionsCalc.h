//Krasivin V. A.
#pragma once
#include <iostream>

using namespace std;


struct Polynomial {
    int N;        // степень полинома
    double* a;    // массив коэффициентов a[i], i=0..N
};

struct Power {
    double a, b, c;    // коэффициенты a*x^b + c
};

struct Exponential {
    double a, b, c, d; // коэффициенты a*b^(c*x) + d
};

struct Logarithm {
    double a, b, c;    // коэффициенты a*ln(b*x) + c
};

struct Sinusoid {
    double a, b, c, d; // коэффициенты a*sin(b*x + c) + d
};

struct Cosinusoid {
    double a, b, c, d; // коэффициенты a*cos(b*x + c) + d
};


// TODO
double polynomial_value(const Polynomial& p, double x);
double power_value(const Power& f, double x);
double exponential_value(const Exponential& f, double x);
double logarithm_value(const Logarithm& f, double x);
double sinusoid_value(const Sinusoid& f, double x);
double cosinusoid_value(const Cosinusoid& f, double x);