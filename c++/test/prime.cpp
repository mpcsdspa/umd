#include <iostream>
using namespace std;

bool check_prime(int n);


int main(){
	int n;
	cout << "Enter a number:";
	cin >> n;
	bool result = check_prime(n);
	if (result == true)
	{
		cout << "The given number" << n << "is prime";
	}
	else
	{
		cout << "The given number " << n << " is not prime";
	}
	return 0;
}
	

bool check_prime(int n){
	bool ans = true;
	for (int i = 2; i < n; i++)
	{
		cout << i;
		float a = n % i;
		if (a == 0)
		{
			ans = false;
			break;
		}
	}
	return ans;
}


