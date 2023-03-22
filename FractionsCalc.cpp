#include "FractionsCalc.h"
// Zhurov E. D.
void FractionsMenu(){
	int choose = 0;
	switch (choose) {
	case 1: BasicOperationsFractions(); break;
	case 2: ComparisonFractionsCalc(); break;
	case 3: ReductionFractionsCalc();  break;
	case 4: DecimalFractionsCalc();  break;
	default: cout << "Неправильное значение!!!"; FractionsMenu(); 
	}
} // TO DO!

void BasicOperationsFractions() {} // TO DO! // Базовые математические операции над дробями

void ComparisonFractionsCalc(){} // TO DO! // Сравнение дробей

void ReductionFractionsCalc(){} // TO DO! // Сокращение дробей

void DecimalFractionsCalc(){} // TO DO! // Перевод в десятичную дробь