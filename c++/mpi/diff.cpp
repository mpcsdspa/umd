#include <iostream>
#include <mpi.h>
using namespace std;

const double a = 0.0;
const double b = 1.0;


double func(double x)
{
	return (x*x*x);
}


void SO_FirstDeriv_1D(double *u, double *u_x, int mynode, int totalnodes, int n, double dx)
{
	double two_invdx = 1.0/(2.0*dx);
	double temp;
	MPI_Status status;
	
	if(mynode == 0)
	{
		u_x[0]= (-3*u[0] + 4*u[1] - u[2])*two_invdx;
	}
	
	if (mynode == totalnodes - 1)
	{
		u_x[n-1] = (3*u[n-1] -4*u[n-2] + u[n-3])*two_invdx;
	}
	
	for (int i = 1; i < n-1; ++i)
	{
		u_x[i] = (u[i+1] - u[i-1])*two_invdx;
	}
	
	if(mynode == 0)
	{
		temp = u[n-1];
		MPI_Send(&temp, 1, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD);
		MPI_Recv(&temp, 1, MPI_DOUBLE, 1, 1, MPI_COMM_WORLD, &status);
		u_x[n-1] = (temp - u[n-2])*two_invdx;
	}
	else if (mynode == totalnodes - 1)
	{
		MPI_Recv(&temp, 1, MPI_DOUBLE, mynode-1, 1, MPI_COMM_WORLD, &status);
		u_x[0] = (u[1] - temp)*two_invdx; 
		temp = u[0];
		MPI_Send(&temp, 1, MPI_DOUBLE, mynode-1, 1, MPI_COMM_WORLD);
		
	}
	else
	{
		MPI_Recv(&temp, 1, MPI_DOUBLE, mynode-1, 1, MPI_COMM_WORLD, &status);
		u_x[0] = (u[1] - temp)*two_invdx;
		temp = u[0];
		MPI_Send(&temp, 1, MPI_DOUBLE, mynode-1, 1, MPI_COMM_WORLD);
		
		temp = u[n-1];
		MPI_Send(&temp, 1, MPI_DOUBLE, mynode+1, 1, MPI_COMM_WORLD);
		MPI_Recv(&temp, 1, MPI_DOUBLE, mynode+1, 1, MPI_COMM_WORLD, &status);
		u_x[n-1] = (temp - u[n-2])*two_invdx;
	}
}

int main(int argc, char **argv)
{
	double *u, *u_x, dx, two_invdx;
	int mynode, totalnodes;
	int n = 20; // total number of elements
	
	MPI_Status status;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &totalnodes);  // get totalnodes
	MPI_Comm_rank(MPI_COMM_WORLD, &mynode);  // get node
	
	//cout << totalnodes ;
	int np = 5;
	u = new double [np];
	u_x = new double [n];
	
	dx = (b - a)/(np*totalnodes);
	int start_val = n*mynode/totalnodes;
	int end_val = n*(mynode+1)/totalnodes;
	
	for (int i = 0; i<np; ++i)
	{
		u[i] = func((i+start_val)*dx);
		u_x[i] = 0.0;
	}

	SO_FirstDeriv_1D(u, u_x, mynode, totalnodes, n, dx);

	for (int i = 0; i<np; ++i)
	{
		if (mynode == 2)
		cout << u_x[i] << endl;
	}
	
	MPI_Finalize();
	
	return 0;
}
	
