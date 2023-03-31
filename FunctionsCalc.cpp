//Realised by Krasivin V. A.
#include "FunctionsCalc.h"

void FunctionsMenu()
{
	system("cls");
	double choose;
	int s_choose;

    do
    {
		cout << "Выберите операцию: \n";
		cout << "0) Выход в главное меню\n";
		cout << "1) Вычисление опредённого интеграла интеграла на отрезке\n";
		cout << "2) Построение графика функции\n";
		cout << "3) Поиск корня y = 0\n";
		cout << "4) Поиск экстремума\n";

		cin >> choose;

		while (round(choose) != choose)
		{
			cout << "Некорректный ввод, повторите снова: ";
			cin >> choose;
		} s_choose = (int)choose;

		switch (s_choose) {
		case 1:break;
		case 2: break;
		case 3:break;
		case 4: break;
		case 0:return; break;
		default: cout << "Неправильное значение!\n";
		}

    } while (s_choose != 0);


};

Polynomial EnterPolynomial() {
	Polynomial p;
	double N;

	cout << "Введите степень полинома: ";
	cin >> N;

	while (round(N) != N || N <= 0)
	{
		cout << "Некорректное значение, повторите ввод: ";
		cin >> N;
	} 

	p.N = N;
	p.a = new double[N + 1];

	for (int id = 0; id < N; id++)
	{
		cout << "Введите " << id + 1 << "-й коэфицент полинома: ";
		cin >> p.a[id];
	}

	return p;
}

double PolynomialValue(const Polynomial& p, double x) {
    double y = 0.0;
    for (int id = p.N; id >= 0; id--) {
        y = y * x + p.a[id];
    }
    return y;
}

double PolynomialDerivative(const Polynomial& p, double x)
{
	double result = 0.0;
	for (int id = 1; id < p.N; id++)
	{
		result += id * p.a[id] * pow(x, id - 1);
	}
}

Power EnterPower() {
	Power f;
	cout << "Введите коэфиценты степенной ф-ии (a*x^b + c).\n";

	cout << "a = ";
	cin >> f.a;
	cout << "b = ";
	cin >> f.b;
	cout << "c = ";
	cin >> f.c;

	return f;
}

double PowerValue(const Power& f, double x) {
    return f.a * pow(x, f.b) + f.c;
}

double PowerDerivative(const Power& f, double x)
{
	return f.a * f.b * pow(x, f.b - 1);
}

Exponential EnterExponental() {
	Exponential f;
	cout << "Введите коэфиценты экспонентальной ф-ии (a*b^(c*x) + d).\n";

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

double ExponentialValue(const Exponential& f, double x) {
    return f.a * pow(f.b, f.c * x) + f.d;
}

double ExponentialDerivative(const Exponential& f, double x)
{
	return f.a * f.c * pow(f.b, f.c * x) * log(f.b);
}

Logarithm EnterLogarithm() {
	Logarithm f;
	cout << "Введите коэфиценты логарифмической ф-ии (a*ln(b*x) + c).\n";

	cout << "a = ";
	cin >> f.a;
	cout << "b = ";
	cin >> f.b;
	cout << "c = ";
	cin >> f.c;

	return f;
}

double LogarithmValue(const Logarithm& f, double x) {
    return f.a * log(f.b * x) + f.c;
}

double LogarithmDerivative(const Logarithm& f, double x)
{
	return f.a / (f.b * x);
}

Sinusoid EnterSinusoid() {
	Sinusoid f;
	cout << "Введите коэфиценты ф-ии синусоиды (a*sin(b*x + c) + d).\n";

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

double SinusoidValue(const Sinusoid& f, double x) {
    return f.a * sin(f.b * x + f.c) + f.d;
}

double SinusoidDerivative(const Sinusoid& f, double x) {
	return f.a * f.b * cos(f.b * x + f.c);
}

Cosinusoid EnterCosinusoid() {
	Cosinusoid f;
	cout << "Введите коэфиценты ф-ии косинусоиды (a*cos(b*x + c) + d).\n";

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

double CosinusoidValue(const Cosinusoid& f, double x) {
    return f.a * cos(f.b * x + f.c) + f.d;
}

double CosinusoidDerivative(const Cosinusoid& f, double x) {
	return -f.a * f.b * sin(f.b * x + f.c);
}