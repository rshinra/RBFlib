using namespace std;
#include <iostream>
#include <stdlib.h>
#include "RBF.h"


void main(){
  class RBF1DN U;
  U.new_basis(2,1,0,0);
  U.new_basis(1,1,0,0);
  cout << U.rbf(1.0,0) << endl;
  cout << U.rbf(0.0,1) << endl;
  cout << U.u(0.0) << endl;
  U.print_net();
}