#include "FractionsCalc.h"
// Zhurov E. D.

void FractionsMenu() {
	int choose = 0;
	cout << "Выберите операцию\n";
	cout << "1) Базовые математические операции\n";
	cout << "2) Сравнение дробей\n";
	cout << "3) Сокращение дроби\n";
	cout << "4) Перевод в десятичную дробь\n";
	cin >> choose;
	switch (choose) {
	case 1:
	case 2:
	case 3:
	case 4: FractionInput(choose); break;
	default: cout << "Неверное значение!\n"; FractionsMenu();
	}
}

void FractionInput(int ch) {
	struct Fraction Frac;
	struct Fraction Frac_2;
	cout << "Добавить дробь\n";
	cout << "1) Смешанная дробь\n";
	cout << "2) Обыкновенная дробь\n";
	int choose_2;
	do { // Ввод первой дроби
		cin >> choose_2;
		switch (choose_2) {
		case 1:
			cout << "Введите целую часть\n"; cin >> Frac.integer;
			cout << "Введите числитель\n"; cin >> Frac.numerator;
			do {
				cout << "Введите знаменатель\n"; cin >> Frac.denominator;
				if (Frac.denominator == 0) cout << "Знаменатель не может быть 0!\n";
			} while (Frac.denominator == 0); break;
		case 2:
			cout << "Введите числитель\n"; cin >> Frac.numerator;
			do {
				cout << "Введите знаменатель\n"; cin >> Frac.denominator;
				if (Frac.denominator == 0) cout << "Знаменатель не может быть 0!\n";
			} while (Frac.denominator == 0); break;
		default: cout << "Ошибка!\n";
		}
	} while ((choose_2 != 1) && (choose_2 != 2));

	// Уравнивание знаков минус для первой дроби
	if ((Frac.integer != 0) && (Frac.denominator * Frac.integer * Frac.numerator < 0)) Frac.minus = true;
	if ((Frac.integer == 0) && (Frac.denominator * Frac.numerator < 0)) Frac.minus = true;

	if (Frac.denominator < 0) Frac.denominator *= -1;
	if (Frac.integer < 0) Frac.integer *= -1;
	if (Frac.numerator < 0) Frac.numerator *= -1;

	if ((ch == 1) || (ch == 2)) { // Ввод второй дроби
		cout << "Добавить вторую дробь\n";
		cout << "1) Смешанная дробь\n";
		cout << "2) Обыкновенная дробь\n";
		int choose_2;
		do {
			cin >> choose_2;
			switch (choose_2) {
			case 1:
				cout << "Введите целую часть\n"; cin >> Frac_2.integer;
				cout << "Введите числитель\n"; cin >> Frac_2.numerator;
				do {
					cout << "Введите знаменатель\n"; cin >> Frac_2.denominator;
					if (Frac.denominator == 0) cout << "Знаменатель не может быть 0!\n";
				} while (Frac_2.denominator == 0); break;
			case 2:
				cout << "Введите числитель\n"; cin >> Frac_2.numerator;
				do {
					cout << "Введите знаменатель\n"; cin >> Frac_2.denominator;
					if (Frac.denominator == 0) cout << "Знаменатель не может быть 0!\n";
				} while (Frac_2.denominator == 0); break;
			default: cout << "Ошибка!\n";
			}
		} while ((choose_2 != 1) && (choose_2 != 2));

		// Уравнивание знаков для второй дроби
		if ((Frac_2.integer != 0) && (Frac_2.denominator * Frac_2.integer * Frac_2.numerator < 0))
			Frac_2.minus = true;
		if ((Frac_2.integer == 0) && (Frac_2.denominator * Frac_2.numerator < 0)) Frac_2.minus = true;

		if (Frac_2.denominator < 0) Frac_2.denominator *= -1;
		if (Frac_2.integer < 0) Frac_2.integer *= -1;
		if (Frac_2.numerator < 0) Frac_2.numerator *= -1;

		// Вывод дробей
		if ((Frac.integer != 0) || (Frac_2.integer != 0)) {
			cout << "Первая дробь: ";
			if (Frac.minus == true) cout << "-";
			cout << Frac.integer << " " << Frac.numerator << "/" << Frac.denominator << endl;
			cout << "Вторая дробь: ";
			if (Frac_2.minus == true) cout << "-";
			cout << Frac_2.integer << " " << Frac_2.numerator << "/" << Frac_2.denominator << endl;
		}
		else {
			cout << "Первая дробь: ";
			if (Frac.minus == true) cout << "-";
			cout << Frac.numerator << "/" << Frac.denominator << endl;
			cout << "Вторая дробь: ";
			if (Frac_2.minus == true) cout << "-";
			cout << Frac_2.numerator << "/" << Frac_2.denominator << endl;
		}
	}
	if ((ch == 3) || (ch == 4)) { // Вывод дробей
		if (Frac.minus == true) cout << "-";
		if (Frac.integer == 0) {
			cout << Frac.numerator << "/" << Frac.denominator << endl;
		}
		else cout << Frac.integer << " " << Frac.numerator << "/" << Frac.denominator << endl;
	}

	if (ch == 1) { // Переход к конкретным мат. действиям
		BasicOperationsFractions(Frac, Frac_2);
	}
	if (ch == 2) {
		ComparisonFractionsCalc(Frac, Frac_2);
	}
	if (ch == 3) {
		ReductionFractionsCalc(Frac);
	}
	if (ch == 4) {
		DecimalFractionsCalc(Frac);
	}
}

void BasicOperationsFractions(struct Fraction Frac, struct Fraction Frac_2) { // Базовые математические операции над дробями
	int choose_basic_operation = 0;
	do {
		cout << "Выберите операцию\n";
		cout << "1) Сложение\n";
		cout << "2) Вычитание из первой дроби второй\n";
		cout << "3) Деление первой дроби на вторую\n";
		cout << "4) Умножение\n";
		cin >> choose_basic_operation;
		if ((choose_basic_operation != 1) && (choose_basic_operation != 2) && (choose_basic_operation != 3) && (choose_basic_operation != 4))
			cout << "Ошибка!\n";
	} while ((choose_basic_operation != 1) && (choose_basic_operation != 2) && (choose_basic_operation != 3) && (choose_basic_operation != 4));

	if (choose_basic_operation == 1) {// Сложение
		int temporary_denominator = Frac.denominator;
		Frac.numerator *= Frac_2.denominator;
		Frac.denominator *= Frac_2.denominator;
		Frac_2.numerator *= temporary_denominator;
		Frac_2.denominator *= temporary_denominator;
		if ((Frac.minus == 0) && (Frac_2.minus == 0)) {
			Frac.integer += Frac_2.integer;
			Frac.numerator += Frac_2.numerator;
		}
		if ((Frac.minus == 1) && (Frac_2.minus == 0)) {
			Frac.integer = Frac_2.integer - Frac.integer;
			Frac.numerator = Frac_2.numerator - Frac.numerator;
			if ((Frac.integer != 0) && (Frac.denominator * Frac.integer * Frac.numerator > 0)) Frac.minus = false;
			if ((Frac.integer == 0) && (Frac.denominator * Frac.numerator > 0)) Frac.minus = false;
			if (Frac.integer < 0) Frac.integer *= -1;
			if (Frac.numerator < 0) Frac.numerator *= -1;
		}
		if ((Frac.minus == 0) && (Frac_2.minus == 1)) {
			Frac.integer -= Frac_2.integer;
			Frac.numerator -= Frac_2.numerator;
			if ((Frac.integer != 0) && (Frac.denominator * Frac.integer * Frac.numerator > 0)) Frac.minus = false;
			if ((Frac.integer == 0) && (Frac.denominator * Frac.numerator > 0)) Frac.minus = false;
			if (Frac.integer < 0) Frac.integer *= -1;
			if (Frac.numerator < 0) Frac.numerator *= -1;
		}
		if ((Frac.minus == 1) && (Frac_2.minus == 1)) {
			Frac.integer = -Frac_2.integer - Frac.integer;
			Frac.numerator = -Frac_2.numerator - Frac.numerator;

		}
	}
	if (choose_basic_operation == 2) {// Вычитание
		int temporary_denominator = Frac.denominator;
		Frac.numerator *= Frac_2.denominator;
		Frac.denominator *= Frac_2.denominator;
		Frac_2.numerator *= temporary_denominator;
		Frac_2.denominator *= temporary_denominator;
		if ((Frac.minus == 0) && (Frac_2.minus == 0)) {
			Frac.integer -= Frac_2.integer;
			Frac.numerator -= Frac_2.numerator;
			if ((Frac.integer != 0) && (Frac.denominator * Frac.integer * Frac.numerator > 0)) Frac.minus = false;
			if ((Frac.integer == 0) && (Frac.denominator * Frac.numerator > 0)) Frac.minus = false;
			if (Frac.integer < 0) Frac.integer *= -1;
			if (Frac.numerator < 0) Frac.numerator *= -1;
		}
		if ((Frac.minus == 1) && (Frac_2.minus == 0)) {
			Frac.integer = -Frac_2.integer - Frac.integer;
			Frac.numerator = -Frac_2.numerator - Frac.numerator;
		}
		if ((Frac.minus == 0) && (Frac_2.minus == 1)) {
			Frac.integer += Frac_2.integer;
			Frac.numerator += Frac_2.numerator;
		}
		if ((Frac.minus == 1) && (Frac_2.minus == 1)) {
			Frac.integer = Frac_2.integer - Frac.integer;
			Frac.numerator = Frac_2.numerator - Frac.numerator;
			if ((Frac.integer != 0) && (Frac.denominator * Frac.integer * Frac.numerator > 0)) Frac.minus = false;
			if ((Frac.integer == 0) && (Frac.denominator * Frac.numerator > 0)) Frac.minus = false;
			if (Frac.integer < 0) Frac.integer *= -1;
			if (Frac.numerator < 0) Frac.numerator *= -1;
		}
	}
	if (choose_basic_operation == 3) {// Деление
		if ((Frac.minus == 1) && (Frac_2.minus == 1))Frac.minus = false;
		if ((Frac.minus == 1) && (Frac_2.minus == 0))Frac.minus = true;
		if ((Frac.minus == 0) && (Frac_2.minus == 1))Frac.minus = true;
		if ((Frac.minus == 0) && (Frac_2.minus == 0))Frac.minus = false;
		if (Frac.integer != 0) {
			Frac.numerator = Frac.numerator + (Frac.integer * Frac.denominator);
			Frac.integer = 0;
		}
		if (Frac_2.integer != 0) {
			Frac_2.numerator = Frac_2.numerator + (Frac_2.integer * Frac_2.denominator);
			Frac_2.integer = 0;
		}
		Frac.numerator *= Frac_2.denominator;
		Frac.denominator *= Frac_2.numerator;
	}
	if (choose_basic_operation == 4) { // Умножение
		if ((Frac.minus == 1) && (Frac_2.minus == 1)) Frac.minus = false;
		if ((Frac.minus == 1) && (Frac_2.minus == 0)) Frac.minus = true;
		if ((Frac.minus == 0) && (Frac_2.minus == 1)) Frac.minus = true;
		if ((Frac.minus == 0) && (Frac_2.minus == 0)) Frac.minus = false;
		if (Frac.integer != 0) {
			Frac.numerator = Frac.numerator + (Frac.integer * Frac.denominator);
			Frac.integer = 0;
		}
		if (Frac_2.integer != 0) {
			Frac_2.numerator = Frac_2.numerator + (Frac_2.integer * Frac_2.denominator);
			Frac_2.integer = 0;
		}
		Frac.numerator *= Frac_2.numerator;
		Frac.denominator *= Frac_2.denominator;
	}
	ReductionFractionsCalc(Frac);
}
void ComparisonFractionsCalc(struct Fraction Frac, struct Fraction Frac_2) {// Сравнение дробей
	if (((Frac.minus == true) && (Frac_2.minus == false)) || ((Frac.minus == false) && (Frac_2.minus == true))) {
		if ((Frac.integer != 0) || (Frac_2.integer != 0)) {
			if (Frac.minus == true) cout << "-";
			cout << Frac.integer << " " << Frac.numerator << "/" << Frac.denominator;
			if ((Frac.minus == true) && (Frac_2.minus == false)) cout << " < ";
			if ((Frac.minus == false) && (Frac_2.minus == true)) cout << " > ";
			if (Frac_2.minus == true) cout << "-";
			cout << Frac_2.integer << " " << Frac_2.numerator << "/" << Frac_2.denominator << endl;
		}
		else {
			if (Frac.minus == true) cout << "-";
			cout << Frac.numerator << "/" << Frac.denominator;
			if ((Frac.minus == true) && (Frac_2.minus == false)) cout << " < ";
			if ((Frac.minus == false) && (Frac_2.minus == true)) cout << " > ";
			if (Frac_2.minus == true) cout << "-";
			cout << Frac_2.numerator << "/" << Frac_2.denominator << endl;
		}
	}
	if (Frac.minus == Frac_2.minus) {
		if (Frac.integer != 0) {
			Frac.numerator = Frac.numerator + (Frac.integer * Frac.denominator);
			Frac.integer = 0;
		}
		if (Frac_2.integer != 0) {
			Frac_2.numerator = Frac_2.numerator + (Frac_2.integer * Frac_2.denominator);
			Frac_2.integer = 0;
		}
		int temporary_denominator = Frac.denominator;
		Frac.numerator *= Frac_2.denominator;
		Frac.denominator *= Frac_2.denominator;
		Frac_2.numerator *= temporary_denominator;
		Frac_2.denominator *= temporary_denominator;
		if ((Frac.integer != 0) || (Frac_2.integer != 0)) {
			if (Frac.minus == true) cout << "-";
			cout << Frac.integer << " " << Frac.numerator << "/" << Frac.denominator;
			if ((Frac.minus == 0) && (Frac_2.minus == 0)) {
				if (Frac.numerator > Frac_2.numerator) cout << " > ";
				if (Frac.numerator < Frac_2.numerator) cout << " < ";
			}
			if ((Frac.minus == 1) && (Frac_2.minus == 1)) {
				if (Frac.numerator > Frac_2.numerator) cout << " < ";
				if (Frac.numerator < Frac_2.numerator) cout << " > ";
			}
			if (Frac.numerator == Frac_2.numerator) cout << " = ";
			if (Frac_2.minus == true) cout << "-";
			cout << Frac_2.integer << " " << Frac_2.numerator << "/" << Frac_2.denominator << endl;
		}
		else {
			if (Frac.minus == true) cout << "-";
			cout << Frac.numerator << "/" << Frac.denominator;
			if ((Frac.minus == 0) && (Frac_2.minus == 0)) {
				if (Frac.numerator > Frac_2.numerator) cout << " > ";
				if (Frac.numerator < Frac_2.numerator) cout << " < ";
			}
			if ((Frac.minus == 1) && (Frac_2.minus == 1)) {
				if (Frac.numerator > Frac_2.numerator) cout << " < ";
				if (Frac.numerator < Frac_2.numerator) cout << " > ";
			}
			if (Frac.numerator == Frac_2.numerator) cout << " = ";
			if (Frac_2.minus == true) cout << "-";
			cout << Frac_2.numerator << "/" << Frac_2.denominator << endl;
		}
	}
	FractionsMenu();
}
void ReductionFractionsCalc(struct Fraction Frac) {// Сокращение дробей
	if (Frac.denominator == 0) {
		cout << "Ошибка! Деление на 0!\n"; FractionsMenu();
	}
	else {
		Frac.integer = Frac.integer + Frac.numerator / Frac.denominator;
		Frac.numerator = Frac.numerator % Frac.denominator;
	}

	for (int i = Frac.numerator; i > 0; i--) {
		if ((Frac.numerator % i == 0) && (Frac.denominator % i == 0)) {
			Frac.numerator /= i;
			Frac.denominator /= i;
			break;
		}
	}
	cout << "Ответ: ";
	if (Frac.minus == true) cout << "-";
	if (Frac.numerator == 0)
		cout << Frac.integer << endl;
	else if (Frac.integer == 0)
		cout << Frac.numerator << "/" << Frac.denominator << endl;
	else cout << Frac.integer << " " << Frac.numerator << "/" << Frac.denominator << endl;
	cout << "Ответ в десятичной дроби: ";
	DecimalFractionsCalc(Frac);
}
void DecimalFractionsCalc(struct Fraction Frac) {// Перевод в десятичную дробь
	if (Frac.denominator == 0) {
		cout << "Ошибка! Деление на 0!\n"; FractionsMenu();
	}
	double decimal = 0;
	decimal += double(Frac.numerator) / double(Frac.denominator) + Frac.integer;
	if (Frac.minus == true) cout << "-";
	cout << decimal << endl;
	FractionsMenu();
}