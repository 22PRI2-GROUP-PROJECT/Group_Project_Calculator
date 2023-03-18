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
