#include "CombFormulCalc.h"

//to do
long double fact(int factorial)
{
	if (factorial < 0) 
		return 0;
	if (factorial == 0) 
		return 1; 
	else 
		return factorial * fact(factorial - 1); 
}
// to do
void PlaceWithRepet()
{
	double placement, positions, result;
	do {
		cin >> placement;
		cout << endl;
		if (placement <= 0)
			cout << "Неверное значение, попробуйте ввести снова: ";
	} while (placement <= 0);
	do {
		cin >> positions;
		cout << endl;
		if (positions <= 0)
			cout << "Неверное значение, попробуйте ввести снова: ";
	} while (positions <= 0);
	result = pow(placement , positions);
	cout << "Ответ: " << result;
};
//to do
void PlaceWithoutRepet()
{
	double placement, positions, result;
	do {
		cin >> placement;
		cout << endl;
		if (placement <= 0)
			cout << "Неверное значение, попробуйте ввести снова: ";
	} while (placement <= 0);
	do {
		cin >> positions;
		cout << endl;
		if (positions <= 0)
			cout << "Неверное значение, попробуйте ввести снова: ";
	} while (positions <= 0);
	result = fact(placement) / fact(placement-positions);
	cout << "Ответ: " << result;
};
void CombWithRepet()
{
	double n, m, result;
	do {
		cin >> n;
		cout << endl;
		if (n <= 0)
			cout << "Неверное значение, попробуйте ввести снова: ";
	} while (n <= 0);
	do {
		cin >> m;
		cout << endl;
		if (m <= 0)
			cout << "Неверное значение, попробуйте ввести снова: ";
	} while (m <= 0);
	result = (fact(n+m-1))/(fact(m)*fact(n-1));
	cout << "Ответ: " << result;
};
void CombWithoutRepet()
{
	double n, m, result;
	do {
		cin >> n;
		cout << endl;
		if (n <= 0)
			cout << "Неверное значение, попробуйте ввести снова: ";
	} while (n <= 0);
	do {
		cin >> m;
		cout << endl;
		if (m <= 0)
			cout << "Неверное значение, попробуйте ввести снова: ";
	} while (m <= 0);
			
	 
	result = fact(n)/(fact(n-m)*fact(m));
	cout << "Ответ: " << result;
};
void Permutations()
{
		double permutations, result;
		do {
			cout << "Введите число перестановок: ";
			cin >> permutations;
			if (permutations <= 0)
			{
				cout << "Неверное значение, попробуйте ввести снова: "<<endl;
			}
		} while (permutations <= 0);
				cout << endl;
				result = fact(permutations);
				cout << "Ответ: " << result;
			
		
}

