#include <iostream>
#include <string>
using namespace std;

class Animal
{
	protected:
		string name;
		int age;
	
	public:
		void set_value(string c, int n)
		{
			age = n;
			name = c;
		}
};

class Zebra : public Animal
{
	public:
		void display()
		{
			cout << " Zebra ka Naam " << name << " Zebra ka umar" << age << endl;
		}
};

class Dolphin : public Animal
{
	public:
		void display()
		{
			cout << " Dolphin ka Naam " << name << " Zebra ka umar" << age << endl;
		}
};


int main()
{
	Zebra zeb;
	zeb.set_value("Mrinal", 23);
	zeb.display();
	Dolphin dol;
	dol.set_value("Mihir", 18);
	dol.display();
	return 0;
}
