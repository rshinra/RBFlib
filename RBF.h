using namespace std;
#include <iostream>
#include <stdlib.h>
#include <math.h>


class RBF1DN{
  public :
    // Members
    struct RBF1D{
      double A = 0;  // Height
      double B = 0;  // Width
      double C = 0;  // Center
      double D = 0;  // Skew
    };
    
    struct RBF1D *Network[10000] = {NULL};     // Network holds all the radial basis functions.    
    double *prnt[10002] = {NULL};              // prnt holds pointers to depth-length vectors of x, u, and any rbs
    char prnth[10002][6];                      // printh holds a 6 character header  for the prnt vectors
    int depth = 0;                             // depth of print array - used to see if x vector is defined, 
    
    // Methods
    void new_basis(float A, float B, float C, float D){  // create a new radial basis function, and store it in the next pointer
      int i;
      for(i  = 0; i < 10000 && Network[i] != NULL; i++);
      if(i == 10000)
        exit(2); // Make exit status 2 "Out of New Basis Functions
      Network[i] = (struct RBF1D *) malloc( sizeof(struct RBF1D));
      (*Network)[i].A = A;
      (*Network)[i].B = B;
      (*Network)[i].C = C;
      (*Network)[i].D = D;
    };
    
    // plot x should be set one time  think about reset
    void set_plot_x(double start, double end, double interval){
      int i;
      double *ptr;
      if(depth)
        cout << endl << "PRINT ARRAY HAS BEEN SET" << endl;
      else{
        depth = ceil((end - start) / interval) + 1;
        strcpy(prnth[1],"x");
      }
      ptr = (double *) malloc(sizeof(double) * depth);
      for(i = 1; i < depth; i++)
        ptr[i] = start + i * interval;
      ptr[i] = end;
      prnt[0] = ptr;
    };
    void set_plot_x(double start, double end, int intervals){
      double Ntrvl = (end - start)/intervals;
      set_plot_x(start,end,Ntrvl);
    };
    
    void plot_rbf(int w){
      // flag if 0 has been used
      // make check for existing w if not 0
      // check for depth first. if not defined, error.
      //if (w > 0)
        
    };
    
    void plot_u(void){
      // Ensure that u is the second pointer
      // check if u's been calculated (maybe not for updates
    };
    
    double u(double x){
      int i;
      double tot = 0.;
      for(i=0;i<10000 && Network[i];i++)
      {
        tot += rbf(x,i);
      }
      return(tot);
    };
    double rbf(double x, int w){
      // calculate single rbf at specific x =
      double A = (* Network)[w].A;
      double B = (* Network[w]).B;
      double X = x - (* Network[w]).C;
      double D = (* Network[w]).D;
      if(Network[w]){
        if(fabs(D) < .01)
          return(A * exp(- pow(B*X,2)));
        else
          return(A * exp(- pow(B*X,2)) * .5 * ( tanh(D * (X)) + 1 ));
      }else{
        cout << "RBF " << w << " Has not been initialized" << endl;
        return(-99999.00);
      }
    };
    double rbf(int w, double x){
      return(rbf(x,w));
    };
    
    
    void print_net(){
      int i=0;
      while(Network[i] && i < 10000){
        cout << endl << "Radial Basis Function: " << i << endl;
        cout << "A: " << (*Network)[i].A << endl << "B: " << (*Network)[i].B << endl << "C: " << (*Network)[i].C << endl << "D: " << (*Network)[i].D << endl;
        i++;
      }
    }
 };

class RBF2DN{
  struct RBF2D{
    double A = 0;  // Height
    double B = 0;  // Width
    double Cx = 0; // Center - x
    double Cy = 0; // Center - y
    double D = 0;  // Skew
  };
  
  struct RBF2D *Network[10000] = {NULL};
    
    // Methods
    int new_basis(float A, float B, float Cx, float Cy, float D){
      int i;
      for(i  = 0; i < 10000 && Network[i] != NULL; i++);
      if(i == 10000)
        return(0);//exit(2); // Make exit status 2 "Out of New Basis Functions
      Network[i] = (struct RBF2D *) malloc( sizeof(struct RBF2D));
      (*Network)[i].A = A;
      (*Network)[i].B = B;
      (*Network)[i].Cx = Cx;
      (*Network)[i].Cy = Cy;
      (*Network)[i].D = D;
    };
    
    void print_net(int w){
      cout << endl << "Radial Basis Function: " << w << endl;
      cout << (*Network)[w].A << (*Network)[w].B << (*Network)[w].Cx << (*Network)[w].Cy << (*Network)[w].D << endl;
    }
};

class  RBF3DN{
  struct RBF3D{
    double A = 0;  // Height
    double B = 0;  // Width
    double Cx = 0;  // Center
    double Cy = 0;  // Center
    double Cz = 0;  // Center
    double D = 0;  // Skew
  };

    struct RBF3D *Network[10000] = {NULL};
    
    // Methods
    int new_basis(float A, float B, float Cx, float Cy, float Cz, float D){
      int i;
      for(i  = 0; i < 10000 && Network[i] != NULL; i++);
      if(i == 10000)
        return(0);//exit(2); // Make exit status 2 "Out of New Basis Functions
      Network[i] = (struct RBF3D *) malloc( sizeof(struct RBF3D));
      (*Network)[i].A = A;
      (*Network)[i].B = B;
      (*Network)[i].Cx = Cx;
      (*Network)[i].Cy = Cy;
      (*Network)[i].Cz = Cz;
      (*Network)[i].D = D;
    };
    
    void print_net(int w){
      cout << endl << "Radial Basis Function: " << w << endl;
      cout << (*Network)[w].A << (*Network)[w].B << (*Network)[w].Cx << (*Network)[w].Cy << (*Network)[w].Cz << (*Network)[w].D << endl;
    }
  };