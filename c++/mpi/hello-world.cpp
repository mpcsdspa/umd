#include <iostream>
#include <mpi.h>
#define _BSD_SOURCE
#include <sys/time.h>
#include <time.h>
using namespace std;


int main(int argc, char **argv){
	struct timeval start, end;
	int mynode, totalnodes;
	gettimeofday(&start, NULL);
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &mynode);
	MPI_Comm_size(MPI_COMM_WORLD, &totalnodes);
	cout << "Hello World" << mynode << "of" << totalnodes << endl;
	gettimeofday(&end, NULL);
    
    double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
             end.tv_usec - start.tv_usec) / 1.e6;
    cout << "time taken = " << delta << "seconds" << endl;
	MPI_Finalize();
}

