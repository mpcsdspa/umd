#include <iostream>
using namespace std;


int factorial(int n);


int main(){
	int n;
	unsigned int fac;
	cout << "Enter the number:";
	cin >> n;
	fac = factorial(n);
	cout << "The factorial is " << fac ;
	return 0;
}


int factorial(int n){
	unsigned int fac;
	if (n == 0 or n == 1)
	{
		fac = 1;
	}
	else
	{
		fac = n * factorial(n-1);
	}
	return fac;
}

