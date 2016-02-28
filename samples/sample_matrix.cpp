// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

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
	cout << "������������ �������� ��������� ������������� ����������� ������"<< endl;
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
