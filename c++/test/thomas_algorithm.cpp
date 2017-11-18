#include <iostream>
using namespace std;


void Thomas_AlgorithmLU(double *a, double *b, double *c, double *l, double *u, double *d, int n)
{
	d[0] = a[0];
	u[0] = c[0];

	for (int i =0; i<n-2; ++i)
	{
		l[i] = b[i]/(d[i]);
		d[i+1] = a[i+1] - l[i]*u[i];
		u[i+1] = c[i+1];
	}

	l[n-2] = b[n-2]/d[n-2];
	d[n-1] = a[n-1] -l[n-2]*u[n-2]; 
}


void Thomas_Algorithm_Solve(double *q, double *l, double *u, double *d, double *x, int n)
{
	double *y;
	y = new double [n];

	// Forward Substituion
	y[0] = q[0];

	for (int i = 1; i<n; ++i)
	{	
		y[i] = q[i] - l[i-1]*y[i-1];
	}

	//Backward Substituion
	x[n-1] = y[n-1]/d[n-1];
	for (int i = n-2; i >= 0; i--)
	{
		x[i] = (y[i] - u[i]*x[i+1])/d[i];
	}

}

void Matrix_L(double *l, int n)
{
	double **L;
	L = new double *[n];
	for (int i = 0; i<n; ++i)
	{
		L[i] =  new double [n];
	}

	for (int i =0; i<n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				L[i][j] = 1.0;
			else if (i == j+1)
				L[i][j] = l[j];
			else
				L[i][j] = 0.0;
		}
	}

	cout << "The lower triangular matrix is " << endl;
	for (int i =0; i<n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << L[i][j] << '\t';
		}
		cout << endl;
	}
}


void Matrix_U(double *d, double *u, int n)
{
	double **U;
	U = new double *[n];
	for (int i = 0; i<n; ++i)
	{
		U[i] =  new double [n];
	}

	for (int i =0; i<n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				U[i][j] = d[i];
			else if (j == i+1)
				U[i][j] = u[i];
			else
				U[i][j] = 0.0;
		}
	}

	cout << "The Upper triangular matrix is " << endl;
	for (int i =0; i<n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << U[i][j] << '\t';
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cout << "Enter the size of matrix" << endl;
	cin >> n;

	double *a, *b, *c, *l, *u, *d, *x, *q;
	a = new double [n];
	b = new double [n-1];
	c = new double [n-1];
	x = new double [n];
	q = new double [n];

	l = new double [n-1];
	d = new double [n];
	u = new double [n-1];

	cout << "Enter the elements of \"a\" array" << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}


	cout << "Enter the elements of \"b\" array" << endl;
	for (int i = 0; i < n-1; ++i)
	{
		cin >> b[i];
	}


	cout << "Enter the elements of \"c\" array" << endl;
	for (int i = 0; i < n-1; ++i)
	{
		cin >> c[i];
	}


	cout << "Enter the elements of \"q\"  RHS array" << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> q[i];
	}

	Thomas_AlgorithmLU(a, b, c, l, u, d, n);
	Thomas_Algorithm_Solve(q, l, u, d, x, n);

	Matrix_L(l, n);
	Matrix_U(d, u, n);


	cout << "The solution for the system is " << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << x[i] << endl;;
	}


	return 0;
}