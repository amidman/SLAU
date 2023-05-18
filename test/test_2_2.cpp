#include"../src/MPI.h"
#include"../src/Gradient_descent.h"
#include<iostream>

double f(std::vector<double> x, CSR<double> matrix, std::vector<double> b,double c){
    int n = x.size();
    std::vector<double> Ax = matrix*x;
    double a = 0;
    for(int i=0;i<n;++i){
        a+=Ax[i]*x[i];
    }
    double btx = 0;
    for(int i=0;i<n;++i){
        btx+=b[i]*x[i];
    }

    return 0.5*a-btx+c;
}


int main(){
    std::vector<double> values{10,11,13,15};
    std::vector<int> cols{0,1,2,3};
    std::vector<int> rows{0,1,2,3,4};

    CSR<double> matrix = CSR<double>(values,cols,rows);

    std::vector<double> b{4,4,4,4};
    std::vector<double> x_mpi;
    std::vector<double> x_opt;
    std::vector<double> x_gd;
    double c = 2;
    double tolerance = 0.0000000000001;
    double tau = 0.9*2/15;
    double tau_opt = 2.0/(10+15);
    std::cout<<"MPI:";
    x_mpi = MPI(matrix,b,tau,tolerance);
    std::cout<<"MPI opt:";
    x_opt = MPI(matrix,b,tau_opt,tolerance);
    std::cout<<"GD fast:";
    x_gd = Gradient_descent_fast(matrix,b,tolerance);


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
    std::cout<<"X gradient descent fast:";
    for(int i=0;i<4;i++){
        std::cout<<x_gd[i]<<" ";
    }
    std::cout<<std::endl;

    std::cout<<f(x_mpi,matrix,b,c)<<" "<<f(x_opt,matrix,b,c)<<" "<<f(x_gd,matrix,b,c)<<" "<<std::endl;

    return 0;
}

//f min = -0.67

/*
MPI:
0.48 0.48
0.384 0.096
0.4032 0.4032
0.39936 0.15744
0.400128 0.354048
0.399974 0.196762
0.400005 0.322591
0.399999 0.221927
0.4 0.302458
0.4 0.238034
0.4 0.289573
0.4 0.248341
0.4 0.281327
0.4 0.254939
0.4 0.276049
0.4 0.259161
0.4 0.272671
0.4 0.261863
0.4 0.27051
0.4 0.263592
0.4 0.269126
*/

/*
MPI opt:
0.32 0.32
0.384 0.256
0.3968 0.2688
0.39936 0.26624
0.399872 0.266752
0.399974 0.26665
0.399995 0.26667
0.399999 0.266666
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667*/

/*
GD fast:
0.326531 0.326531
0.384001 0.256289
0.396962 0.268899
0.399352 0.266265
0.399878 0.266755
0.399974 0.266651
0.399995 0.26667
0.399999 0.266666
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667
0.4 0.266667*/