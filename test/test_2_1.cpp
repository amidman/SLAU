#include"../src/MPI.h"
#include"../src/Gauss_zedel.h"
#include"../src/Gradient_descent.h"
#include<cmath>
#include<iostream>


int main(){
    double A = 8;
    double B = 17;

    int n = 17;

    CSR<double> matrix = CSR<double>(n,A,B);

    std::vector<double> b(n*n,1);
    std::vector<double> x_mpi;
    std::vector<double> x_opt;
    std::vector<double> x_sym;

    double tolerance = 0.000000001;
    double tau = 0.5/(B+2*A*cos(3.1415/(n+1)));
    double tau_opt = 1.0/(B+2*A*cos(3.1415/(n+1))+B+2*A*cos(3.1415*n/(n+1)));
    std::cout<<"MPI:";
    x_mpi = MPI(matrix,b,tau,tolerance);
    std::cout<<"MPI opt:";
    x_opt = MPI(matrix,b,tau_opt,tolerance);
    std::cout<<"Zedel sym:";
    x_sym = Zedel_sym(matrix,b,tolerance);


    std::cout<<"X gradient descent (MPI):";
    for(int i=0;i<4;i++){
        std::cout<<x_mpi[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"X MPI opt:";
    for(int i=0;i<4;i++){
        std::cout<<x_opt[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"X Zedel sym:";
    for(int i=0;i<4;i++){
        std::cout<<x_sym[i]<<" ";
    }
    std::cout<<std::endl;

    return 0;
}