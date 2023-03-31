#include "FunctionsCalc.h"

void FunctionsMenu()
{
	double choose;
	int s_choose;

    do
    {
		cout << "�������� ��������: \n";
		cout << "0) ����� � ������� ����\n";
		cout << "1) ���������� ���������� ��������� ��������� �� �������\n";
		cout << "2) ���������� ������� �������\n";
		cout << "3) ����� ����� y = 0\n";
		cout << "4) ����� ����������\n";

		cin >> choose;

		while (round(choose) != choose)
		{
			cout << "������������ ����, ��������� �����: ";
			cin >> choose;
		} s_choose = (int)choose;

		switch (s_choose) {
		case 1:break;
		case 2: break;
		case 3:break;
		case 4: break;
		case 0:return; break;
		default: cout << "������������ ��������!\n";
		}

    } while (s_choose != 0);


};

Polynomial enter_polynomial() {
	Polynomial p;
	double N;

	cout << "������� ������� ��������: ";
	cin >> N;

	while (round(N) != N || N <= 0)
	{
		cout << "������������ ��������, ��������� ����: ";
		cin >> N;
	} p.N = N;

	for (int id = 0; id < N; id++)
	{
		cout << "������� " << id + 1 << "-� ��������� ��������: ";
		cin >> p.a[id];
	}

	return p;
}

double polynomial_value(const Polynomial& p, double x) {
    double y = 0.0;
    for (int i = p.N; i >= 0; i--) {
        y = y * x + p.a[i];
    }
    return y;
}

Power enter_power() {
	Power f;
	cout << "������� ���������� ��������� �-�� (a*x^b + c).\n";

	cout << "a = ";
	cin >> f.a;
	cout << "b = ";
	cin >> f.b;
	cout << "c = ";
	cin >> f.c;

	return f;
}

double power_value(const Power& f, double x) {
    return f.a * pow(x, f.b) + f.c;
}

Exponential enter_exponental() {
	Exponential f;
	cout << "������� ���������� ��������������� �-�� (a*b^(c*x) + d).\n";

	cout << "a = ";
	cin >> f.a;
	cout << "b = ";
	cin >> f.b;
	cout << "c = ";
	cin >> f.c;
	cout << "d = ";
	cin >> f.d;

	return f;
}

double exponential_value(const Exponential& f, double x) {
    return f.a * pow(f.b, f.c * x) + f.d;
}

Logarithm enter_logarithm() {
	Logarithm f;
	cout << "������� ���������� ��������������� �-�� (a*ln(b*x) + c).\n";

	cout << "a = ";
	cin >> f.a;
	cout << "b = ";
	cin >> f.b;
	cout << "c = ";
	cin >> f.c;

	return f;
}

double logarithm_value(const Logarithm& f, double x) {
    return f.a * log(f.b * x) + f.c;
}

Sinusoid enter_sinusoid() {
	Sinusoid f;
	cout << "������� ���������� �-�� ��������� (a*sin(b*x + c) + d).\n";

	cout << "a = ";
	cin >> f.a;
	cout << "b = ";
	cin >> f.b;
	cout << "c = ";
	cin >> f.c;
	cout << "d = ";
	cout << "d = ";
	cin >> f.d;

	return f;
}

double sinusoid_value(const Sinusoid& f, double x) {
    return f.a * sin(f.b * x + f.c) + f.d;
}

Cosinusoid enter_cosinusoid() {
	Cosinusoid f;
	cout << "������� ���������� �-�� ����������� (a*cos(b*x + c) + d).\n";

	cout << "a = ";
	cin >> f.a;
	cout << "b = ";
	cin >> f.b;
	cout << "c = ";
	cin >> f.c;
	cout << "d = ";
	cout << "d = ";
	cin >> f.d;

	return f;
}

double cosinusoid_value(const Cosinusoid& f, double x) {
    return f.a * cos(f.b * x + f.c) + f.d;
}