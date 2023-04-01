#include"PolynomialCalc.h"
//Зайцев И. Н.
int ReadPolynomial(char* string)//чтение полинома
{
	char key;
	int string_lenth = 0;
	int size = 0;
	int point;
	system("cls");
	cout << "Enter the polynomial:" << endl;
	for (int i = 0; i < string_lenth; i++) printf("%c", string[i]);
	do
	{
		key = _getch();
	} while (key != '-' && (key < '0' || key > '9'));
	string[string_lenth] = key;
	string_lenth++;
	if (string_lenth == l_max)return 0;
	do//ввод полинома (одночлен за цикл)
	{
		point = 0;
		if (key == '+' || key == '-') {
			do//коэффициент
			{
				system("cls");
				cout << "Enter the polynomial:" << endl;
				for (int i = 0; i < string_lenth; i++) printf("%c", string[i]);
				key = _getch();
			} while ((key < '0' || key > '9'));
			string[string_lenth] = key;
			string_lenth++;
			if (string_lenth == l_max)return 0;
		}
		if (key >= '0' && key <= '9')
		{
			do
			{
				do
				{
					system("cls");
					cout << "Enter the polynomial:" << endl;
					for (int i = 0; i < string_lenth; i++) printf("%c", string[i]);
					key = _getch();
				} while (key != 'x' && (key < '0' || key > '9') && (key != '.' && !point));
				string[string_lenth] = key;
				string_lenth++;
				if (string_lenth == l_max)return 0;
				if (key == '.')point++;
			} while (key != 'x');
		}
		if (key == 'x')//степень
		{
			string[string_lenth] = '^';
			string_lenth++;
			if (string_lenth == l_max)return 0;
			do
			{
				system("cls");
				cout << "Enter the polynomial:" << endl;
				for (int i = 0; i < string_lenth; i++) printf("%c", string[i]);
				key = _getch();
			} while (key < '0' || key > '9');
			string[string_lenth] = key;
			string_lenth++;
			if (string_lenth == l_max)return 0;
			do
			{
				do
				{
					system("cls");
					cout << "Enter the polynomial:" << endl;
					for (int i = 0; i < string_lenth; i++) printf("%c", string[i]);
					key = _getch();
				} while (key != '-' && key != '+' && key != '\r' && (key < '0' || key > '9'));
				//ввод производится до нажатия enter или до указания знака сдедующего одночлена
				string[string_lenth] = key;
				string_lenth++;
				if (string_lenth == l_max)return 0;
			} while (key != '-' && key != '+' && key != '\r');

		}
		size++;
	} while (key != '\r');
	return size;
}
void StringToPolynomial(Monomial* polynomial, char* string, int size)//запись введённых значеинй в массив полинома
{
	int n = 0;
	for (int i = 0; i < size; i++)
	{
		if (string[n] == '-')
		{
			polynomial[i].koefficient *= -1;
			n++;
		}
		if (string[n] == '+') n++;
		polynomial[i].koefficient *= (int(string[n]) - 48);
		n++;
		while (string[n] != '.' && string[n] != 'x')
		{
			polynomial[i].koefficient = polynomial[i].koefficient * 10 + int(string[n]) - 48;
			n++;
		}
		if (string[n] == '.')
		{
			n++;
			double double_part = int(string[n]) - 48;
			n++;
			while (string[n] != 'x')
			{
				double_part = double_part * 10 + int(string[n]) - 48;
				n++;
			}
			while (double_part >= 1)
			{
				double_part = double_part / 10.0;
			}
			polynomial[i].koefficient += double_part;
		}
		n++; n++;
		polynomial[i].pow *= int(string[n]) - 48;
		n++;
		while (string[n] != '+' && string[n] != '-' && string[n] != '\r')
		{
			polynomial[i].pow = polynomial[i].pow * 10 + int(string[n]) - 48;
			n++;
		}
	}
	return;
}
int PolynomialReductAndSort(Monomial* polynomial, int old_size)//сокращение и сортировка полинома
{
	int new_size = old_size;
	Monomial tmp;
	for (int i = 1; i < new_size; i++)//сокращение
	{
		for (int j = 0; j < i; j++)
		{
			if (polynomial[j].pow == polynomial[i].pow)
			{
				polynomial[j].koefficient += polynomial[i].koefficient;
				tmp = polynomial[i];
				polynomial[i] = polynomial[new_size - 1];
				polynomial[new_size - 1] = tmp;
				new_size--;
				i--;
			}
		}
	}
	for (int i = 0; i < new_size; i++)//удаление одночленов с коэффициентами = 0
	{
		if (polynomial[i].koefficient == 0)
		{
			tmp = polynomial[i];
			polynomial[i] = polynomial[new_size - 1];
			polynomial[new_size - 1] = tmp;
			new_size--;
			i--;
		}
	}
	for (int i = 1; i < new_size; i++)//сортировка
	{
		for (int j = i; j < new_size; j++)
		{
			if (polynomial[j].pow > polynomial[j - 1].pow)
			{
				tmp = polynomial[j];
				polynomial[j] = polynomial[j - 1];
				polynomial[j - 1] = tmp;
			}
		}
	}

	return new_size;
}
void PrintPolynomial(Monomial* polynomial, int size)//вывод полинома на экран
{
	system("cls");
	if (!size)
	{
		printf("0");
		return;
	}
	if (polynomial[0].koefficient < 0)printf("-");
	printf("%.3lfx^%d", fabs(polynomial[0].koefficient), polynomial[0].pow);
	for (int i = 1; i < size; i++)
	{
		if (polynomial[i].koefficient < 0)printf("-");
		else printf("+");
		printf("%.3lfx^%d", fabs(polynomial[i].koefficient), polynomial[i].pow);
	}
	return;
}

void PrintPolynomial2(Monomial* polynomial, int size)//вывод полинома на экран
{
	if (!size)
	{
		printf("0");
		return;
	}
	if (polynomial[0].koefficient < 0)printf("-");
	printf("%.3lfx^%d", fabs(polynomial[0].koefficient), polynomial[0].pow);
	for (int i = 1; i < size; i++)
	{
		if (polynomial[i].koefficient < 0)printf("-");
		else printf("+");
		printf("%.3lfx^%d", fabs(polynomial[i].koefficient), polynomial[i].pow);
	}
	return;
}

void PolynomialSum()//вычисление суммы полиномов
{
	char first_polynomial_string[l_max];
	char second_polynomial_string[l_max];
	Monomial* first_polynomial, * second_polynomial;
	int first_polynomial_size = ReadPolynomial(first_polynomial_string);
	if (!first_polynomial_size)
	{
		return;
	}
	int second_polynomial_size = ReadPolynomial(second_polynomial_string);
	if (!second_polynomial_size)
	{
		return;
	}
	first_polynomial = (Monomial*)malloc(first_polynomial_size * sizeof(Monomial));
	for (int i = 0; i < first_polynomial_size; i++)
	{
		first_polynomial[i].koefficient = 1;
		first_polynomial[i].pow = 1;
	}
	second_polynomial = (Monomial*)malloc(second_polynomial_size * sizeof(Monomial));
	for (int i = 0; i < second_polynomial_size; i++)
	{
		second_polynomial[i].koefficient = 1;
		second_polynomial[i].pow = 1;
	}
	StringToPolynomial(first_polynomial, first_polynomial_string, first_polynomial_size);
	StringToPolynomial(second_polynomial, second_polynomial_string, second_polynomial_size);
	first_polynomial_size = PolynomialReductAndSort(first_polynomial, first_polynomial_size);
	second_polynomial_size = PolynomialReductAndSort(second_polynomial, second_polynomial_size);
	Monomial* result = (Monomial*)malloc((first_polynomial_size + second_polynomial_size) * sizeof(Monomial));
	for (int i = 0; i < first_polynomial_size; i++)result[i] = first_polynomial[i];
	for (int i = first_polynomial_size; i < first_polynomial_size + second_polynomial_size; i++)result[i] = second_polynomial[i - first_polynomial_size];
	int result_size = PolynomialReductAndSort(result, first_polynomial_size + second_polynomial_size);
	PrintPolynomial(result, result_size);
	char key = _getch();
	return;
}

void PolynomialDif()//вычисление разности полиномов
{
	char first_polynomial_string[l_max];
	char second_polynomial_string[l_max];
	Monomial* first_polynomial, * second_polynomial;
	int first_polynomial_size = ReadPolynomial(first_polynomial_string);
	if (!first_polynomial_size)
	{
		return;
	}
	int second_polynomial_size = ReadPolynomial(second_polynomial_string);
	if (!second_polynomial_size)
	{
		return;
	}
	first_polynomial = (Monomial*)malloc(first_polynomial_size * sizeof(Monomial));
	for (int i = 0; i < first_polynomial_size; i++)
	{
		first_polynomial[i].koefficient = 1;
		first_polynomial[i].pow = 1;
	}
	second_polynomial = (Monomial*)malloc(second_polynomial_size * sizeof(Monomial));
	for (int i = 0; i < second_polynomial_size; i++)
	{
		second_polynomial[i].koefficient = 1;
		second_polynomial[i].pow = 1;
	}
	StringToPolynomial(first_polynomial, first_polynomial_string, first_polynomial_size);
	StringToPolynomial(second_polynomial, second_polynomial_string, second_polynomial_size);
	first_polynomial_size = PolynomialReductAndSort(first_polynomial, first_polynomial_size);
	second_polynomial_size = PolynomialReductAndSort(second_polynomial, second_polynomial_size);
	Monomial* result = (Monomial*)malloc((first_polynomial_size + second_polynomial_size) * sizeof(Monomial));
	for (int i = 0; i < first_polynomial_size; i++)result[i] = first_polynomial[i];
	for (int i = first_polynomial_size; i < first_polynomial_size + second_polynomial_size; i++) {
		result[i] = second_polynomial[i - first_polynomial_size]; result[i].koefficient *= -1;
	}
	int result_size = PolynomialReductAndSort(result, first_polynomial_size + second_polynomial_size);
	PrintPolynomial(result, result_size);
	char key = _getch();
	return;
}

void PolynomialMult()//вычисление произведения полиномов
{
	char first_polynomial_string[l_max];
	char second_polynomial_string[l_max];
	Monomial* first_polynomial, * second_polynomial;
	int first_polynomial_size = ReadPolynomial(first_polynomial_string);
	if (!first_polynomial_size)
	{
		return;
	}
	int second_polynomial_size = ReadPolynomial(second_polynomial_string);
	if (!second_polynomial_size)
	{
		return;
	}
	first_polynomial = (Monomial*)malloc(first_polynomial_size * sizeof(Monomial));
	for (int i = 0; i < first_polynomial_size; i++)
	{
		first_polynomial[i].koefficient = 1;
		first_polynomial[i].pow = 1;
	}
	second_polynomial = (Monomial*)malloc(second_polynomial_size * sizeof(Monomial));
	for (int i = 0; i < second_polynomial_size; i++)
	{
		second_polynomial[i].koefficient = 1;
		second_polynomial[i].pow = 1;
	}
	StringToPolynomial(first_polynomial, first_polynomial_string, first_polynomial_size);
	StringToPolynomial(second_polynomial, second_polynomial_string, second_polynomial_size);
	first_polynomial_size = PolynomialReductAndSort(first_polynomial, first_polynomial_size);
	second_polynomial_size = PolynomialReductAndSort(second_polynomial, second_polynomial_size);
	Monomial* result = (Monomial*)malloc((first_polynomial_size * second_polynomial_size) * sizeof(Monomial));
	for (int i = 0; i < first_polynomial_size; i++)
	{
		for (int j = 0; j < second_polynomial_size; j++)
		{
			result[i * first_polynomial_size + j].koefficient = first_polynomial[i].koefficient * second_polynomial[j].koefficient;
			result[i * first_polynomial_size + j].pow = first_polynomial[i].pow + second_polynomial[j].pow;
		}
	}
	int result_size = PolynomialReductAndSort(result, first_polynomial_size * second_polynomial_size);
	result_size = PolynomialReductAndSort(result, result_size);
	PrintPolynomial(result, result_size);
	char key = _getch();
	return;
}

void PolynomialNumberMult()//вычисление произведения полинома на число
{
	char first_polynomial_string[l_max];
	Monomial* first_polynomial;
	int first_polynomial_size = ReadPolynomial(first_polynomial_string);
	int number;
	system("cls");
	cout << "Enter the number: " << endl;
	cin >> number;
	if (!first_polynomial_size)
	{
		return;
	}
	first_polynomial = (Monomial*)malloc(first_polynomial_size * sizeof(Monomial));
	for (int i = 0; i < first_polynomial_size; i++)
	{
		first_polynomial[i].koefficient = 1;
		first_polynomial[i].pow = 1;
	}
	StringToPolynomial(first_polynomial, first_polynomial_string, first_polynomial_size);
	first_polynomial_size = PolynomialReductAndSort(first_polynomial, first_polynomial_size);
	for (int i = 0; i < first_polynomial_size; i++)first_polynomial[i].koefficient *= number;
	PrintPolynomial(first_polynomial, first_polynomial_size);
	char key = _getch();
	return;
}

void PolynomialDeriv()//вычисление производной полинома
{
	char first_polynomial_string[l_max];
	Monomial* first_polynomial;
	int first_polynomial_size = ReadPolynomial(first_polynomial_string);
	if (!first_polynomial_size)
	{
		return;
	}
	first_polynomial = (Monomial*)malloc(first_polynomial_size * sizeof(Monomial));
	for (int i = 0; i < first_polynomial_size; i++)
	{
		first_polynomial[i].koefficient = 1;
		first_polynomial[i].pow = 1;
	}
	StringToPolynomial(first_polynomial, first_polynomial_string, first_polynomial_size);
	first_polynomial_size = PolynomialReductAndSort(first_polynomial, first_polynomial_size);
	for (int i = 0; i < first_polynomial_size; i++)
	{
		first_polynomial[i].koefficient *= first_polynomial[i].pow;
		first_polynomial[i].pow--;
		if (first_polynomial[i].pow < 0)
		{
			first_polynomial[i].koefficient *= 0;
		}
	}
	first_polynomial_size = PolynomialReductAndSort(first_polynomial, first_polynomial_size);
	PrintPolynomial(first_polynomial, first_polynomial_size);
	char key = _getch();
	return;
}

void PolynomialDiv()//вычисление разности 
{
	char first_polynomial_string[l_max];
	char second_polynomial_string[l_max];
	Monomial* first_polynomial, * second_polynomial;
	int first_polynomial_size = ReadPolynomial(first_polynomial_string);
	if (!first_polynomial_size)
	{
		return;
	}
	int second_polynomial_size = ReadPolynomial(second_polynomial_string);
	if (!second_polynomial_size)
	{
		return;
	}
	first_polynomial = (Monomial*)malloc(first_polynomial_size * sizeof(Monomial));
	for (int i = 0; i < first_polynomial_size; i++)
	{
		first_polynomial[i].koefficient = 1;
		first_polynomial[i].pow = 1;
	}
	second_polynomial = (Monomial*)malloc(second_polynomial_size * sizeof(Monomial));
	for (int i = 0; i < second_polynomial_size; i++)
	{
		second_polynomial[i].koefficient = 1;
		second_polynomial[i].pow = 1;
	}
	StringToPolynomial(first_polynomial, first_polynomial_string, first_polynomial_size);
	StringToPolynomial(second_polynomial, second_polynomial_string, second_polynomial_size);
	first_polynomial_size = PolynomialReductAndSort(first_polynomial, first_polynomial_size);
	second_polynomial_size = PolynomialReductAndSort(second_polynomial, second_polynomial_size);
	Monomial* big_polynomial = (Monomial*)malloc((first_polynomial[0].pow + 1) * sizeof(Monomial));
	int t;
	for (int i = 0; i < first_polynomial[0].pow + 1; i++)
	{
		t = 0;
		for (int j = 0; j < first_polynomial_size; j++)
		{
			if (first_polynomial[j].pow == first_polynomial[0].pow - i)
			{
				big_polynomial[i] = first_polynomial[i];
				t = 1;
			}
			else
			{
				big_polynomial[i].koefficient = 0;
				big_polynomial[i].pow = first_polynomial[0].pow - i;
			}
			if (t)break;
		}

	}
	Monomial* small_polynomial = (Monomial*)malloc((second_polynomial[0].pow + 1) * sizeof(Monomial));
	for (int i = 0; i < second_polynomial[0].pow + 1; i++)
	{
		t = 0;
		for (int j = 0; j < second_polynomial_size; j++)
		{
			if (second_polynomial[j].pow == second_polynomial[0].pow - i)
			{
				small_polynomial[i] = second_polynomial[i];
				t = 1;
			}
			else
			{
				small_polynomial[i].koefficient = 0;
				small_polynomial[i].pow = second_polynomial[0].pow - i;
			}
			if (t)break;
		}

	}
	int i = 0;
	system("cls");
	while (first_polynomial[i].pow >= second_polynomial[0].pow)
	{
		for (int j = 0; j + 1 < second_polynomial_size; j++)
		{
			big_polynomial[i + 1 + j].koefficient -= small_polynomial[j + 1].koefficient;
		}
		if (big_polynomial[i].pow - small_polynomial[0].pow >= 0)
		{
			if (big_polynomial[i].koefficient >= 0)printf("+");
			printf("%.3lfx^%d", big_polynomial[i].koefficient / small_polynomial[0].koefficient, big_polynomial[i].pow - small_polynomial[0].pow);
		}
		i++;
	}
	Monomial* new_polynomial = (Monomial*)malloc((first_polynomial[0].pow + 1 - i) * sizeof(Monomial));
	Monomial tmp;
	for (int j = i; j < first_polynomial[0].pow + 1; j++)
	{
		new_polynomial[j - i].koefficient = big_polynomial[j].koefficient;
		new_polynomial[j - i].pow = big_polynomial[j].pow;
		if (new_polynomial[j - i].pow < 0)
		{

			tmp = new_polynomial[j];
			new_polynomial[j] = new_polynomial[first_polynomial[0].pow];
			new_polynomial[first_polynomial[0].pow] = tmp;
			first_polynomial[0].pow--;
			j--;
		}
	}
	int new_size = PolynomialReductAndSort(new_polynomial, first_polynomial[0].pow + 1 - i);
	printf("(");
	PrintPolynomial2(new_polynomial, new_size);
	printf(")");
	char key = _getch();
	return;
}

void PolynomialCalcMenu()
{
	char key;
	do
	{

		do
		{
			system("cls");
			cout << "1 - PolynomialSum\n2 - PolynomialDif\n3 - PolynomialMult\n4 - PolynomialNumberMult\n5 - PolynomialDeriv\n6 - PolynomialDiv\n0 - Exit" << endl;
			key = _getch();
		} while (key < '0' || key>'6');
		switch (int(key) - 48)
		{
		case 0: return;
		case 1: PolynomialSum(); break;
		case 2: PolynomialDif(); break;
		case 3: PolynomialMult(); break;
		case 4: PolynomialNumberMult(); break;
		case 5: PolynomialDeriv(); break;
		default: PolynomialDiv();
		}

	} while (true);
	return;
}