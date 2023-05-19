#pragma once

#include<vector>
#include<cmath>
#include"CSR.h"
#include"operators.h"
#include<iostream>

std::vector<double> MPI(CSR<double> matrix, std::vector<double> b, double tau, double tolerance){
    int n = b.size();
    std::vector<double> res(n);
    std::vector<double> dif(n);
    for(int i =0;i<n;++i){
        res[i] = 0;
    }
    do{
        dif = (matrix*res-b);
        res = res-dif*tau;

    std::cout<<res[0]<<" "<<res[3]<<std::endl;
	//std::cout<<norm(matrix*res-b)<<std::endl;
    
    }while(norm(dif) > tolerance);

    return res;
}

std::vector<double> calc_cheb_pol(double lmax, double lmin, int n){
    std::vector<double> cheb(n);

    for(int i=0;i<n;i++){
        cheb[i] = 1/((lmax+lmin)/2+(lmax-lmin)/2*cos(3.14159265*(2*i-1)/(2*n+2)));
    }

    return cheb;
}

std::vector<double> MPI_cheb(CSR<double> matrix, std::vector<double> b, int n_pol, double lmax, double lmin, double tolerance){
    int n = b.size();
    std::vector<double> res(n,0);
    std::vector<double> dif(n);

    std::vector<double> tau = calc_cheb_pol(lmax, lmin, n_pol);

    do{
        for(int i = 0;i<n_pol; ++i){
            dif = (matrix*res-b);
            res = res-dif*tau[i];
        }
    //std::cout<<res[0]<<" "<<res[3]<<std::endl;
	std::cout<<norm(dif)<<std::endl;
    
    }while(norm(dif) > tolerance);

    return res;
}