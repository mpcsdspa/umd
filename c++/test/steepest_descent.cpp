#include <iostream>
#include "other.h"
using namespace std;


void multiply(double **A,  double *B, double **C, int m1, int n2, int n1)
{
	for (int i = 0; i < m1; ++i)
	{
		for (int j = 0; j < n2; j++)
		{
			C[i][j] = 0.0;
			for (int k = 0; k < n1; k++)
			{
				C[i][j] = C[i][j] + A[i][k]*B[k];
			}
		}
	}
}


double compute_alpha(double **A, double **C, double *r0, int n)
{
	double num, den;
	num = 0.0;
	den = 0.0;
	for (int i =0; i<n; ++i)
	{
		num = num + r0[i]*r0[i];
	}

	for (int i =0; i<n; ++i)
	{
		den = den + r0[i]*C[i][0];
	}
	return num/den;
}

double norm(double *x, int n)
{
	double norm = 0.0;
	for (int i=0; i<n; ++i)
	{
		norm = norm + x[i]*x[i];
	}
	return norm;
}

double* Steepest_Descent(double **A, double *b, double *x0, int n, double tolerance)
{
	double *r0, *x1;
	double alpha;
	int count = 0;

	double **C;
	C = new double *[n];
	for (int i = 0; i<n; ++i)
	{
		C[i] = new double [1];
	}

	r0 = new double [n];
	x1 = new double [n];
	multiply(A, x0, C, n, 1, n);


	for (int i =0; i<n; ++i)
	{
		r0[i] = C[i][0] - b[i];
	}

	while(norm(r0, n) > tolerance)
	{
		multiply(A, r0, C, n, 1, n);
		alpha = compute_alpha(A, C, r0, n);
		for (int i =0; i<n; ++i)
		{
			x1[i] = x0[i] - alpha*r0[i];
		}
		multiply(A, x1, C, n, 1, n);
		for (int i =0; i<n; ++i)
		{
			r0[i] = C[i][0] - b[i];
		}
		for (int i =0; i<n; ++i)
		{
			x0[i] = x1[i];
		}
		count = count + 1;
	}
	cout << "Total number of iterations is " << count << endl;
	return x1;	
}

int main()
{
	int n;
	cout << "Enter the size of the matrix" << endl;
	cin >> n;
	cout << "Enter the matrix A" << endl;
	double **A;
	A = new double *[n];
	for (int i = 0; i<n; ++i)
	{
		A[i] = new double [n];
	}
	scan_matrix(A, n, n);
	cout << "Enter the vector b" << endl;
	double *b, *x0;
	b = new double [n];
	x0 = new double [n];
	for (int i = 0; i<n; ++i)
	{
		cin >> b[i];
		x0[i] = 0.0;
	}
	double *x;
	x = Steepest_Descent(A, b, x0, n, 1e-12);
	for (int i = 0; i<n; ++i)
	{
		cout << x[i] << endl;
	}
	return 0;
}