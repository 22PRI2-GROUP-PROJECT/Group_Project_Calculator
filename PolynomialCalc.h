#pragma once
//Зайцев И. Н.
#include<conio.h>
#include<malloc.h>
#include<iostream>
#include<stdio.h>
#include<math.h>

#define l_max 200

using namespace std;

struct Monomial//одночлен - компонент многочлена
{
	double koefficient;
	int pow;
};

int ReadPolynomial(char* string);//чтение полинома

void StringToPolynomial(Monomial* polynomial, char* string, int size);//запись введённых значеинй в массив полинома

int PolynomialReductAndSort(Monomial* polynomial, int old_size);//сокращение и сортировка полинома

void PrintPolynomial(Monomial* polynomial, int size);//вывод полинома на экран

void PrintPolynomial2(Monomial* polynomial, int size);//вывод полинома на экран

void PolynomialSum();//вычисление суммы полиномов

void PolynomialDif();//вычисление разности полиномов

void PolynomialMult();//вычисление произведения полиномов

void PolynomialNumberMult();//вычисление произведения полинома на число

void PolynomialDeriv();//вычисление производной полинома

void PolynomialDiv();//вычисление разности

void PolynomialCalcMenu();