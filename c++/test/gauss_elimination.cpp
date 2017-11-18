#include <iostream>
using namespace std;
#include "other.h"

void echelon_form(double **a, int m, int n, double *b)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			double p = a[j][i]/a[i][i];
			b[j] = b[j] - p*b[i];
			for (int k = 0; k < n; ++k)
			{
				a[j][k] = a[j][k] - p*a[i][k];
			}
		}
	}
}


int main(){
	int m, n;
	cout << "Enter the size of matrix" << endl;
	cin >> m >> n;
	double **A;
	A = new double *[m];
	for (int i = 0; i < m; ++i)
	{
		A[i] = new double [n];
	}

	double *b;
	b = new double [m];
	cout << "Enter the elements of the matrix A" << endl;
	scan_matrix(A, m, n);
	cout << "Enter the elements of matrix B" << endl;
	scan_data(b, m);
	echelon_form(A, m, n, b);
	print_matrix(A, m, n);
	print_data(b, m);
}