#include <iostream>
#include "other.h"
#include <math.h>
using namespace std;

void scan_vectors(double **a, int m, int n)
{
	for (int i = 0;i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}
}


void print_vectors(double **a, int m, int n)
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

double get_norm(double *x, int n)
{
	double sum = 0.0;
	for (int i=0; i<n; ++i)
	{
		sum = sum + x[i]*x[i];
	}
	sum = pow(sum, 0.5);
	return sum;
}

void copy_vectors(double **a, double **b, int m, int n)
{
	for (int i = 0;i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			b[i][j] =  a[i][j];
		}
	}
}


double dot_product(double *x, double *y, int n)
{
	double sum = 0.0;
	for (int i = 0; i< n; ++i)
	{
		sum = sum + x[i]*y[i];
	}
}

void gram_schmidt(double **V, double **X, double **R, int m, int n)
{
	double **Y;

	Y = new double *[m];
	for (int i = 0; i<m; ++i)
	{
		Y[i] = new double [n];
	}

	R[0][0] = get_norm(X[0], n);
	for (int k=0; k<n; ++k)
	{
		V[0][k] = V[0][k] / R[0][0];
	}


	for(int j = 1; j < m; ++j)
	{
		for (int i = 0; i< j; ++i)
		{
			R[i][j] = dot_product(V[i], X[j], n);
		}
		for (int k = 0; k< n; ++k)
			{
				Y[j][k] = X[j][k];
				for (int l = 0; l < j; ++l)
					{
						Y[j][k] = Y[j][k] - R[l][j]*V[l][k];
					}
			}
		R[j][j] = get_norm(Y[j], n);
		for (int k = 0; k< n; ++k)
			{
				V[j][k] = Y[j][k] / R[j][j];
			}	
	}
}
	

int main(){
	int m, n;
	cout << "Enter the size of the vector" << endl;
	cin >> n;
	cout << "Enter the number of vectors" << endl;
	cin >> m;
	cout << "Enter the elements of the vectors one by one" << endl;
	double **v, **x, **r;
	v = new double *[m];
	for (int i=0; i<m; ++i)
	{
		v[i] = new double [n];
	}

	x = new double *[m];
	for (int i=0; i<m; ++i)
	{
		x[i] = new double [n];
	}

	r = new double *[m];
	for (int i = 0; i<m; ++i)
	{
		r[i] = new double [m];
	}

	scan_vectors(v, m, n);
	copy_vectors(v, x, m, n);
	gram_schmidt(v, x, r, m, n);
	print_vectors(v, m, n);
	print_vectors(r, m, m);
}

