#include <iostream>
#include <omp.h>
#define _BSD_SOURCE
#include <sys/time.h>
#include <time.h>
using namespace std;

void discretize_x(double *x, double min, double max, int N)
{
	double h = (max - min)/N;
	#pragma omp parallel for
	for(int i =0; i<=N; ++i)
	{
		x[i] = min + i*h;
	}
}

double f(double x)
{
	return 1.0/(1+x);
}


double rectangle(double *x, double min, double max, int N)
{
	double sum = 0.0;
	double h = (max - min)/N;
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
	for (int i=1; i<N; ++i)
	{
		sum = sum + (h/6)*(2*f(x[i]) + 4*f(0.5*(x[i] + x[i-1])));
	}
	sum = sum + 4*h*f(0.5*(x[N] + x[N-1]))/6;
	sum = sum + h*(f(min) + f(max))/6;

	return sum;
}


int main()
{
	struct timeval start, end;
	
	
	double min, max;
	cout << "Enter the limits of the interval " << endl;
	cin >> min >> max;
	int N;
	cout << "Enter the number of segments " << endl;
	cin >> N;
	double *x = new double [N+1];
	discretize_x(x, min, max, N);
	double integral;
	//integral = rectangle(x, min, max, N);
	
	gettimeofday(&start, NULL);
	
	double integral_t = trapezoidal(x, min, max, N);
	// double integral_s = simpson(x, min, max, N);
	// cout << "The value of the integral obtained from rectangle midpoint rule is " << integral << endl;
	
	
	cout << "The value of the integral obtained from Trapezoidal rule is " << integral_t << endl;
	gettimeofday(&end, NULL);
    
    double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
             end.tv_usec - start.tv_usec) / 1.e6;
    cout << "time taken = " << delta << "seconds" << endl;
    
    
	// cout << "The value of the integral obtained from Simpson rule is " << integral_s << endl;
	return 0;
}
	
	
