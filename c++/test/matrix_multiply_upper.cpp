#include <iostream>
#include "other.h"
using namespace std;


void matrix_multiply_upper(double **a, double **b, double **c, int n)
{	
	for(int i =0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
		{
			for (int k=i; k<=j; ++k)
			{
				c[i][j] = c[i][j] + a[i][k]*b[k][j];
			}
		}
	}
}

int main(){
	int n;
	cout << "Enter the size of matrix A" << endl;
	cin >> n;
	double **A, **B, **C;
	A = new double *[n] ;
	B = new double *[n] ;
	C = new double *[n] ;
	for (int i=0; i<n; ++i)
	{
		A[i] = new double [n];
		B[i] = new double [n];
		C[i] = new double [n];
	}
	cout << "Enter the elements of matrix A" << endl;
	scan_matrix(A, n, n);
	cout << "Enter the elements of matrix B" << endl;
	scan_matrix(B, n, n);
	initialize_matrix(C, n, n);
	matrix_multiply_upper(A, B, C, n);
	print_matrix(C, n, n);
}