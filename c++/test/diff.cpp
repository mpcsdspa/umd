#include <iostream>
#define _BSD_SOURCE
#include <sys/time.h>
#include <time.h>
using namespace std;

const double a = 0.0;
const double b = 1.0;

double func(double x)
{
	return (x*x*x);
}

void SecondDeriv_1D(double *u, double *u_xx, int n, double dx)
{
	double inv_dx2 = 1.0/(dx*dx);

	u_xx[0] = (2*u[0] - 5*u[1] + 4*u[2] - u[3])*inv_dx2;

	for (int i = 1; i < n-1; ++i)
	{
		u_xx[i] = (u[i+1] - 2*u[i] + u[i-1])*inv_dx2;
	}

	u_xx[n-1] = (2*u[n-1] - 5*u[n-2] + 4*u[n-3] - u[n-4])*inv_dx2;
}

void SecondDeriv_1Dper(double *u, double *u_xx, int n, double dx)
{
	double inv_dx2 = 1.0/(dx*dx);

	u_xx[0] = (u[1] - 2*u[0] + u[n-1])*inv_dx2;

	for (int i = 1; i < n-1; ++i)
	{
		u_xx[i] = (u[i+1] - 2*u[i] + u[i-1])*inv_dx2;
	}

	u_xx[n-1] = (u[0] - 2*u[n-1] + u[n-2])*inv_dx2;
}

void FirstDeriv_1D(double *u, double *u_x, int n, double dx)
{
	double two_invdx = 1.0/(2*dx);

	u_x[0] = (-3*u[0] +4*u[1] - u[2])*two_invdx;

	for (int i = 1; i < n-1; ++i)
	{
		u_x[i] = (u[i+1] - u[i-1])*two_invdx;
	}

	u_x[n-1] = (3*u[n-1] - 4*u[n-2] + u[n-3])*two_invdx;
}

void FirstDeriv_1Dper(double *u, double *u_x, int n, double dx)
{
	double two_invdx = 1.0/(2*dx);

	u_x[0] = (u[1] - u[n-1])*two_invdx;

	for (int i = 1; i < n-1; ++i)
	{
		u_x[i] = (u[i+1] - u[i-1])*two_invdx;
	}

	u_x[n-1] = (u[0] - u[n-2])*two_invdx;
}

int main()
{
	struct timeval start, end;

	int n;
	cout << "Enter the number of points" << endl;
	cin >> n;
	double *u, *u_x, *u_xx;
	u = new double [n];
	u_x = new double [n];
	u_xx = new double [n];
	// x = new double [n];

	gettimeofday(&start, NULL);

	double dx = (b - a)/n;
	for (int i = 0; i<n; ++i)
	{
		// x[i] = i*dx;
		u[i] = func(i*dx);
	}
	SecondDeriv_1D(u, u_xx, n, dx);
	// for (int i = 0; i<n; ++i)
	// {
	// 	cout << u_xx[i] << endl;
	// }
	FirstDeriv_1D(u, u_x, n, dx);

	gettimeofday(&end, NULL);
    
    double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
             end.tv_usec - start.tv_usec) / 1.e6;
    cout << "time taken = " << delta << "seconds" << endl;
	// for (int i = 0; i<n; ++i)
	// {
	// 	cout << u_x[i] << endl;
	// }
}