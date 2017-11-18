#include <iostream>
#define _BSD_SOURCE
#include <sys/time.h>
#include <time.h>
#include <omp.h>
using namespace std;


int main(){
    // clock_t t;
    struct timeval start, end;
    
    double *a;
    int n = 10000000;
    a = new double [n];
    // t = clock();
    gettimeofday(&start, NULL);
    #pragma omp parallel for
    for (int i=0; i<n; ++i)
    {
        a[i] = 1.0*2;
    }
    // t = clock() - t;
    // double seconds = t*0.001;
    gettimeofday(&end, NULL);
    
    double delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
             end.tv_usec - start.tv_usec) / 1.e6;
    cout << "time taken = " << delta << "seconds" << endl;
    // for (int i=0; i<n; ++i)
    // {
    //     cout << a[i] << endl;
    // }
}


// struct timeval start, end;
// gettimeofday(&start, NULL);

// // benchmark code

// gettimeofday(&end, NULL);

// delta = ((end.tv_sec  - start.tv_sec) * 1000000u + 
//          end.tv_usec - start.tv_usec) / 1.e6;