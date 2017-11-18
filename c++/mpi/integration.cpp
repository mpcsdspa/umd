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


double trapezoidal(double *x, double min, double h, double start, double end)
{
	double sum = 0.0;

	for(int i = start; i<=end; ++i)
	{
		x[i] = min + i*h;
	}

	for (int i=start; i<end; ++i)
	{
		sum = sum + h*f(x[i]);
	}
	return sum;
}


int main (int argc, char **argv){


	double min = 0.0;
	double max = 1.0;
	int N = 1000;
	double *x = new double [N+1];
	double h = (max - min)/N;
	int totalnodes, mynode;
	double value_recv, answer;
	
	MPI_Status status;
	

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &totalnodes);  // get totalnodes
	MPI_Comm_rank(MPI_COMM_WORLD, &mynode);  // get node
	
	int start_val = N*mynode/totalnodes;
	int end_val = N*(mynode+1)/totalnodes;

	double value = trapezoidal(x,min,h, start_val, end_val);
	
	MPI_Reduce(&value, &answer, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	// if (mynode!=0)
	// {
	// 	MPI_Send(&value, 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD);
	// }
	
	// if(mynode == 0)
	// {
	// 	for (int i=1; i <totalnodes; ++i)
	// 	{
	// 		MPI_Recv(&value_recv, 1, MPI_DOUBLE, i, 1, MPI_COMM_WORLD, &status);
	// 		value = value + value_recv;
	// 	}
	// 	value = value + 0.5*h*(-f(min) + f(max));
	// 	cout << "The sum is " << value << endl;
	// }

	if (mynode == 0)
	{
		answer = answer + 0.5*h*(-f(min) + f(max));
		cout << " The value of integral is " << answer << endl;
	}
	
	MPI_Finalize();
	return 0;
}

