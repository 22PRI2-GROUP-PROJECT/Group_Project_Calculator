#include "ProbStatCalc.h"
// Zhurov E. D.
void ProbStatCalcMenu() {
	int choose = 0;
	cout << "Выберите операцию\n";
	cout << "0) Вернуться в главное меню\n"
	cout << "1) Найти вероятность m/n\n";
	cout << "2) Найти математическое ожидание\n";
	cout << "3) Найти дисперсию\n";
	cin >> choose;
	switch (choose) {
	case 0: return;
	case 1:ProbabilityCalc(); break;
	case 2:MathExpectation(); break;
	case 3:DispersionCalc(); break;
	default: cout << "Неверное значение!\n"; ProbStatCalcMenu();
	}
}

void ProbabilityCalc() {// Вероятность
	int n, m;
	do {
		cout << "Введите кол-во благоприятствующих событию A исходов: ";
		cin >> m;
		cout << "Введите кол-во всех возможных исходов: ";
		cin >> n;
	} while ((n < 0) || (m <= 0));
	cout << "P(A): " << double(m) / double(n);
}

void DispersionCalc() {// Дисперсия
	int number_of_values;
	do {
		cout << "Введите кол-во значений\n";
		cin >> number_of_values;
		if (number_of_values < 1) cout << "Ошибка! Значение не может быть < 1!";
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
void MathExpectation() {// Мат. ожидание
	int number_of_values;
	do {
		cout << "Введите кол-во значений\n";
		cin >> number_of_values;
		if (number_of_values < 1) cout << "Ошибка! Значение не может быть < 1!";
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