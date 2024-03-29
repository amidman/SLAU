#pragma once

#include<vector>
#include"CSR.h"
#include"operators.h"
#include<iostream>

std::vector<double> Gradient_descent_fast(CSR<double> matrix, std::vector<double> b, double tolerance){
    int n = b.size();
    std::vector<double> res(n,0);
    std::vector<double> dif(n);

    do{
        dif = (matrix*res-b);

        double tau = 0;
        for(int i =0;i<n;++i){
            tau+=dif[i]*dif[i];
        }
        std::vector<double> Ar = matrix*dif;
        double rtAr = 0;
        for(int i =0;i<n;++i){
            rtAr+=Ar[i]*dif[i];
        }

        tau = tau/rtAr;

        res = res-dif*tau;

    std::cout<<res[0]<<" "<<res[3]<<std::endl;
    }while(norm(dif) > tolerance);

    return res;
}

std::vector<double> Heavy_ball(CSR<double> matrix, std::vector<double> b, double tau, double tolerance, double alpha){
    int n = b.size();
    std::vector<double> res(n,0);
    std::vector<double> res_p(n,0);
    std::vector<double> res_pp(n,0);
    std::vector<double> dif(n);

    do{
        dif = (matrix*res-b);
        res = res_p-(res_p-res_pp)*alpha-dif*tau;

        res_p = res;
        res_pp = res_p;
    //std::cout<<res[0]<<" "<<res[3]<<std::endl;
	//std::cout<<norm(matrix*res-b)<<std::endl;
    
    }while(norm(dif) > tolerance);

    return res;
}