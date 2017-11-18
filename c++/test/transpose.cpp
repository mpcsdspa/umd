#include <iostream>
#include <string>
#include "other.h"
using namespace std;


void transpose(int **a, int m, int n){
	for (int i = 0; i < m; ++i)
	{
		for (int j = i; j < n; j ++)
		{
			swap(a[i][j], a[j][i]);
		}
	}
}

int main()
{
	int **a;
	int m, n;
	cout << "Enter the size of the matrix" << endl;
	cin >> m >> n;
	a = new int*[m];
	for (int i = 0; i<m; i++)
	{
		a[i] = new int[n];
	}
	cout << "Enter the numbers of the matrix" << endl;
	scan_matrix(a,m,n);
	transpose(a, m, n);
	print_matrix(a,m,n);
}
