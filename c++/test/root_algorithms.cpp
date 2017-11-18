#include <iostream>
using namespace std;
#include <math.h>


double fun(double x)
{
	return x*x - 5*x + 6;
}

double fun_der(double x)
{
	return 2*x - 5;
}

double func(double x) // used only for Fixed Point Iteration as function has to be SELF MAPPED.
{
	return 0.5*(x + 3/x);
}


double Newton_Raphson(double x0, int max_iter, double tolerance, int p) // p stands for multiplicity
{
	double x;
	for (int i = 0; i < max_iter; ++i)
	{
		x = x0 - p*fun(x0)/fun_der(x0);
		if(fabs(x - x0) < tolerance) break;
		x0 = x;
	}
	return x;
}

double Fixed_point(double x0, int max_iter, double tolerance)
{
	double x;
	for (int i = 0; i < max_iter; ++i)
	{
		x = func(x0);
		if(fabs(x - x0) < tolerance) break;
		x0 = x;
	}
	return x;
}


double Secant(double a, double b, int max_iter, double tolerance)
{
	double x;
	for (int i = 0; i < max_iter; ++i)
	{
		x = a - fun(a)*(b - a)/(fun(b) - fun(a));
		if(fabs(fun(x)) < tolerance) break;
		a = x;
	}
	return x;
}

double Bisection(double a, double b, int max_iter, double tolerance)
{
	double mid;
	for (int i=0; i< max_iter; ++i)
	{
		if (fun(a) * fun(b) < 0)
		{
			mid = 0.5*(a + b);
			if (fun(mid)*fun(a) < 0)
			{
				b = mid;
			}
			if (fun(mid)*fun(b) < 0)
			{
				a = mid;
			}
			if (fabs(fun(mid)) < tolerance)
			{
				break;
			}
		}	
	}

return mid;
}

int main()
{
	double root;
	//root = Fixed_point(1.0, 100, 1e-6);
	root = Secant(1.5, 2.75, 10, 1e-6);
	cout << root << fun(root) << endl;
	return 0;	
}


