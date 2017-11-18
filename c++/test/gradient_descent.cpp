#include <iostream>
#include "other.h"
using namespace std;


void multiply_Ax(double **A, double *x, double *C, int m1, int n1)
{
	for (int i = 0; i < m1; ++i)
	{
		C[i] = 0.0;
		for (int k = 0; k < n1; ++k)
		{
			C[i] = C[i] + A[i][k]*x[k];
		}
	}
}

double compute_alpha(double **A, double *C, double *r0, int n)
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
		den = den + r0[i]*C[i];
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

void dfan(double *out, double *in1, double *in2, int n)
{
	for (int i = 0;i < n; ++i)
	{
		out[i] = in1[i] - in2[i];
	}
}

void copy_vectors(double *a, double *b, int n)
{
	for (int i = 0;i < n; ++i)
	{
		b[i] = a[i];
	}
}

double* Gradient_Descent(double **A, double *b, double *x0, int n, double tolerance)
{
	double *r0, *x1, *C;
	double alpha;
	int count = 0;
	C = new double [n];
	r0 = new double [n];
	x1 = new double [n];
	multiply_Ax(A, x0, C, n, n);
	dfan(r0, C, b, n);

	while(norm(r0, n) > tolerance)
	{
		multiply_Ax(A, r0, C, n, n);
		alpha = compute_alpha(A, C, r0, n);
		for (int i =0; i<n; ++i)
		{
			x1[i] = x0[i] - alpha*r0[i];
		}
		multiply_Ax(A, x1, C, n, n);
		dfan(r0, C, b, n);
		copy_vectors(x1, x0, n);
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
	x = Gradient_Descent(A, b, x0, n, 1e-12);
	for (int i = 0; i<n; ++i)
	{
		cout << x[i] << endl;
	}
	return 0;
}