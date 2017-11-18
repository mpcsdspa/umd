#include <iostream>
using namespace std;


int dot_product(double *x, double *y)
{
	int a = 0;
	for (int i = 0; i<3; ++i)
	{
		a = a + x[i]*y[i];
	}
	return a;
}

int main()
{
	double A[3][3];
	for (int i = 0; i<3; ++i)
	{
		for (int j = 0; j<3; ++j)
		{
			A[i][j] = i + j;
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j =0; j < 3; j++)
		{
			cout << A[i][j] << '\t';
		}
		cout << endl;
	}
	int a = dot_product(A[1], A[1]);
	cout << a;
	// cout << A[1][0] << endl;
}
