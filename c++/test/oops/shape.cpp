#include <iostream>
using namespace std;


class Shape
{
	protected:
		double width;
		double height;
	
	public:
		void set_data(double x, double y)
		{
			width = x;
			height = y;
		}
};

class Rectangle : public Shape
{
	public:
		double area()
		{
			return width*height;
		}
};

class Triangle : public Shape
{
	public:
		double area()
		{
			return 0.5*width*height;
		}
};

int main()
{
	Rectangle rect;
	rect.set_data(4,5);
	cout << "Area of rectangle is" << rect.area() << endl;
	Triangle tri;
	tri.set_data(3,2);
	cout << "Area of triangle is" << tri.area() << endl;
}
	
