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
	cin >> placement;
	cout << endl;
	cin >> positions;
	cout << endl;
	result = placement * positions;
	cout << result;
};
//to do
void PlaceWithoutRepet()
{
	double placement, positions, result;
	cin >> placement;
	cout << endl;
	cin >> positions;
	cout << endl;
	result = fact(placement) / fact(placement-positions);
	cout << result;
};
void CombWithRepet()
{
	double n, m, result;
	cin >> n;
	cout << endl;
	cin >> m;
	cout << endl;
	result = (fact(n+m-1))/(fact(m)*fact(n-1));
	cout << result;
};
void CombWithoutRepet()
{
	double n, m, result;
	cin >> n;
	cout << endl;
	cin >> m;
	cout << endl;
	result = fact(n)/(fact(n-m)*fact(m));
	cout << result;
};
void Permutations()
{
	double permutations, result;
	cin >> permutations;
	cout << endl;
	result = fact(permutations);
	cout << result;
}

