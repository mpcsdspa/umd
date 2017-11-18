#include <iostream>
using namespace std;
#include <vector>



int main(){
	vector<int> v(10);
	for(int i=0; i<10; ++i)
	{
		v[i] = i;
	}
	for(int i=0; i<10; ++i)
	{
		cout << v[i];
	}
}
