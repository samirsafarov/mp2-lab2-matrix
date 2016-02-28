// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include <time.h>
#include "utmatrix.h"
//---------------------------------------------------------------------------
#define size 10
void main()
{
	TMatrix<int> a(size), b(size), c(size);
	int i, j;
	clock_t start,finish;
	double time;

	setlocale(LC_ALL, "Russian");
	cout << "Тестирование программ поддержки представления треугольных матриц"<< endl;
	for (i = 0; i < size; i++)
		for (j = 0; j < size-i; j++ )
		{
			a[i][j] =  i * 10 + j;
			b[i][j] = (i * 10 + j) * 100;
		}
	start=clock();
	c = a + b;
	finish=clock();
	cout << "Matrix a = " << endl << a << endl;
	cout << "Matrix b = " << endl << b << endl;
	cout << "Matrix c = a + b" << endl << c << endl;
	time=(double)(finish-start)/(double)CLOCKS_PER_SEC;
	cout<<"time"<<time<<endl;
}
//---------------------------------------------------------------------------
