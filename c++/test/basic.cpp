#include "other.h"
#include <iostream>
using namespace std;


void scan_data(double* a, int n){
	for (int i=0; i<n; i++)
	{
		cin >> a[i];
	}
}

void print_data(double* a, int n){
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << '\t';
	}
}

void initialize_array(int a[], int n){
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
}

void swap(int* x, int* y){
	int temp;
	temp = *y;
	*y = *x;
	*x = temp;
}

void scan_matrix(double **a, int m, int n)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}
}


void print_matrix(double **a, int m, int n)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j =0; j < n; j++)
		{
			cout << a[i][j] << '\t';
		}
		cout << endl;
	}
}

void initialize_matrix(double **a, int m, int n)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = 0;
		}
	}
}