#pragma once
//������ �. �.
#include<conio.h>
#include<malloc.h>
#include<iostream>
#include<stdio.h>
#include<math.h>

#define l_max 200

using namespace std;

struct Monomial//�������� - ��������� ����������
{
	double koefficient;
	int pow;
};

int ReadPolynomial(char* string);//������ ��������

void StringToPolynomial(Monomial* polynomial, char* string, int size);//������ �������� �������� � ������ ��������

int PolynomialReductAndSort(Monomial* polynomial, int old_size);//���������� � ���������� ��������

void PrintPolynomial(Monomial* polynomial, int size);//����� �������� �� �����

void PrintPolynomial2(Monomial* polynomial, int size);//����� �������� �� �����

void PolynomialSum();//���������� ����� ���������

void PolynomialDif();//���������� �������� ���������

void PolynomialMult();//���������� ������������ ���������

void PolynomialNumberMult();//���������� ������������ �������� �� �����

void PolynomialDeriv();//���������� ����������� ��������

void PolynomialDiv();//���������� ��������

void PolynomialCalcMenu();