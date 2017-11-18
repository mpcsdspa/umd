
#include <iostream.h>

int main(int argc, char * argv[]){
  int i;
  double x[100];
  double dx = 1.0/99.0;

  for(i=0;i<100;i++)
    x[i] = i*dx;

  for(i=0;i<100;i++)
    cout << "x[" << i << "] = " << x[i] << endl;
}

