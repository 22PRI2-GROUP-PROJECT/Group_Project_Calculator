#include "FunctionsCalc.h"

void FunctionsMenu()
{

};

double polynomial_value(const Polynomial& p, double x) {
    double y = 0.0;
    for (int i = p.N; i >= 0; i--) {
        y = y * x + p.a[i];
    }
    return y;
}

double power_value(const Power& f, double x) {
    return f.a * pow(x, f.b) + f.c;
}

double exponential_value(const Exponential& f, double x) {
    return f.a * pow(f.b, f.c * x) + f.d;
}

double logarithm_value(const Logarithm& f, double x) {
    return f.a * log(f.b * x) + f.c;
}

double sinusoid_value(const Sinusoid& f, double x) {
    return f.a * sin(f.b * x + f.c) + f.d;
}

double cosinusoid_value(const Cosinusoid& f, double x) {
    return f.a * cos(f.b * x + f.c) + f.d;
}