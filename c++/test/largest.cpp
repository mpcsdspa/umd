#include <iostream>
using namespace std;


// function declaration
void print_data(int a[], int n);
void initialize_array(int a[], int n);
void scan_data(int* a, int n);

int main(){
	int a[5];
	int n = sizeof(a)/ sizeof(a[0]);
	initialize_array(a, n);
	cout << "Enter 5 integers \n";
	scan_data(a, n);
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j < 5; j++)
		{
			if (a[i] < a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	print_data(a, n);
}


void scan_data(int* a, int n){
	for (int i=0; i<n; i++)
	{
		cin >> a[i];
	}
}

void print_data(int a[], int n){
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << '\t';
	}
}

void initialize_array(int a[], int n){
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
}
