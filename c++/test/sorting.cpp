#include <iostream>
#include "other.h"
using namespace std;


void insertion_sort(int* a, int n){
	for (int i = 1; i < n; ++i)
	{
		for (int j = i-1; j >= 0; j--)
		{
			if(a[j+1] < a[j]){swap(&a[j+1], &a[j]);}
		}
	}
}


void bubble_sort(int* a, int n){
	for (int i = 0; i < n-1; ++i)
	{
		for(int j = 0; j < n-1; j++)
		{
			if(a[j+1] < a[j]){swap(a[j], a[j+1]);}
		}
	}
}


void selection_sort(int* a, int n){
	for (int i = 0; i < n-1; ++i)
	{
		int lowindex = i;
		for(int j = i; j < n; ++j)
		{

			if(a[j] < a[lowindex]){lowindex = j;}
		}
		swap(&a[i], &a[lowindex]);
	}
}

int main(){
	int n;
	cout <<"Enter the number of items"<< endl;
	cin >> n;
	int a[n];
	cout << "Enter the numbers to be sorted" << endl;
	scan_data(a, n);
	selection_sort(a, n);
	print_data(a, n);
	cout << endl;
}