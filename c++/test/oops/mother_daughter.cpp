#include <iostream>
using namespace std;

class Mother
{
	public:
		void display()
		{
			cout << "Mother is GOD" << endl;
		}
};

class Daughter : public Mother
{
	public:
		void display()
		{
			cout << "Daughter should be respected " << endl;
		}
};

int main()
{
	Daughter riya;
	riya.display();
	return 0;
}
