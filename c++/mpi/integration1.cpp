#include <iostream>
#include <mpi.h>
#define _BSD_SOURCE
#include <sys/time.h>
#include <time.h>
using namespace std;



double f(double x)
{
	return 1.0/(1+x);
}


double trapezoidal(int start_val, int end_val, double *x, double h, double min)
{
	for(int i = start_val; i<=end_val; ++i)
	{
		x[i] = min + i*h;
	}

	double value = 0.0;
	for (int i=start_val; i<end_val; ++i)
	{
		value = value + h*f(x[i]);
	}
	return value;
}


int main (int argc, char **argv){


	double min = 0.0;
	double max = 1.0;
	int N = 100;
	double *x = new double [N+1];
	double h = (max - min)/N;
	int totalnodes, mynode;
	double value_recv;
	
	MPI_Status status;
	

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &totalnodes);  // get totalnodes
	MPI_Comm_rank(MPI_COMM_WORLD, &mynode);  // get node
	
	int start_val = N*mynode/totalnodes;
	int end_val = N*(mynode+1)/totalnodes;

	double value = trapezoidal(start_val, end_val, x, h, min);
	
	if (mynode!=0)
	{
		MPI_Send(&value, 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD);
	}
	
	if(mynode == 0)
	{
		for (int i=1; i <totalnodes; ++i)
		{
			MPI_Recv(&value_recv, 1, MPI_DOUBLE, i, 1, MPI_COMM_WORLD, &status);
			value = value + value_recv;
		}
		value = value + 0.5*h*(-f(min) + f(max));
		cout << "The sum is " << value << endl;
	}
	
	MPI_Finalize();
	return 0;
}
