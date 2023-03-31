#include "CombFormulCalc.h"

void CombMenu() {
	int choose = 0;
	cout << "Выберите операцию: \n";
	cout << "0) Выход в главное меню\n";
	cout << "1) Размещения с повторениями\n";
	cout << "2) Размещения без повторений\n";
	cout << "3) Сочетания с повторениями\n";
	cout << "4) Сочетания без повторений\n";
	cout << "5) Перестановки\n";
	
	cin >> choose;
	switch (choose) {
	case 1:PlaceWithRepet(); break;
	case 2:PlaceWithoutRepet(); break;
	case 3:CombWithRepet(); break;
	case 4:CombWithoutRepet();break;
	case 5:Permutations(); break;
	case 0:return; break;
	default: cout << "Неправильное значение!\n"; CombMenu();
	}
}

long double fact(int factorial)//Функция нахождения факториала числа
{
	if (factorial < 0) 
		return 0;
	if (factorial == 0) 
		return 1; 
	else 
		return factorial * fact(factorial - 1); 
}

void PlaceWithRepet()//Функция нахождения числа размещений с повторениями
{
	double placement, positions, result;
	do {
		cout << "Введите количество всех элементов: ";
		cin >> placement;
		cout << endl;
		if (placement <= 0)
			cout << "Неверное значение, попробуйте ввести снова: "<<endl;
	} while (placement <= 0);
	do {
		cout << "Введите количество размещаемых элементов: ";
		cin >> positions;
		cout << endl;
		if (positions <= 0)
			cout << "Неверное значение, попробуйте ввести снова: "<<endl;
	} while (positions <= 0);
	result = pow(placement , positions);
	cout << "Ответ: " << result;
}

void PlaceWithoutRepet()//Функция нахождения числа размещений без повторений
{
	double placement, positions, result;
	do {
		cout << "Введите количество всех элементов: ";
		cin >> placement;
		cout << endl;
		if (placement <= 0)
			cout << "Неверное значение, попробуйте ввести снова: "<<endl;
	} while (placement <= 0);
	do {
		cout <<"Введите количество размещаемых элементов: ";
		cin >> positions;
		cout << endl;
		if (positions <= 0)
			cout << "Неверное значение, попробуйте ввести снова: "<<endl;
	} while (positions <= 0);
	result = fact(placement) / fact(placement-positions);
	cout << "Ответ: " << result;
}
void CombWithRepet()//Функция нахождения числа сочетаний с повторениями
{
	double n, m, result;
	cout << "Учитывается, что сочетание из n элементов по m." << endl;
	do {
		cout << "Введите число n элементов: " << endl;
		cin >> n;
		cout << endl;
		if (n <= 0)
			cout << "Неверное значение, попробуйте ввести снова: "<<endl;
	} while (n <= 0);
	do {
		cout << "Введите число m элементов : ";
		cin >> m;
		cout << endl;
		if (m <= 0)
			cout << "Неверное значение, попробуйте ввести снова: "<<endl;
	} while (m <= 0);
	result = (fact(n+m-1))/(fact(m)*fact(n-1));
	cout << "Ответ: " << result;
}
void CombWithoutRepet()//Функция нахождения числа сочетаний без повторений
{
	double n, m, result;
	cout << "Учитывается, что сочетание из n элементов по m." << endl;
	do {
		cout << "Введите число n элементов: "<<endl;
		cin >> n;
		cout << endl;
		if (n <= 0)
			cout << "Неверное значение, попробуйте ввести снова: "<<endl;
	} while (n <= 0);
	do {
		cout << "Введите число m элементов : ";
		cin >> m;
		cout << endl;
		if (m <= 0)
			cout << "Неверное значение, попробуйте ввести снова: "<<endl;
	} while (m <= 0);
	result = fact(n)/(fact(n-m)*fact(m));
	cout << "Ответ: Число сочетаний из n по m = " << result;
}
void Permutations()//Функция нахождения числа перестановок
{
		double permutations, result;
		do {
			cout << "Введите число перестановок: ";
			cin >> permutations;
			if (permutations <= 0)
			{
				cout <<endl<< "Неверное значение, попробуйте ввести снова: "<<endl;
			}
		} while (permutations <= 0);
				cout << endl;
				result = fact(permutations);
				cout << "Ответ: " << result;
}

