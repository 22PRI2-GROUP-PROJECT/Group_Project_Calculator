#pragma once
//Realised by Machehin Grigory Alexandrovich

#include <iostream>
#include <locale>
using namespace std;
const int MAX_SIZE = 10;

void inputMatrix(double matrix[][MAX_SIZE], int rows, int cols);
void printMatrix(double matrix[][MAX_SIZE], int rows, int cols);
void addMatrix(double matrix1[][MAX_SIZE], double matrix2[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols);
void subtractMatrix(double matrix1[][MAX_SIZE], double matrix2[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols);
void multiplyMatrix(double matrix1[][MAX_SIZE], double matrix2[][MAX_SIZE], double result[][MAX_SIZE], int rows1, int cols1, int cols2);
void divideMatrix(double matrix1[][MAX_SIZE], double matrix2[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols);
void SumMatrNum(double matrix1[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols);
void SubstractMatrNum(double matrix1[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols);
void MultiplyNumber(double matrix1[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols);
void MatrTransp(double matrix1[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols);
int MatrDeterm(double matrix1[][MAX_SIZE], int rows, int cols);
void MatrReverse(double matrix1[][MAX_SIZE], double result[][MAX_SIZE], int rows, int cols);
void MatrMenu();