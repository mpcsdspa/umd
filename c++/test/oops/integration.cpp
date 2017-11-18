#include <iostream>
#include <omp.h>
using namespace std;

double f(double x);

class Integration
{
	protected:
		double min;
		double max;
		double *x;
		int N;
	public:
		void set_value(double a, double b, int N)
		{
			min = min;
			max = max;
			N = N;
		}
		
		void discretize_x(double *x, double min, double max, int N)
		{
			double h = (max - min)/N;
			#pragma omp parallel for
			for(int i =0; i<=N; ++i)
			{
				x[i] = min + i*h;
			}
		}

		double rectangle(double *x, double min, double max, int N)
		{
			double sum = 0.0;
	        double h = (max - min)/N;
	        #pragma omp parallel for reduction(+:sum)
			for (int i=0; i<N; ++i)
		{
			sum = sum + h*f(0.5*(x[i]+x[i+1]));
		}
			return sum;
		}

		double trapezoidal(double *x, double min, double max, int N)
		{
			double sum = 0.0;
			double h = (max - min)/N;
			int i;
			#pragma omp parallel for reduction(+:sum)
			for (i=1; i<N; ++i)
			{
				sum = sum + h*f(x[i]);
			}
			sum = sum + 0.5*h*(f(min) + f(max));
			return sum;
		}


		double simpson(double *x, double min, double max, int N)
		{
			double sum = 0.0;
			double h = (max - min)/N;
			#pragma omp parallel for reduction(+:sum)
			for (int i=1; i<N; ++i)
			{
				sum = sum + (h/6)*(2*f(x[i]) + 4*f(0.5*(x[i] + x[i-1])));
			}
			sum = sum + 4*h*f(0.5*(x[N] + x[N-1]))/6;
			sum = sum + h*(f(min) + f(max))/6;

			return sum;
		}

};


double f(double x)
{
	return 1.0/(1+x);
}


int main()
{
	Integration integral;
	double min, max;
	int N;
	cout << "Enter the limits of the interval " << endl;
	cin >> min >> max;
	cout << "Enter the number of segments " << endl;
	cin >> N;
	double *x = new double [N+1];
	integral.set_value(min, max, N);
	integral.discretize_x(x,min, max, N);
	cout << integral.rectangle(x, min, max, N) << endl;
	cout << integral.trapezoidal(x, min, max, N) << endl;
	cout << integral.simpson(x, min, max, N) << endl;
	return 0;
}


