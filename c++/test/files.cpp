#include <iostream>
using namespace std;
#include <fstream>

/*
int main(){
	fstream file;
	file.open("file1.txt", ios::out);
	cout << "File created" ;
	file.close();
	return 0;
}
*/

/*
int main(){
	char c;
	fstream file;
	file.open("file1.txt", ios::in);
	if(!file)
	{
		cout << "File not found" ;
	}
	while(!file.eof())
	{
		file >> noskipws >> c;   // noskipws makes sure lines are read separately
		cout << c;
	}
	return 0;
}
*/

/*
int main(){
	char c;
	fstream file;
	file.open("file1.txt", ios::app);
	file << "How are you mrinal?";
	file.close();
	file.open("file1.txt", ios::out|ios::in);
	while(!file.eof())
	{
		file >> c;
		cout << c;
	}
	file.close();
	return 0;
}
*/


int main(){
	char c;
	fstream file;
	int age;
	char name[20];
	cout << "Enter your name";
	cin.getline(name, 20);
	cout << "Enter age";
	cin >> age;
	file.open("file1.txt", ios::out);
	file << name << endl;
	file << age << endl;
	file.close();
	age = 21;
	file.open("file1.txt", ios::in);
	file >> name;
	cout<<"Name: "<<name<<",Age:"<<age<<endl;
	file.close();
	return 0;
}