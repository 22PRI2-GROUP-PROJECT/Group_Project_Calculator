//Krasivin V. A.
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


// TODO
void FunctionsMenu();


Polynomial enter_polynomial();
double polynomial_value(const Polynomial& p, double x);

Power enter_power();
double power_value(const Power& f, double x);

Exponential enter_exponental();
double exponential_value(const Exponential& f, double x);

Logarithm enter_logarithm();
double logarithm_value(const Logarithm& f, double x);

Sinusoid enter_sinusoid();
double sinusoid_value(const Sinusoid& f, double x);

Cosinusoid enter_cosinusoid();
double cosinusoid_value(const Cosinusoid& f, double x);
