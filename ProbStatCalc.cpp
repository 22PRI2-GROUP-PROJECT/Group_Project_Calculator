#include "ProbStatCalc.h"
// Zhurov E. D.
void ProbStatCalcMenu() { // TO DO!
	int choose = 0;
	cout << "Choose option\n";
	cout << "1) Finding the probability m/n\n";
	cout << "2) Finding the mathematical expectation\n";
	cout << "3) Finding the variance\n";
	cin >> choose;
	switch (choose) {
	case 1:ProbabilityCalc(); break;
	case 2:MathExpectation(); break;
	case 3:DispersionCalc(); break;
	default: cout << "Wrong value!\n"; ProbStatCalcMenu();
	}
}

void ProbabilityCalc() { // TO DO! // Вероятность
	int n, m;
	do {
		cout << "Enter the number of favorable outcomes: ";
		cin >> m;
		cout << "Enter the number of all outcomes: ";
		cin >> n;
	} while ((n < 0) || (m <= 0));
	cout << "P(A): " << double(m) / double(n);
}

void DispersionCalc() { // TO DO! // Дисперсия
	int number_of_values;
	do {
		cout << "Enter the number of values\n";
		cin >> number_of_values;
		if (number_of_values < 1) cout << "Error! Value cannot be < 1!";
	} while (number_of_values < 1);
	double* x = new double[number_of_values];
	double* p = new double[number_of_values];
	for (int i = 0; i < number_of_values; i++) {
		cout << "x: ";
		cin >> x[i];
		cout << "p: ";
		cin >> p[i];
	}
	double M = 0, D = 0;
	for (int i = 0; i < number_of_values; i++) {
		M += p[i] * x[i];
		D += p[i] * x[i] * x[i];
	}
	cout << "D: " << D - (M * M);
}
void MathExpectation() { // TO DO! // Мат. ожидание
	int number_of_values;
	do {
		cout << "Enter the number of values\n";
		cin >> number_of_values;
		if (number_of_values < 1) cout << "Error! Value cannot be < 1!";
	} while (number_of_values < 1);
	double* x = new double[number_of_values];
	double* p = new double[number_of_values];
	for (int i = 0; i < number_of_values; i++) {
		cout << "x: ";
		cin >> x[i];
		cout << "p: ";
		cin >> p[i];
	}
	double M = 0;
	for (int i = 0; i < number_of_values; i++) {
		M += p[i] * x[i];
	}
	cout << "M: " << M;
}