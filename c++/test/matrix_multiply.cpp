#include <iostream>
#include "other.h"
using namespace std;


void multiply(int **A,  int **B, int **C, int m1, int n2, int n1)
{
	for (int i = 0; i < m1; ++i)
	{
		for (int j = 0; j < n2; j++)
		{
			for (int k = 0; k < n1; k++)
			{
				C[i][j] = C[i][j] + A[i][k]*B[k][j];
			}
		}
	}
}

int main(){
	int m1, n1, m2, n2;
	cout << "Enter the size of matrix A" << endl;
	cin >> m1 >> n1;
	cout << "Enter the size of matrix B" << endl;
	cin >> m2 >> n2;
	if(n1 != m2)
	{
		cout << "Cannot multiply matrices, wrong dimension" << endl;
		return 0;
	}
	int **A, **B, **C;

	A = new int *[m1];
	for (int i=0; i < m1; i++)
	{
		A[i] = new int[n1];
	}

	B = new int *[m2];
	for (int i = 0; i < m2; i++)
	{
		B[i] = new int[n2];
	}

	C = new int *[m1];
	for (int i=0; i < m1; i++)
	{
		C[i] = new int[n2];
	}

	cout << "Enter the elements of matrix A" << endl;
	scan_matrix(A, m1, n1);
	cout << "Enter the elements of matrix B" << endl;
	scan_matrix(B, m2, n2);
	initialize_matrix(C, m1, n2);
	multiply(A, B, C, m1, n2, n1);
	print_matrix(C, m1, n2);
	return 0;
}