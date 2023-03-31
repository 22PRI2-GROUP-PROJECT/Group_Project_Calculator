#include "ProbStatCalc.h"
// Zhurov E. D.
void ProbStatCalcMenu() {
	int choose = 0;
	cout << "�������� ��������\n";
	cout << "0) ��������� � ������� ����\n"
	cout << "1) ����� ����������� m/n\n";
	cout << "2) ����� �������������� ��������\n";
	cout << "3) ����� ���������\n";
	cin >> choose;
	switch (choose) {
	case 0: return;
	case 1:ProbabilityCalc(); break;
	case 2:MathExpectation(); break;
	case 3:DispersionCalc(); break;
	default: cout << "�������� ��������!\n"; ProbStatCalcMenu();
	}
}

void ProbabilityCalc() {// �����������
	int n, m;
	do {
		cout << "������� ���-�� ������������������ ������� A �������: ";
		cin >> m;
		cout << "������� ���-�� ���� ��������� �������: ";
		cin >> n;
	} while ((n < 0) || (m <= 0));
	cout << "P(A): " << double(m) / double(n);
}

void DispersionCalc() {// ���������
	int number_of_values;
	do {
		cout << "������� ���-�� ��������\n";
		cin >> number_of_values;
		if (number_of_values < 1) cout << "������! �������� �� ����� ���� < 1!";
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
void MathExpectation() {// ���. ��������
	int number_of_values;
	do {
		cout << "������� ���-�� ��������\n";
		cin >> number_of_values;
		if (number_of_values < 1) cout << "������! �������� �� ����� ���� < 1!";
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