#include <iostream>
#include <fstream>
#include <string>
#include "other.h"
using namespace std;


void LU_decompose(double **a, int n, double **l, double **u)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			double p = u[j][i]/u[i][i];
			for (int k = 0; k < n; ++k)
			{
				u[j][k] = u[j][k] - p*u[i][k];
			}
		}
	}
	for (int i =0; i <n; ++i)
	{
		for (int j = 0; j <=i; ++j)
		{
			double p = 0.0;
			for (int k = 0; k <= j-1; ++k)
			{
				p = p + l[i][k]*u[k][j];
			}
			l[i][j] = (a[i][j] - p)/(u[j][j]);
		}
	}
}	


void copy_matrix(double **a, int n, double **b)
{
	for (int i =0; i<n; ++i)
	{
		for (int j=0; j <n; ++j)
		{
			b[i][j] = a[i][j];
		}
	}
}


void write_to_file(double **a, int n, string filename)
{
	fstream file;
	file.open(filename.c_str(), ios::out);
	for (int i=0; i<n; i++)
	{
		for(int j=0;j<n; ++j)
		{
			file << a[i][j] << "\t";
		}
		file << endl;
	}
	file.close();
}


int main(){
	int n;
	cout << "Enter the size of symmetric matrix" << endl;
	cin >> n;
	double **A, **L, **U;
	A = new double *[n];
	for (int i = 0; i < n; ++i)
	{
		A[i] = new double [n];
	}
	L = new double *[n];
	for (int i =0; i < n; ++i)
	{
		L[i] = new double [n];
	}
	U = new double *[n];
	for (int i = 0; i <n;++i)
	{
		U[i] = new double [n];
	}

	double *b;
	cout << "Enter the elements of the matrix A" << endl;
	scan_matrix(A, n, n);
	copy_matrix(A, n, U);
	LU_decompose(A, n, L, U);
	print_matrix(L, n, n);
	print_matrix(U, n, n);
	write_to_file(L, n, "lower.txt");
	write_to_file(U, n, "upper.txt");
}
