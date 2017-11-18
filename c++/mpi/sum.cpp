#include <iostream>
#include <mpi.h>
#define _BSD_SOURCE
#include <sys/time.h>
#include <time.h>
using namespace std;

const int N = 100000;

int main (int argc, char **argv){
	int mynode, totalnodes;
	int startval, endval;
	
	struct timeval start, end;
	double start_time, end_time;
	
	MPI_Status status;
	
	gettimeofday(&start, NULL);
	//start_time=MPI_Wtime();  
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &totalnodes);  // get totalnodes
	MPI_Comm_rank(MPI_COMM_WORLD, &mynode);  // get node
	
	int sum = 0;
	int sum_receive;
	startval = N*mynode/totalnodes+1;
	endval = N*(mynode+1)/totalnodes;
	
	for (int i=startval; i<=endval; ++i)
	{
		sum = sum + i;
	}
	
	if (mynode!=0)
	{
		MPI_Send(&sum, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
	}
	
	if(mynode == 0)
	{
		for (int i=1; i <totalnodes; ++i)
		{
			MPI_Recv(&sum_receive, 1, MPI_INT, i, 1, MPI_COMM_WORLD, &status);
			sum = sum + sum_receive;
		}
		cout << "The sum is " << sum << endl;
	}
	
	gettimeofday(&end, NULL);
    
    double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
             end.tv_usec - start.tv_usec) / 1.e6;
    cout << "time taken = " << delta << "seconds" << endl;
	//end_time = MPI_Wtime();
	
	// cout << "The time taken is " << end_time - start_time << endl;
	
	MPI_Finalize();
	return 0;
}
