#include "FractionsCalc.h"
// Zhurov E. D.
void FractionsMenu(){
	int choose = 0;
	switch (choose) {
	case 1: BasicOperationsFractions(); break;
	case 2: ComparisonFractionsCalc(); break;
	case 3: ReductionFractionsCalc();  break;
	case 4: DecimalFractionsCalc();  break;
	default: cout << "������������ ��������!!!"; FractionsMenu(); 
	}
} // TO DO!

void BasicOperationsFractions() {} // TO DO! // ������� �������������� �������� ��� �������

void ComparisonFractionsCalc(){} // TO DO! // ��������� ������

void ReductionFractionsCalc(){} // TO DO! // ���������� ������

void DecimalFractionsCalc(){} // TO DO! // ������� � ���������� �����