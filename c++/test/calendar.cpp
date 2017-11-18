#include <iostream>
using namespace std;


void print_calendar(int days[5][7]){
	char week_letter[] = {'M', 'T', 'W', 'T', 'F', 'S', 'S'};
	for (int i = 0; i < 7; i++)
	{
		cout << week_letter[i] << '\t';
	}
	cout << '\n';
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if(days[i][j] > 0)
			{
				cout << days[i][j] << '\t';
			}
			else
			{
				cout << ' ' << '\t';
			}
		}
		cout << '\n' ;
	}
}

int main(){
	int n, n1;
	int days[5][7] = {};
	int day_no = 1;
	
	cout << "Enter the first day of the month (0:Monday..6:Sunday) and the number of days";
	cin >> n1 >> n;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			days[i][j] = day_no - n1;
			day_no = day_no + 1;
			if(day_no > n+n1)
			{
				break;
			}
		}
	}
	print_calendar(days);
	return 0;
}


