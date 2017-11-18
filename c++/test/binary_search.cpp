#include <iostream>
#include "other.h"
using namespace std;


int binary_search(int* a, int n, int x){
	int low = 0;
	int high = n-1;
	while(high > low){
		int mid = (low + high)*0.5;
		if(a[mid] >= x)
		{
			high = mid;
		}
		else
		{
			low = mid+1;
		}
	}
	if(a[low] == x)
	{
		return low;
	}
	else
	{
		return -1;
	}
}

int main(){
	int a[10], n;
	cout << "Enter the number of integers you are inputting" << endl;
	cin >> n;
	cout << "Enter an array" << endl;
	scan_data(a, n);
	cout << "Enter the number you want to search in the array" << endl;
	int x;
	cin >> x;
	int loc;
	loc = binary_search(a, n, x);
	cout << "The position of the number is" << (loc);
}



