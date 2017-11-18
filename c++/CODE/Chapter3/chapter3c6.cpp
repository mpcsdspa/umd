
#include <iostream.h>
#include "SCchapter3.h"

double func(double x);

int main(int argc, char * argv[]){
  int i;
  int degree, polypnts;
  int npts = 1000;      //number of points used for plotting
  double xpt, soln, approx;
  LSPoly poly;

  cout << "Enter the degree of the least squares polynomial: ";
  cin >> degree;
  
  cout << "Enter the number of points to use for evaluation: ";
  cin >> polypnts;
  
  double * poly_xpts = new double[polypnts];
  double * func_vals = new double[polypnts];
 
  CreateGrid_EvenlySpaced(polypnts, poly_xpts, -1.0, 1.0);

  for(i=0;i<polypnts;i++){
    func_vals[i] = func(poly_xpts[i]);
  }

  poly.Initialize(polypnts,degree,poly_xpts,func_vals);
  
  for(i=0;i<npts;i++){
    xpt = -1.0 + 2.0*i/(npts-1);
    soln = func(xpt);
    approx =  poly.Evaluate(xpt);
    cout << xpt << " " << soln << " " << approx << endl;
  }

  delete[] poly_xpts;
  delete[] func_vals;
}

double func(double x){
  double y;
  
  y = 1.0 + 25.0*x*x;
  y = 1.0/y;
  
  return y;
}

