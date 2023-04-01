#include "ProbStatCalc.h"
// Zhurov E. D.
void ProbStatCalcMenu() {
	int choose = 0;
	cout << "Âûáåðèòå îïåðàöèþ\n";
	cout << "0) Âåðíóòüñÿ â ãëàâíîå ìåíþ\n";
	cout << "1) Íàéòè âåðîÿòíîñòü m/n\n";
	cout << "2) Íàéòè ìàòåìàòè÷åñêîå îæèäàíèå\n";
	cout << "3) Íàéòè äèñïåðñèþ\n";
	cin >> choose;
	switch (choose) {
	case 0: return;
	case 1:ProbabilityCalc(); break;
	case 2:MathExpectation(); break;
	case 3:DispersionCalc(); break;
	default: cout << "Íåâåðíîå çíà÷åíèå!\n"; ProbStatCalcMenu();
	}
}

void ProbabilityCalc() {// Âåðîÿòíîñòü
	int n, m;
	do {
		cout << "Ââåäèòå êîë-âî áëàãîïðèÿòñòâóþùèõ ñîáûòèþ A èñõîäîâ: ";
		cin >> m;
		cout << "Ââåäèòå êîë-âî âñåõ âîçìîæíûõ èñõîäîâ: ";
		cin >> n;
	} while ((n < 0) || (m <= 0));
	cout << "P(A): " << double(m) / double(n)<< endl;
	ProbStatCalcMenu();
}

void DispersionCalc() {// Äèñïåðñèÿ
	int number_of_values;
	do {
		cout << "Ââåäèòå êîë-âî çíà÷åíèé\n";
		cin >> number_of_values;
		if (number_of_values < 1) cout << "Îøèáêà! Çíà÷åíèå íå ìîæåò áûòü < 1!";
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
	cout << "D: " << D - (M * M)<< endl;
	delete[] x;
	delete[] p;
	ProbStatCalcMenu();
}
void MathExpectation() {// Ìàò. îæèäàíèå
	int number_of_values;
	do {
		cout << "Ââåäèòå êîë-âî çíà÷åíèé\n";
		cin >> number_of_values;
		if (number_of_values < 1) cout << "Îøèáêà! Çíà÷åíèå íå ìîæåò áûòü < 1!";
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
	delete[] x;
	delete[] p;
	ProbStatCalcMenu();
}
