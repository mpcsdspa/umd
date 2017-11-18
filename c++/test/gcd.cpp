#include <iostream>
using namespace std;


int gcd(int small, int big){
	while(big % small != 0) {
	    int rem = big % small;
	    big = small;
	    small = rem;
	}
	return small;
}

int main(){
	int a, b;
	cout << "Enter two numbers with lowest as first" << endl;
	cin >> a >> b;
	cout << "GCD of the given numbers is" << gcd(a,b) << endl;
}


