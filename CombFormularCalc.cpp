#include "CombFormulCalc.h"

void CombMenu() {
	int choose = 0;
	cout << "�������� ��������: \n";
	cout << "0) ����� � ������� ����\n";
	cout << "1) ���������� � ������������\n";
	cout << "2) ���������� ��� ����������\n";
	cout << "3) ��������� � ������������\n";
	cout << "4) ��������� ��� ����������\n";
	cout << "5) ������������\n";
	
	cin >> choose;
	switch (choose) {
	case 1:PlaceWithRepet(); break;
	case 2:PlaceWithoutRepet(); break;
	case 3:CombWithRepet(); break;
	case 4:CombWithoutRepet();break;
	case 5:Permutations(); break;
	case 0:return; break;
	default: cout << "������������ ��������!\n"; CombMenu();
	}
}

long double fact(int factorial)//������� ���������� ���������� �����
{
	if (factorial < 0) 
		return 0;
	if (factorial == 0) 
		return 1; 
	else 
		return factorial * fact(factorial - 1); 
}

void PlaceWithRepet()//������� ���������� ����� ���������� � ������������
{
	double placement, positions, result;
	do {
		cout << "������� ���������� ���� ���������: ";
		cin >> placement;
		cout << endl;
		if (placement <= 0)
			cout << "�������� ��������, ���������� ������ �����: "<<endl;
	} while (placement <= 0);
	do {
		cout << "������� ���������� ����������� ���������: ";
		cin >> positions;
		cout << endl;
		if (positions <= 0)
			cout << "�������� ��������, ���������� ������ �����: "<<endl;
	} while (positions <= 0);
	result = pow(placement , positions);
	cout << "�����: " << result;
}

void PlaceWithoutRepet()//������� ���������� ����� ���������� ��� ����������
{
	double placement, positions, result;
	do {
		cout << "������� ���������� ���� ���������: ";
		cin >> placement;
		cout << endl;
		if (placement <= 0)
			cout << "�������� ��������, ���������� ������ �����: "<<endl;
	} while (placement <= 0);
	do {
		cout <<"������� ���������� ����������� ���������: ";
		cin >> positions;
		cout << endl;
		if (positions <= 0)
			cout << "�������� ��������, ���������� ������ �����: "<<endl;
	} while (positions <= 0);
	result = fact(placement) / fact(placement-positions);
	cout << "�����: " << result;
}
void CombWithRepet()//������� ���������� ����� ��������� � ������������
{
	double n, m, result;
	cout << "�����������, ��� ��������� �� n ��������� �� m." << endl;
	do {
		cout << "������� ����� n ���������: " << endl;
		cin >> n;
		cout << endl;
		if (n <= 0)
			cout << "�������� ��������, ���������� ������ �����: "<<endl;
	} while (n <= 0);
	do {
		cout << "������� ����� m ��������� : ";
		cin >> m;
		cout << endl;
		if (m <= 0)
			cout << "�������� ��������, ���������� ������ �����: "<<endl;
	} while (m <= 0);
	result = (fact(n+m-1))/(fact(m)*fact(n-1));
	cout << "�����: " << result;
}
void CombWithoutRepet()//������� ���������� ����� ��������� ��� ����������
{
	double n, m, result;
	cout << "�����������, ��� ��������� �� n ��������� �� m." << endl;
	do {
		cout << "������� ����� n ���������: "<<endl;
		cin >> n;
		cout << endl;
		if (n <= 0)
			cout << "�������� ��������, ���������� ������ �����: "<<endl;
	} while (n <= 0);
	do {
		cout << "������� ����� m ��������� : ";
		cin >> m;
		cout << endl;
		if (m <= 0)
			cout << "�������� ��������, ���������� ������ �����: "<<endl;
	} while (m <= 0);
	result = fact(n)/(fact(n-m)*fact(m));
	cout << "�����: ����� ��������� �� n �� m = " << result;
}
void Permutations()//������� ���������� ����� ������������
{
		double permutations, result;
		do {
			cout << "������� ����� ������������: ";
			cin >> permutations;
			if (permutations <= 0)
			{
				cout <<endl<< "�������� ��������, ���������� ������ �����: "<<endl;
			}
		} while (permutations <= 0);
				cout << endl;
				result = fact(permutations);
				cout << "�����: " << result;
}

