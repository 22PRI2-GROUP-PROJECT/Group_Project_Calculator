//Krasivin V. A.
#pragma once
#include <iostream>

using namespace std;


struct Polynomial {
    int N;        // ������� ��������
    double* a;    // ������ ������������� a[i], i=0..N
};

struct Power {
    double a, b, c;    // ������������ a*x^b + c
};

struct Exponential {
    double a, b, c, d; // ������������ a*b^(c*x) + d
};

struct Logarithm {
    double a, b, c;    // ������������ a*ln(b*x) + c
};

struct Sinusoid {
    double a, b, c, d; // ������������ a*sin(b*x + c) + d
};

struct Cosinusoid {
    double a, b, c, d; // ������������ a*cos(b*x + c) + d
};


// TODO
double polynomial_value(const Polynomial& p, double x);
double power_value(const Power& f, double x);
double exponential_value(const Exponential& f, double x);
double logarithm_value(const Logarithm& f, double x);
double sinusoid_value(const Sinusoid& f, double x);
double cosinusoid_value(const Cosinusoid& f, double x);